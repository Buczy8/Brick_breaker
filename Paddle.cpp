//
// Created by pawel on 31.05.2024.
//

#include "Paddle.h"
Paddle::Paddle(float x, float y) {
    if (!mPaddleTexture.loadFromFile("assets/paddle.png")) {
        throw "Could not load paddle.png";
    }
    mPaddleSprite.setTexture(mPaddleTexture);
    mPaddleSprite.setPosition(x, y);
}
void Paddle:: update() {
    mPaddleSprite.move(velocity);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
        velocity.x = -9.f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < windowWidth)
        velocity.x = 9.f;
    else
        velocity.x = 0.f;
}

float Paddle::left(){
    return mPaddleSprite.getPosition().x;
}

float Paddle::right() {
    return mPaddleSprite.getPosition().x + mPaddleSprite.getGlobalBounds().width;
}

float Paddle::top() {
    return mPaddleSprite.getPosition().y;
}

float Paddle::bottom() {
    return mPaddleSprite.getPosition().y + mPaddleSprite.getGlobalBounds().height;
}
void Paddle::draw(sf::RenderWindow& window) {
    window.draw(mPaddleSprite);
}
void Paddle::reset() {
    mPaddleSprite.setPosition(windowWidth / 2, windowHeight - 50);
}
sf::Sprite Paddle::getPaddleSprite() {
    return mPaddleSprite;
}