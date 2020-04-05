#include <cmath>
#include <vector>
#include "Boid.h"
#include "Point.h"
#include "Constants.h"


Boid::Boid(int id, float x, float y) {

    this -> id = id;
    this -> pos = Point(x, y); 
    this -> vel = Point(0.0, 0.0);
    this -> acc = Point(0.0, 0.0);
}

void Boid::accelerate(std::vector<Boid>& boids, Point& goal) {

    Point rel_pos = Point();
    Point rel_vel = Point();
    Point repulsion = Point();
    int rel_vel_counter = 0;
    int rel_pos_counter = 0;

    for (Boid& other: boids) {
        if (other.id == this -> id) {
            continue;
        }
        Point diff = other.pos - this -> pos;
        repulsion -= diff * exp(-diff.length());
        if (diff.length() < REL_VEL_DISTANCE) {
            rel_vel += other.vel;
            rel_vel_counter += 1;
        }
        if (diff.length() < REL_POS_DISTANCE) {
            rel_pos += other.pos;
            rel_pos_counter += 1;
        }
    }

    rel_pos = rel_pos_counter > 0 ? rel_pos / rel_pos_counter : rel_pos;
    rel_vel = rel_vel_counter > 0 ? rel_vel / rel_vel_counter : rel_vel;
    
    this -> acc += (goal - this -> pos) * GOAL_SCALE;
    this -> acc += (rel_pos - this -> pos) * REL_POS_SCALE;
    this -> acc += (rel_vel - this -> vel) * REL_VEL_SCALE;
    this -> acc += repulsion;
    this -> acc *= ACCELERATION_SCALE;
}

void Boid::tick() {

    this -> vel += this -> acc;
    this -> limit_velocity();
    this -> pos += this -> vel;
    this -> acc.x = 0.0;
    this -> acc.y = 0.0;
}

void Boid::limit_velocity() { 

    if (this -> vel.length() > MAX_VELOCITY) {
        this -> vel /= this -> vel.length();
        this -> vel *= MAX_VELOCITY;
    }
}
