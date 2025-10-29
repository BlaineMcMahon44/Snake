#pragma once
#include "utils.h"
#include <vector>
#include <SFML/Graphics.hpp>

// Will hold the snake which is composed of sf::RectangleShape objects 
class Snake {
    private:
        std::vector<sf::RectangleShape> snakeBody {};
        bool checkBounds(float xPos, float yPos);
        bool spawnSnake(sf::RectangleShape& snakeHead);

    public:
        Snake();
        void moveSnake(sf::Vector2f position);
        const std::vector<sf::RectangleShape>& getSnake();
};