//
// Created by pawel on 06.06.2024.
//
#ifndef BRICK_BREAKER_GAMEENGINE_H
#define BRICK_BREAKER_GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Brick.h"
#include "Ball.h"
#include "GameState.h"
#include "bin/ScoreTracker.h"

class GameEngine {
public:
    static void processEvents(sf::RenderWindow& window, std::vector<Brick>& bricks, bool& ballIsActive);
    static void render(sf::RenderWindow& window, sf::Sprite& backgroundSprite, Paddle& paddle, Ball& ball, sf::Sprite& pauseButtonSprite, std::vector<Brick>& bricks, sf::RectangleShape& redBar);
    template <class T1, class T2>
            static bool isIntersecting(T1& mA, T2& mB);
    static void testCollision(Paddle& paddle, Ball& ball, std::vector<Brick>& bricks);


    static void testCollisionPaddleBall(Paddle &paddle, Ball &ball);

    static void testCollisionBrickBall(Brick &brick, Ball &ball);

private:
    sf::Clock mClock;
    bool mBallIsActive;

    static void removeDestroyedBricks(std::vector<Brick> &bricks);

    void adjustBallVelocityAfterBrickCollision(Ball &ball, Brick &brick);

    static void handleBallBrickCollisions(Ball &ball, std::vector<Brick> &bricks);

    static void handlePaddleBallCollision(Paddle &paddle, Ball &ball);

};

#endif //BRICK_BREAKER_GAMEENGINE_H
