//
// Created by pawel on 31.05.2024.
//
const int windowWidth = 900;
const int windowHeight = 900;

#ifndef BRICK_BREAKER_PADDLE_H
#define BRICK_BREAKER_PADDLE_H
#include <SFML/Graphics.hpp>


class Paddle
{
private:
    sf::Texture mPaddleTexture;
    sf::Vector2f velocity;
    sf::Sprite mPaddleSprite;
public:
    Paddle(float x, float y);
    void update();
    float left();
    float right();
    float top();
    float bottom();
    void draw(sf::RenderWindow& window);
    void reset();
    friend class Game;
};

#endif //BRICK_BREAKER_PADDLE_H
