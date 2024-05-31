//
// Created by pawel on 31.05.2024.
//

#include "Ball.h"
Ball::Ball(float x, float y) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
}
void Ball::update(){
    shape.move(velocity);

    if (left() < 0)
        velocity.x = 8.f;
    else if (right() > windowWidth)
        velocity.x = -8.f;

    if (top() < 0)
        velocity.y = 8.f;
    else if (bottom() > windowHeight)
        velocity.y = -8.f;
}
float Ball::left() {
    return shape.getPosition().x;
}
float Ball::right() {
    return shape.getPosition().x + shape.getRadius() * 2;
}
float Ball::top() {
    return shape.getPosition().y;
}
float Ball::bottom() {
    return shape.getPosition().y + shape.getRadius() * 2;
}