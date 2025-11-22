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
    sf::RectangleShape snakeHead {{RECTANGLE_LENGTH, RECTANLGE_WIDTH}};

    if (!spawnSnake(snakeHead))
    {
        throw std::runtime_error("Error spawning snake");
    }
    snakeBody->addTail(snakeHead);
}

/**
 * @brief Attempts to set the snakeHead position within the window coordinates
 *
 * @param snakeHead - sf::RectangleShape reference
 *
 * @return - bool indicating if success or not setting position
 */
bool Snake::spawnSnake(sf::RectangleShape& snakeHead)
{
    try
    {
        Coordinates snakeSpawnCoordinates {};
        generateSpawnPoint(snakeSpawnCoordinates);
        std::cout << "Snake spawned at " << snakeSpawnCoordinates.xPos << " " << snakeSpawnCoordinates.yPos << "\n";
        snakeHead.setPosition({snakeSpawnCoordinates.xPos, snakeSpawnCoordinates.yPos});
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

/**
 * @brief Checks if the snake is inbounds or not
 *
 * @param xPos - float of x pos of snakeHead
 * @param yPos - float of y pos of snakeHead
 * @return - bool indicating if x and y pos are inbounds
 */
bool Snake::checkBounds(const float xPos, const float yPos)
{
    if ( (xPos >= static_cast<float>(WINDOW_WIDTH)) || (xPos <= OUT_OF_BOUNDS) ||
        (yPos >= static_cast<float>(WINDOW_HEIGHT)) || (yPos <= OUT_OF_BOUNDS ))
    {
        return false;
    }
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

    // Get coordinates to validate if snake is in bounds
    const float xPos = snakeBody->getHeadCoordinateX();
    const float yPos = snakeBody->getHeadCoordinateY();

    if (checkBounds(xPos, yPos))
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
        std::cout << "" << "\n";
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
            velocity = {0.0, -RECTANLGE_WIDTH};
            break;
        case DOWN:
            velocity = {0.0,  RECTANLGE_WIDTH};
            break;
        case LEFT:
            velocity = {-RECTANLGE_WIDTH, 0.0};
            break;
        case RIGHT:
            velocity = {RECTANLGE_WIDTH, 0.0};
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
    sf::RectangleShape snakeBodyPart {{RECTANGLE_LENGTH, RECTANLGE_WIDTH}};
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
