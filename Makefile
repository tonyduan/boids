

CC = g++
CFLAGS = -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) $(CFLAGS) src/*.cpp -o out/boids $(SFML)

run:
	./out/boids

