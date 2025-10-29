#pragma once

constexpr int WINDOW_WIDTH = {800};
constexpr int WINDOW_HEIGHT = {600};

struct Coordinates {
    float xPos;
    float yPos;
};

void generateSpawnPoint(Coordinates& spawnPoint);

enum Direction {
    UP,    // Default value is 0
    DOWN,  // Default value is 1
    LEFT,  // Default value is 2
    RIGHT, // Default value is 3
};