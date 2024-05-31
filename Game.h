//
// Created by pawel on 31.05.2024.
//

#ifndef BRICK_BREAKER_GAME_H
#define BRICK_BREAKER_GAME_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "Brick.h"
#include "Ball.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void testCollision();
    template <class T1, class T2> bool isIntersecting(T1& mA, T2& mB);

private:
    sf::RenderWindow mWindow;
    sf::Clock mClock;
    Paddle mPaddle;
    Ball mBall;
    std::vector<Brick> mBricks;
};


#endif //BRICK_BREAKER_GAME_H
