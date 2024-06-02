//
// Created by pawel on 31.05.2024.
//

#ifndef BRICK_BREAKER_BALL_H
#define BRICK_BREAKER_BALL_H
#include "export.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
class BRICK_BREAKER_API Ball {
public:
    Ball(float x, float y);
    void update();
    float left();
    float right();
    float top();
    float bottom();
    sf::Sprite shape;
    void playHitPaddleSound();
    void playHitBrickSound();
    friend class Game;
private:
    sf::Vector2f velocity{ 0.3f, -0.3f };
    sf::Texture mBallTexture;
    sf::Music mBallHitPaddleSound;
    sf::Music mBallHitBrickSound;
};


#endif //BRICK_BREAKER_BALL_H
