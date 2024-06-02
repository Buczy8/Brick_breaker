#define COMPONETS_EXPORTS

#ifdef COMPONETS_EXPORTS
#define COMPONETS_API __declspec(dllexport)
#else
#define COMPONETS_API __declspec(dllimport)
#endif

#ifndef BRICK_BREAKER_BALL_H
#define BRICK_BREAKER_BALL_H
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include <SFML/Audio.hpp>
class  Ball {
public:
    Ball(float x, float y);
    void update();
    float left();
    float right();
    float top();
    float bottom();
    void BallHitPaddleSoundplay();
    void BallHitBrickSoundplay();
    sf::Sprite shape;

    friend class Game;
private:
    sf::Vector2f velocity{ 0.3f, -0.3f };
    sf::Texture mBallTexture;

    sf::Music mBallHitPaddleSound;
    sf::Music mBallHitBrickSound;
};


#endif //BRICK_BREAKER_BALL_H
