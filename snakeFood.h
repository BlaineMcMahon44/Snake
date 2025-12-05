#pragma once
#include "utils.h"
#include "linkedList.h"
#include <SFML/Graphics.hpp>

/**
 * @class SnakeFood
 * @brief SnakeFood class which will be used to increase the size of the snake
 *
 * Example usage:
 *    Snake snake; will spawn a snake randomly within the window
 *    snake.moveSnake(sf::Vector2f); will move the snake from the current position 
 *  
 */
class SnakeFood
{
private:
    sf::RectangleShape food {{FOOD_HEIGHT, FOOT_WIDTH}};
public:
    SnakeFood();
    sf::RectangleShape getFood() const;
};