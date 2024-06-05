//
// Created by pawel on 31.05.2024.
//

#ifndef BRICK_BREAKER_GAME_H
#define BRICK_BREAKER_GAME_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "Brick.h"
#include "Ball.h"
#include "GameState.h"

class Game {
public:
    Game();
    void run();
    friend class StateMachine;
    
private:
    void processEvents();
    void update();
    void render();
    void testCollision();
    void loadMenu();
    template <class T1, class T2> bool isIntersecting(T1& mA, T2& mB);


private:
    sf::RenderWindow mWindow;

    sf::Clock mClock;

    Paddle mPaddle;

    Ball mBall;
    bool mBallIsActive;

    std::vector<Brick> mBricks;

    sf::Texture mBackgroundTexture;
    sf::Sprite mBackgroundSprite;

    sf::RectangleShape mRedBar;

    GameState m_state;

    sf::Sprite m_mainMenuSprite;
    sf::Texture m_mainMenuTexture;

    sf::Sprite m_buttonSprite;
    sf::Texture m_buttonTexture;

    sf::Texture mPauseButtonTexture;
    sf::Sprite mPauseButtonSprite;

    sf::Texture mPlayButtonTexture;
    sf::Sprite mPlayButtonSprite;

    sf::Texture mGameOverTexture;
    sf::Sprite mGameOverSprite;

    sf::Texture mPlayAgainButtonTexture;
    sf::Sprite mPlayAgainButtonSprite;

    sf::Texture mExitButtonTexture;
    sf::Sprite mExitButtonSprite;

    sf::Texture mWinTexture;
    sf::Sprite mWinSprite;

    sf::Music mBackgroundMusic;
    sf::Music mGameOverSound;
    sf::Music mWinSound;

};


#endif //BRICK_BREAKER_GAME_H
