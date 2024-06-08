

#ifndef BRICK_BREAKER_BALL_H
#define BRICK_BREAKER_BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
class  Ball {
public:
    Ball(float x, float y);
    void update();
    float left();
    float right();
    float top();
    float bottom();
    void playHitPaddleSound();
    void playHitBrickSound();
    void reset();
    sf::Sprite getBallShape();
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f velocity);

private:
    sf::Vector2f velocity{ 8.f, -8.f };
    sf::Texture mBallTexture;
    sf::Music mBallHitPaddleSound;
    sf::Music mBallHitBrickSound;
    sf::Sprite shape;
};


#endif //BRICK_BREAKER_BALL_H
