//
// Created by pawel on 31.05.2024.
//

#include "Brick.h"
Brick::Brick(float x, float y) {
    shape.setSize({ 60.f, 20.f });
    shape.setFillColor(colors[rand() % colors.size()]);
    shape.setPosition(x, y);
}
float Brick::left() {
    return shape.getPosition().x;
}
float Brick::right() {
    return shape.getPosition().x + shape.getSize().x;
}
float Brick::top() {
    return shape.getPosition().y;
}
float Brick::bottom() {
    return shape.getPosition().y + shape.getSize().y;
}
