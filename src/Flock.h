#include <vector>
#include "Boid.h"
#include "Point.h"

#ifndef FLOCK_H_
#define FLOCK_H_

class Flock {

public:
    int num_boids;
    std::vector<Boid> boids;

    Flock();
    Flock(int num_boids, int xlim, int ylim);
    void tick(Point& goal);
};
#endif
