#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(windowWidth, windowHeight), "Brick Breaker"),
               mPaddle(windowWidth / 2 - 60, windowHeight - 50),
               mBall(windowWidth / 2, windowHeight / 2) {
    mWindow.setFramerateLimit(60);

    for (int iX = 0; iX < 11; ++iX) {
        for (int iY = 0; iY < 4; ++iY) {
            mBricks.emplace_back((iX + 1) * 64, (iY + 2) * 32);
        }
    }
}

void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update() {
    sf::Time deltaTime = mClock.restart();

    mBall.update();
    mPaddle.update();
    testCollision();
}

void Game::render() {
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mPaddle.shape);
    mWindow.draw(mBall.shape);
    for (auto& brick : mBricks) {
        mWindow.draw(brick.shape);
    }
    mWindow.display();
}
template <class T1, class T2>
bool Game::isIntersecting(T1& mA, T2& mB) {
    return mA.right() >= mB.left() && mA.left() <= mB.right() &&
           mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void Game::testCollision() {
    if (isIntersecting(mPaddle, mBall)) {
        mBall.velocity.y = -mBall.velocity.y;
        if (mBall.shape.getPosition().x < mPaddle.shape.getPosition().x)
            mBall.velocity.x = -8.f;
        else
            mBall.velocity.x = 8.f;
    }

    for (auto& brick : mBricks) {
        if (!brick.destroyed && isIntersecting(brick, mBall)) {
            brick.destroyed = true;
            mBall.velocity.y = -mBall.velocity.y;
        }
    }

    mBricks.erase(std::remove_if(mBricks.begin(), mBricks.end(), [](const Brick& mBrick) {
        return mBrick.destroyed;
    }), mBricks.end());
}
