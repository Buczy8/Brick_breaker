#pragma once
#ifdef _BUILD
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __declspec(dllimport)
#endif // _BUILD

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

class EXPORT_API  Brick {
public:
    Brick(float mX, float mY);
    float left();
    float right();
    float top();
    float bottom();
    bool isDestroyed();
    void setDestroyed(bool mDestroyed);
    sf::RectangleShape getShape();
    void draw(sf::RenderWindow& window);
private:
    sf::RectangleShape shape;
    bool destroyed{false};
    std::vector<sf::Color> colors{sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan, sf::Color::Black, sf::Color::White};
};
