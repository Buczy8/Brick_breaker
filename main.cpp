

#include <iostream>
#include "Game.h"
int main() {

    //Game game;
    //game.run();
    //testowaniedll
    Brick brick(0, 0);
    std::cout << brick.left() << std::endl;
    std::cout << brick.right() << std::endl;
    std::cout << brick.bottom() << std::endl;
    std::cout << brick.top() << std::endl;
    std::cout << brick.isDestroyed() << std::endl;
    brick.setDestroyed(true);
    std::cout << brick.isDestroyed() << std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Brick Breaker");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        brick.draw(window); // Użycie metody draw
        window.display();
    }
    return 0;
}
