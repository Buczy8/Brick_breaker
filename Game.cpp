#include "Game.h"
#include <iostream>
Game::Game() : mWindow(sf::VideoMode(windowWidth, windowHeight), "Brick Breaker"),
                mPaddle(windowWidth / 2 - 60, windowHeight - 50),
               mBall(windowWidth / 2, windowHeight / 2), m_state(Loading){

    if (!mBackgroundTexture.loadFromFile("assets/bg.png")) {
        throw std::runtime_error("Could not load background image.");
    }
    mBackgroundSprite.setTexture(mBackgroundTexture);

    mRedBar.setSize(sf::Vector2f(windowWidth, 10)); // Ustaw rozmiar czerwonego paska
    mRedBar.setFillColor(sf::Color::Red); // Ustaw kolor czerwonego paska
    mRedBar.setPosition(0, windowHeight - 10);

    if (!mPauseButtonTexture.loadFromFile("assets/pausebutton.png")) {
        throw std::runtime_error("Could not load pause button image.");
    }

    mPauseButtonSprite.setTexture(mPauseButtonTexture);
    mPauseButtonSprite.setPosition(windowWidth - 70, 10);


    if (!mGameOverTexture.loadFromFile("assets/gameover.jpg")) {
        throw std::runtime_error("Could not load game over image.");
    }
    mGameOverSprite.setTexture(mGameOverTexture);
    mGameOverSprite.setPosition(windowWidth / 2 - mGameOverSprite.getGlobalBounds().width / 2, windowHeight / 2 - 150);

    if (!mPlayAgainButtonTexture.loadFromFile("assets/playbutton.png")) {
        throw std::runtime_error("Could not load play button image.");
    }
    mPlayAgainButtonSprite.setTexture(mPlayAgainButtonTexture);
    mPlayAgainButtonSprite.setPosition(windowWidth / 2 - 96 - 35 , windowHeight / 2 + 50);

    if (!mExitButtonTexture.loadFromFile("assets/exitbutton.png")) {
        throw std::runtime_error("Could not load exit button image.");
    }
    mExitButtonSprite.setTexture(mExitButtonTexture);
    mExitButtonSprite.setPosition(windowWidth / 2 + 35, windowHeight / 2 + 50);

    if (!mWinTexture.loadFromFile("assets/win.jpg")) {
        throw std::runtime_error("Could not load win image.");
    }
    mWinSprite.setTexture(mWinTexture);
    mWinSprite.setPosition(windowWidth / 2 - mWinSprite.getGlobalBounds().width / 2, windowHeight / 2 - 350);

    if (!mPlayButtonTexture.loadFromFile("assets/play.png")) {
        throw std::runtime_error("Could not load play button image.");
    }
    mPlayButtonSprite.setTexture(mPlayButtonTexture);
    mPlayButtonSprite.setPosition(windowWidth / 2 - 50, windowHeight / 2 - 50);
}

void Game::loadMenu() {
    if (!m_mainMenuTexture.loadFromFile("assets/menubg.jpg")) {
        throw std::runtime_error("Could not load menu image.");
    }
    m_mainMenuSprite.setTexture(m_mainMenuTexture);
    if (!m_buttonTexture.loadFromFile("assets/menubutton.png")) {
        throw std::runtime_error("Could not load button image.");
    }
    m_buttonSprite.setTexture(m_buttonTexture);
    m_buttonSprite.setPosition(365, 550);



    m_state = MainMenu;
}
void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();
        switch (m_state) {
            case Loading:
                loadMenu();
                std::cout << "Loading" << std::endl;
                break;
            case MainMenu:
                mWindow.clear(sf::Color::Black);
                mWindow.draw(m_mainMenuSprite);
                mWindow.draw(m_buttonSprite);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2f pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
                    if (m_buttonSprite.getGlobalBounds().contains(pos)) {
                        m_state = LevelLoading;
                    }
                }
                break;
            case LevelLoading:
                mBricks.clear();
                for (int iX = 0; iX < 12; ++iX) {
                    for (int iY = 0; iY < 10; ++iY) {
                        mBricks.emplace_back((iX + 1) * 64, (iY + 2) * 32);
                    }
                }
                render();
                m_state = Playing;
                break;
            case Playing:
                update();
                render();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    m_state = Pause; // Zmień stan gry na Pause, jeśli przycisk spacji został naciśnięty
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2f pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
                    if (mPauseButtonSprite.getGlobalBounds().contains(pos)) {
                        m_state = Pause; // Zmień stan gry na Pause, jeśli przycisk pauzy został naciśnięty
                    }
                }
                break;
            case Pause:
                mWindow.draw(mBackgroundSprite);
                mWindow.draw(mPlayButtonSprite);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2f pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
                    if (mPlayButtonSprite.getGlobalBounds().contains(pos)) {
                        m_state = Playing; // Zmień stan gry na Playing, jeśli przycisk play został naciśnięty
                    }
                }
                break;
            case GameOver:
                mWindow.clear(sf::Color::Black);
                mWindow.draw(mGameOverSprite);
                mWindow.draw(mPlayAgainButtonSprite);
                mWindow.draw(mExitButtonSprite);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2f pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
                    if (mPlayAgainButtonSprite.getGlobalBounds().contains(pos)) {
                        m_state = LevelLoading; // Zmień stan gry na LevelLoading, jeśli przycisk play został naciśnięty
                    }
                    if (mExitButtonSprite.getGlobalBounds().contains(pos)) {
                        mWindow.close(); // Zamknij okno, jeśli przycisk exit został naciśnięty
                    }
                }
                break;
            case Win:
                mWindow.clear(sf::Color::Black);
                mWindow.draw(mWinSprite);
                mWindow.draw(mPlayAgainButtonSprite);
                mWindow.draw(mExitButtonSprite);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2f pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
                    if (mPlayAgainButtonSprite.getGlobalBounds().contains(pos)) {
                        m_state = LevelLoading; // Zmień stan gry na LevelLoading, jeśli przycisk play został naciśnięty
                    }
                    if (mExitButtonSprite.getGlobalBounds().contains(pos)) {
                        mWindow.close(); // Zamknij okno, jeśli przycisk exit został naciśnięty
                    }
                }
                break;
        }
        mWindow.display();
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
    if (mBall.bottom() > windowHeight) {
        m_state = GameOver;

    }
    if (mBricks.empty()) {
        m_state = Win;
    }
}

void Game::render() {
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mBackgroundSprite);
    mWindow.draw(mPaddle.mPaddleSprite);
    mWindow.draw(mBall.shape);
    mWindow.draw(mPauseButtonSprite);
    for (auto& brick : mBricks) {
        if (!brick.destroyed) {
            mWindow.draw(brick.shape);
        }
    }
    mWindow.draw(mRedBar);
    //mWindow.display();
}
template <class T1, class T2>
bool Game::isIntersecting(T1& mA, T2& mB) {
    return mA.right() >= mB.left() && mA.left() <= mB.right() &&
           mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void Game::testCollision() {
    if (isIntersecting(mPaddle, mBall)) {
        mBall.shape.setPosition(mBall.shape.getPosition().x, mPaddle.mPaddleSprite.getPosition().y - mBall.shape.getGlobalBounds().height);
        float difference = mBall.shape.getPosition().x - mPaddle.mPaddleSprite.getPosition().x;
        float percentageDifference = difference / (mPaddle.mPaddleSprite.getGlobalBounds().width / 2);
        mBall.velocity.x = percentageDifference * 0.3f;
        mBall.velocity.y = -mBall.velocity.y;

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
