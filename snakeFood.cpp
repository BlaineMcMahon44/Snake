#include "snakeFood.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>

SnakeFood::SnakeFood()
{
    spawnEntity(food, false);
}

sf::RectangleShape SnakeFood::getFood() const
{
    return food;
}