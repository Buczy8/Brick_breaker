#define COMPONETS_EXPORTS

#ifdef COMPONETS_EXPORTS
#define COMPONETS_API __declspec(dllexport)
#else
#define COMPONETS_API __declspec(dllimport)
#endif
#ifndef BRICK_BREAKER_BRICK_H
#define BRICK_BREAKER_BRICK_H
#include <SFML/Graphics.hpp>
#include <cstdlib>
class  Brick {
public:
    Brick(float mX, float mY);
    float left();
    float right();
    float top();
    float bottom();
    friend class Game;
private:
    sf::RectangleShape shape;
    bool destroyed{false};
    std::vector<sf::Color> colors{sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan, sf::Color::Black, sf::Color::White};
};


#endif //BRICK_BREAKER_BRICK_H
