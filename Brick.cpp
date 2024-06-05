#include "Brick.h"
#include <iostream>

sf::Texture Brick::texture;

void Brick::loadTexture(const std::string& textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error loading texture from file: " << textureFile << std::endl;
        // Handle error appropriately
    }
}

Brick::Brick(float x, float y) {
    shape.setSize({ 60.f, 20.f });
    shape.setTexture(&texture);
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

bool Brick::isDestroyed() {
    return destroyed;
}

sf::RectangleShape Brick::getShape() {
    return shape;
}

void Brick::setDestroyed(bool mDestroyed) {
    destroyed = mDestroyed;
}

void Brick::draw(sf::RenderWindow& window) {
    if (!destroyed) {
        window.draw(shape);
    }
}
