#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Flock.h"
#include "Engine.h"
#include "Constants.h"
#include "Point.h"


Engine::Engine() {

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this -> window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, desktop.bitsPerPixel), 
                          "Boids Simulation", sf::Style::Default);
    this -> flock = Flock(NUM_BOIDS, WINDOW_WIDTH, WINDOW_HEIGHT);
    this -> window.setFramerateLimit(60);
}

void Engine::run() {

    sf::CircleShape shape;

    for (int i = 0 ; i < this -> flock.num_boids ; i++) {
        shape = sf::CircleShape(8, 3);
        shape.setFillColor(sf::Color::White);
        shape.setRadius(5.0);
        this -> shapes.push_back(shape);
    }

    while (window.isOpen()) {
        this -> handle_input();
        this -> render();
    }
}

void Engine::handle_input() {

    sf::Event event;
    sf::Vector2i mouse_coords;

    while (this -> window.pollEvent(event)) {
        if ((event.type == sf::Event::Closed) || 
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            this -> window.close();
        }
    }
    mouse_coords = sf::Mouse::getPosition(this -> window);
    Point goal = Point(mouse_coords.x, mouse_coords.y);
    this -> flock.tick(goal);
}

void Engine::render() {

    this -> window.clear(sf::Color::Black);

    for (int i = 0 ; i < this -> flock.num_boids ; i++) {
        this -> shapes[i].setPosition(this -> flock.boids[i].pos.x, 
                                      this -> flock.boids[i].pos.y);
        this -> shapes[i].setRotation(this -> flock.boids[i].vel.angle());
        this -> window.draw(this -> shapes[i]);
    }
    
    this -> window.display();
}
