//
// Created by pawel on 31.05.2024.
//

const int windowWidth = 800;
const int windowHeight = 600;
#ifndef BRICK_BREAKER_PADDLE_H
#define BRICK_BREAKER_PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle
{
private:
    sf::Vector2f velocity;
public:
    Paddle(float x, float y);
    void update();
    float left();
    float right();
    float top();
    float bottom();

    sf::RectangleShape shape;
};

#endif //BRICK_BREAKER_PADDLE_H
