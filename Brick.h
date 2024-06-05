#ifndef BRICK_BREAKER_BRICK_H
#define BRICK_BREAKER_BRICK_H

#include <SFML/Graphics.hpp>
#include <cstdlib>

class Brick {
public:
    Brick(float mX, float mY);
    static void loadTexture(const std::string& textureFile);
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
    static sf::Texture texture;
    bool destroyed{false};
};

#endif //BRICK_BREAKER_BRICK_H
