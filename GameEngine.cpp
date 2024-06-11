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

        // Przesuwa piłkę nad paletkę
        ball.getBallShape().setPosition(ball.getBallShape().getPosition().x, paddle.getPaddleSprite().getPosition().y - ball.getBallShape().getGlobalBounds().height);

        // Wylicza prędkość na podstawie punktu kolizji
        float difference = ball.getBallShape().getPosition().x - paddle.getPaddleSprite().getPosition().x;
        float percentageDifference = difference / (paddle.getPaddleSprite().getGlobalBounds().width / 2);
        ball.setVelocity({ 8.f * percentageDifference, -8.f });

        // Sprawdza czy piłka nie koliduje z paletką
        if (ball.getVelocity().y > 0) {
            ball.setVelocity({ ball.getVelocity().x, -ball.getVelocity().y });
        }
    }
}

void GameEngine::testCollisionBrickBall(Brick& brick, Ball& ball) {
    if (!brick.isDestroyed() && isIntersecting(brick, ball)) {
        ScoreTracker::brickDestroyed();
        ball.playHitBrickSound();
        brick.setDestroyed(true);

        // Oblicza nakładania się piłki na cegłę w czterech kierunkach
        float overlapLeft = ball.right() - brick.left();
        float overlapRight = brick.right() - ball.left();
        float overlapTop = ball.bottom() - brick.top();
        float overlapBottom = brick.bottom() - ball.top();

        // Określa z której strony piłka uderzyła cegłę
        bool ballFromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
        bool ballFromTop = std::abs(overlapTop) < std::abs(overlapBottom);

        // Wyznacza minimalne nakładanie się w osi X i Y
        float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
        float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

        // Sprawdza, czy minimalne nakładanie się jest w osi X czy Y
        if (std::abs(minOverlapX) < std::abs(minOverlapY)) {
            // Jeśli minimalne nakładanie się jest w osi X, odwraca prędkość w osi X
            ball.setVelocity({ -ball.getVelocity().x, ball.getVelocity().y });
        } else {
            // Jeśli minimalne nakładanie się jest w osi Y, odwraca prędkość w osi Y
            ball.setVelocity({ ball.getVelocity().x, -ball.getVelocity().y });
        }
    }
}


void GameEngine::testCollision(Paddle& paddle, Ball& ball, std::vector<Brick>& bricks) {
    testCollisionPaddleBall(paddle, ball);
    for (auto& brick : bricks) {
        testCollisionBrickBall(brick, ball);
    }
    bricks.erase(std::remove_if(bricks.begin(), bricks.end(), [](Brick& mBrick) {
        return mBrick.isDestroyed();
    }), bricks.end());
}
