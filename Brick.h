//
// Created by pawel on 31.05.2024.
//

#ifndef BRICK_BREAKER_BRICK_H
#define BRICK_BREAKER_BRICK_H
#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float mX, float mY);

    sf::RectangleShape shape;
    bool destroyed{false};
    float left();
    float right();
    float top();
    float bottom();

};


#endif //BRICK_BREAKER_BRICK_H
