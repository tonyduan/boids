#include <random>
#include "Boid.h"
#include "Flock.h"


Flock::Flock() {}

Flock::Flock(int num_boids, int xlim, int ylim) {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> x_dist(0, xlim);
    std::uniform_real_distribution<float> y_dist(0, ylim);
    this -> num_boids = num_boids;

    for (int i = 0; i < num_boids; i++) {
        Boid boid = Boid(i, x_dist(mt), y_dist(mt));
        this -> boids.push_back(boid);
    }
}

void Flock::tick(Point& goal) {

    for (Boid& boid : this -> boids) {
        boid.accelerate(this -> boids, goal);
    }
    
    for (Boid& boid : this -> boids) { 
        boid.tick();
    }
}
