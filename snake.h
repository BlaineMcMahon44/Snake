#pragma once
#include "utils.h"
#include <vector>
#include <SFML/Graphics.hpp>

/**
 * @class Snake
 * @brief Snake class which holds contains a vector of sf::RectangleShape objs
 * used to represent the snake head and body
 *
 * Example usage:
 *    Snake snake; will spawn a snake randomly within the window
 *    snake.moveSnake(sf::Vector2f); will move the snake from the current position 
 *  
 */
class Snake {
public:
    /**
    * @brief Constructs spawns snake randomly in-bounds
    * @throws std::runtime_error if spawning fails
    */
    Snake();

    /**
     * @brief Moves the snake by offset from current position
     * @param position sf::Vector2f consists of x and y float values.
     */
    void changeDirection(Direction direction);

    /**
     * @brief Returns a reference to the head of the snake.
     */
    const std::vector<sf::RectangleShape>& getSnake();

private:
    /**
     * @brief Creates a vector to hold snake shapes (sf::RectangleShape)
     */
    std::vector<sf::RectangleShape> snakeBody {};

    /**
     * @brief Direction that the snake is moving
     */
    Direction moveDirection = {Direction::LEFT};
    
    /**
     * @brief Speed the snake is moving
     */
    sf::Vector2f velocity {-1.1, 0.0};

    /**
     * @brief Checks if the snake is within the window
     * @param xPos float that denotes the x cooridnate of snake
     * @param yPos float that denotes the y cooridnate of snake
     */
    bool checkBounds(float xPos, float yPos);

    /**
     * @brief Randomly create xPos and yPos within window for snake spawn
     * @param snakeHead takes a reference to the snake head
     */
    bool spawnSnake(sf::RectangleShape& snakeHead);

    /**
     * @brief Offset snake from current position
     */
    void setVelocity();

};
