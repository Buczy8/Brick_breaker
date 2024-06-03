//
// Created by pawel on 31.05.2024.
//

#include "Ball.h"
Ball::Ball(float x, float y) {
    if (!mBallTexture.loadFromFile("assets/ball.png")) {
        throw "Could not load ball.png";
    }
    shape.setTexture(mBallTexture);
    shape.setPosition(x, y);
    if(!mBallHitPaddleSound.openFromFile("assets/sounds/ballhitpaddle.mp3")){
        throw "Could not load ballhitpaddle.wav";
    }
    if(!mBallHitBrickSound.openFromFile("assets/sounds/ballhitbrick.wav")){
        throw "Could not load ballhitbrick.wav";
    }
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
    return shape.getPosition().x + shape.getGlobalBounds().width;
}
float Ball::top() {
    return shape.getPosition().y;
}
float Ball::bottom() {
    return shape.getPosition().y + shape.getGlobalBounds().height;
}
void Ball::playHitPaddleSound(){
    mBallHitPaddleSound.play();
}
void Ball::playHitBrickSound(){
    mBallHitBrickSound.play();
}
void Ball::reset(){
    shape.setPosition(windowWidth / 2, windowHeight / 2);
    velocity = {8.f, 8.f};
}
