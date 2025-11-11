#pragma once

// Window size constants
constexpr unsigned int WINDOW_WIDTH = {800};
constexpr unsigned int WINDOW_HEIGHT = {600};

// Rectangle size constants
constexpr float RECTANGLE_LENGTH = {10.0f};
constexpr float RECTANLGE_WIDTH = {10.0f};

constexpr int OUT_OF_BOUNDS = {0};

constexpr int FRAME_RATE = {60};

// Coordinate struct to help spawn things
struct Coordinates {
    float xPos;
    float yPos;
};

// Helper function to generate a random spawn within the window
void generateSpawnPoint(Coordinates& spawnPoint);

// Enum to indicate direction snake is moving
enum Direction {
    UP,    // Default value is 0
    DOWN,  // Default value is 1
    LEFT,  // Default value is 2
    RIGHT, // Default value is 3
};
