#include <vector>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Flock.h"

#ifndef ENGINE_H_
#define ENGINE_H_

class Engine {

private:
    sf::RenderWindow window;

    Flock flock;
    std::vector<sf::CircleShape> shapes;

    void handle_input();
    void render();

public:
    Engine();
    void run();
};
#endif

