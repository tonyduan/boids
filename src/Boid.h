#include <vector>
#include "Point.h"

#ifndef BOID_H_
#define BOID_H_

class Boid {
    
public:
    int id;
    Point pos;
    Point vel;
    Point acc;

    Boid(int id, float x, float y);

    void accelerate(std::vector<Boid>& boids, Point& goal);
    void tick();

private:
    void limit_velocity();
};
#endif

