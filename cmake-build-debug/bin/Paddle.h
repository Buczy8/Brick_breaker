#define COMPONETS_EXPORTS

#ifdef COMPONETS_EXPORTS
#define COMPONETS_API __declspec(dllexport)
#else
#define COMPONETS_API __declspec(dllimport)
#endif
const int windowWidth = 900;
const int windowHeight = 900;
#ifndef BRICK_BREAKER_PADDLE_H
#define BRICK_BREAKER_PADDLE_H
#include <SFML/Graphics.hpp>


class  Paddle
{
private:
    sf::Texture mPaddleTexture;
    sf::Vector2f velocity;
public:
    Paddle(float x, float y);
    void update();
    float left();
    float right();
    float top();
    float bottom();
    void draw(sf::RenderWindow& window);
    friend class Game;
private:
    sf::Sprite mPaddleSprite;
};

#endif //BRICK_BREAKER_PADDLE_H
