#include <iostream>
#include "Engine.h"
#include "Boid.h"
#include "Point.h"


int main() {

    std::printf("Hello, world!\n\n");

    std::printf("Notice here the pointers are exactly 28 bytes apart.\n");
    std::printf("This is the amount of contiguous heap space a boid takes.\n");
    Boid* array = new Boid[2] { Boid(43, 123, 456), Boid(42, 123, 456) };
    std::printf("%p\n", &array[0]);
    std::printf("%p\n\n", &array[1]);
    delete[] array;

    std::printf("Here notice allocation on the stack is descending memory space.\n");
    Boid boid1 = Boid(43, 123, 456);
    Boid boid2 = Boid(43, 123, 456);
    std::printf("%p\n", &boid1);
    std::printf("%p\n\n", &boid2);

    std::printf("Press escape to exit.\n");
    Engine engine;
    engine.run();
    return 0;
}


