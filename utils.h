#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

// Window size constants
constexpr unsigned int WINDOW_WIDTH = {1000};
constexpr unsigned int WINDOW_HEIGHT = {1000};

// Rectangle size constants
constexpr float RECTANGLE_HEIGHT = {50.0f};
constexpr float RECTANGLE_WIDTH = {50.0f};

constexpr float FOOD_HEIGHT = {20.0f};
constexpr float FOOT_WIDTH = {20.0f};

constexpr int OUT_OF_BOUNDS = {0};

constexpr int FRAME_RATE = {5};

// Coordinate struct to help spawn things
struct Coordinates {
    float xPos;
    float yPos;
    bool isSnake= {false};
};

// Helper functions to generate random spawn within the window
void generateSpawnPoint(Coordinates& spawnPoint);

// Enum to indicate direction snake is moving
enum Direction {
    UP,    // Default value is 0
    DOWN,  // Default value is 1
    LEFT,  // Default value is 2
    RIGHT, // Default value is 3
};

void spawnEntity(sf::RectangleShape& entity, const bool isSnake);

int generateRandomNumber(int min, int max);