#pragma once
#include "gameWindow.h"
#include <SFML/Graphics.hpp>

/**
 * @struct GameContext struct that keeps track of gameContext
 * @brief holds references to the game window and the direction of the snake
 */
struct GameContext {
    GameWindow& window;
    Direction& direction;
};
