//
// Created by pawel on 06.06.2024.
//

#include "GameEngine.h"
void GameEngine::processEvents(sf::RenderWindow& window, std::vector<Brick>& bricks, bool& ballIsActive) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            ScoreTracker::saveToFile("wynik.txt");
            window.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Delete)
            bricks.clear();
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
            ballIsActive = true;
    }
}

void GameEngine::render(sf::RenderWindow& window, sf::Sprite& backgroundSprite, Paddle& paddle, Ball& ball, sf::Sprite& pauseButtonSprite, std::vector<Brick>& bricks, sf::RectangleShape& redBar) {
    window.clear(sf::Color::Black);
    window.draw(backgroundSprite);
    paddle.draw(window);
    window.draw(ball.getBallShape());
    window.draw(pauseButtonSprite);
    for (auto& brick : bricks) {
        if (!brick.isDestroyed()) {
            brick.draw(window);
        }
    }
    window.draw(redBar);
}
template <class T1, class T2>
bool GameEngine::isIntersecting(T1& mA, T2& mB) {
    return !(mA.right() < mB.left() ||
             mA.left() > mB.right() ||
             mA.bottom() < mB.top() ||
             mA.top() > mB.bottom());
}

    void GameEngine::testCollisionPaddleBall(Paddle& paddle, Ball& ball) {
    if (isIntersecting(paddle, ball)) {
        ScoreTracker::ballBounced();
        ball.playHitPaddleSound();
        ball.getBallShape().setPosition(ball.getBallShape().getPosition().x, paddle.getPaddleSprite().getPosition().y - ball.getBallShape().getGlobalBounds().height);
        float difference = ball.getBallShape().getPosition().x - paddle.getPaddleSprite().getPosition().x;
        float percentageDifference = difference / (paddle.getPaddleSprite().getGlobalBounds().width / 2);
        ball.setVelocity({ 8.f * percentageDifference, -8.f });
    }
}

void GameEngine::testCollisionBrickBall(Brick& brick, Ball& ball) {
    if (!brick.isDestroyed() && isIntersecting(brick, ball)) {
        ScoreTracker::brickDestroyed();
        ball.playHitBrickSound();
        brick.setDestroyed(true);

        float overlapLeft{ ball.right() - brick.left() };
        float overlapRight{ brick.right() - ball.left() };
        float overlapTop{ ball.bottom() - brick.top() };
        float overlapBottom{ brick.bottom() - ball.top() };

        bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
        bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

        float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
        float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

        if (abs(minOverlapX) < abs(minOverlapY))
            ball.setVelocity({ ball.getVelocity().x, -ball.getVelocity().y });
        else
            ball.setVelocity({ -ball.getVelocity().x, ball.getVelocity().y });
    }
}

void GameEngine::testCollision(Paddle& paddle, Ball& ball, std::vector<Brick>& bricks) {
    testCollisionPaddleBall(paddle, ball);
    for (auto& brick : bricks) {
        testCollisionBrickBall(brick, ball);
    }
    bricks.erase(std::remove_if(bricks.begin(), bricks.end(), [](Brick mBrick) {
        return mBrick.isDestroyed();
    }), bricks.end());
}
