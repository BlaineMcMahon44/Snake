#include "snake.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

/**
 * @breif Snake constructor which creates a snakeHead from a sf::RectangleShape
 * Spawns the snake randomly within the window (sets the sf::Rectangle position)
 * Calls addTail to add the sf::RectangleShape to the linked list
 */
Snake::Snake()
{  
    sf::RectangleShape snakeHead {{RECTANGLE_HEIGHT, RECTANGLE_WIDTH}};
    spawnEntity(snakeHead, true);
    snakeBody->addTail(snakeHead);
}

/**
 * @brief Calls getSnakeHeadBounds to get the x and y pos of the snake's head
 * the x and y pos represent the top left corner of the snake heads rectangle
 *
 * @return - bool indicating if x and y pos are inbounds
 */
bool Snake::checkBounds() const
{
    const sf::FloatRect headBounds = getSnakeHeadBounds();

    if (headBounds.position.x <= OUT_OF_BOUNDS || (headBounds.position.x + RECTANGLE_WIDTH) >= WINDOW_WIDTH) return false;
    if (headBounds.position.y <= OUT_OF_BOUNDS || (headBounds.position.y + RECTANGLE_HEIGHT) >= WINDOW_HEIGHT) return false;

    return true;
}

/**
 * @brief Gets the direction from the GameContext which decides which direction the snake should move
 * First check if the snake is inbounds or not
 * Update snake position by calling moveTailToHead
 *
 * @param direction - Direction enum
 */
void Snake::changeDirection(const Direction direction)
{
    // Get the direction from the keyboard and set the velocity
    moveDirection = direction;
    setVelocity();

    if (checkBounds())
    {
        // Check bounds of graph
        //std::cout << "Snake is at position " << xPos << " " << yPos << "\n";
        std::cout << "" << "\n";
    }
    else
    {
        // **** NEED to implement what to do when snake is out of bounds 
        //
        // *****
        //std::cout << "Snake is out of bounds" << xPos << " " << yPos << "\n";
        std::cout << "OUT OF BOUNDS" << "\n";
    }

    // Adjust snake position by offset
    std::cout << "snake size is" << snakeBody->getSize() << "\n";
    if (snakeBody->getSize() >= 1)
    {
        snakeBody->moveTailToHead(velocity);
    }
}

/**
 * @breif Decide which way the snake moves and sets the speed it should move in that direction
 * Uses the RECTANGLE_WIDTH to move the block consistently
 */
void Snake::setVelocity()
{
    switch (moveDirection)
    {
        case UP:
            velocity = {0.0, -RECTANGLE_WIDTH};
            break;
        case DOWN:
            velocity = {0.0,  RECTANGLE_WIDTH};
            break;
        case LEFT:
            velocity = {-RECTANGLE_WIDTH, 0.0};
            break;
        case RIGHT:
            velocity = {RECTANGLE_WIDTH, 0.0};
            break;
        default:
            break;
    };
}

/**
 * Helper function to decide where the new block shoujld be positioned
 * Find the velocity of the current tail and sets it one block length behind the tail
 *
 * @return sf::Vector2f position of the new tail
 */
sf::Vector2f Snake::addBodyHelper()
{
    sf::Vector2f offset {};
    std::cout << "Velocity is " << velocity.x << " " << velocity.y << "\n";
    std::cout << "Move direction is " << moveDirection << "\n";

    // Want to get the offset which is opposite the direction the head is moving
    if (velocity.x != 0) velocity.x = -(velocity.x);
    if (velocity.y != 0) velocity.y = -(velocity.y);

    offset = {velocity.x, velocity.y};

    const sf::Vector2f tailPosition = {snakeBody->getTailCoordinateX(), snakeBody->getTailCoordinateY()};
    std::cout << "Offset is " << offset.x << " " << offset.y << "\n";
    std::cout << "Head position is " << tailPosition.x << " " << tailPosition.y << "\n";
    return tailPosition + offset;
}

/**
 * @breif Creates a new sf::RectangleShape and sets its position by calling addBodyHelper()
 * Then calls linked-list method addTail and passes in a reference to the new sf::RectangleShape
 */
void Snake::addBody()
{
    sf::RectangleShape snakeBodyPart {{RECTANGLE_HEIGHT, RECTANGLE_WIDTH}};
    snakeBodyPart.setPosition(addBodyHelper());
    snakeBody->addTail(snakeBodyPart);
}

/**
 * @brief Returns a reference to the snakes linked list
 *
 * @return - Reference to the snake's linked list
 */
LinkedList& Snake::getSnake() const
{
    if (!snakeBody)
        throw std::runtime_error("LinkedList::getHead() called on empty list");
    return *snakeBody;
}

/**
 * @brief Used to get the x and y pos of the snake head
 *
 * @return sf::FloatRect
 */
sf::FloatRect Snake::getSnakeHeadBounds() const
{
    return snakeBody->getHead()->data.getGlobalBounds();
}