//
// Created by pawel on 31.05.2024.
//

#ifndef BRICK_BREAKER_BALL_H
#define BRICK_BREAKER_BALL_H
#include <SFML/Graphics.hpp>
#include "Paddle.h"
class Ball {
public:
    Ball(float x, float y);
    void update();
    float left();
    float right();
    float top();
    float bottom();

    sf::Vector2f velocity{ 8.f, -8.f };
    sf::CircleShape shape;
};


#endif //BRICK_BREAKER_BALL_H