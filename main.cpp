

#include <iostream>
#include "Game.h"
int main() {

    Game game;
    game.run();

    //testowaniedll
    // Ustawienia okna
    /*
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    window.setFramerateLimit(60);
    Brick::loadTexture("assets/brick.png");
    std::vector<Brick> bricks;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            bricks.emplace_back(10 + i * (60 + 10), 10 + j * (20 + 10));
        }
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        for (auto& brick : bricks) {
            brick.draw(window);
        }
        window.display();
    }*/
}
