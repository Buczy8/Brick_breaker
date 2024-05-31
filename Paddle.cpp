//
// Created by pawel on 31.05.2024.
//

#include "Paddle.h"
Paddle::Paddle(float x, float y) {
    shape.setSize({ 120.f, 20.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
}
void Paddle:: update() {
    shape.move(velocity);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
        velocity.x = -10.f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < windowWidth)
        velocity.x = 10.f;
    else
        velocity.x = 0.f;
}

float Paddle::left(){
    return shape.getPosition().x;
}

float Paddle::right() {
    return shape.getPosition().x + shape.getSize().x;
}

float Paddle::top() {
    return shape.getPosition().y;
}

float Paddle::bottom() {
    return shape.getPosition().y + shape.getSize().y;
}
