#pragma once
#include "utils.h"
#include "linkedList.h"
#include <SFML/Graphics.hpp>

/**
 * @class Snake
 * @brief Snake class which holds contains a vector of sf::RectangleShape objs
 * used to represent the snake head and body
 *
 * Example usage:
c *    Snake snake; will spawn a snake randomly within the window
 *    snake.moveSnake(sf::Vector2f); will move the snake from the current position 
 *  
 */
class Snake {
    private:
    /**
     * @brief Creates a pointer to a doubly linked list to hold snake shapes (sf::RectangleShape)
     */
    std::unique_ptr<LinkedList> snakeBody = std::make_unique<LinkedList>();

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
    bool checkBounds() const;

    /**
     * @brief Offset snake from current position
     */
    void setVelocity();

    /**
    * @brief Helper to determine where to add the block to the snake
    */
    sf::Vector2f addBodyHelper();

    /**
     * @breif Get the bounds of the snake head
     *
     * @return sf::FloatRect contains x and y pos
     */
    sf::FloatRect getSnakeHeadBounds() const;

public:
    /**
    * @brief Constructs spawns snake randomly in-bounds
    * @throws std::runtime_error if spawning fails
    */
    Snake();

    /**
     * @brief Moves the snake by offset from current position
     * @param direction sf::Vector2f consists of x and y float values.
     */
    void changeDirection(Direction direction);

    /**
     * @brief Returns a reference to the head of the snake.
     */
    LinkedList& getSnake() const;

    /**
    * @brief Adds to the snake body
    */
    void addBody();

};
