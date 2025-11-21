#include "snake.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

/*
* The constructor creates an sf::RectangleShape object with provide coordinates
* Adds this as the head to the snake vector
*/
Snake::Snake()
{  
    // Create head of the snake from with 10 x 10 floats
    sf::RectangleShape snakeHead {{RECTANGLE_LENGTH, RECTANLGE_WIDTH}};

    // Spawn the snake
    if (!spawnSnake(snakeHead))
    {
        throw std::runtime_error("Error spawning snake");
    }
    snakeBody->addTail(snakeHead);
}

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

// Method to check if the snake head is in bounds
bool Snake::checkBounds(const float xPos, const float yPos)
{
    if ( (xPos >= static_cast<float>(WINDOW_WIDTH)) || (xPos <= OUT_OF_BOUNDS) ||
        (yPos >= static_cast<float>(WINDOW_HEIGHT)) || (yPos <= OUT_OF_BOUNDS ))
    {
        return false;
    }
    return true;
}


// Method to move the snake to a new position
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


void Snake::setVelocity()
{
    switch (moveDirection)
    {
        case UP:
            velocity = {0.0, -1.0 + -RECTANLGE_WIDTH};
            break;
        case DOWN:
            velocity = {0.0, 1.0 + RECTANLGE_WIDTH};
            break;
        case LEFT:
            velocity = {-1.0 + -RECTANLGE_WIDTH, 0.0};
            break;
        case RIGHT:
            velocity = {(1.0 + RECTANLGE_WIDTH), 0.0};
            break;
        default:
            break;
    };
}

sf::Vector2f Snake::addBodyHelper()
{
    sf::Vector2f offset {};
    std::cout << "Velocity is " << velocity.x << " " << velocity.y << "\n";
    std::cout << "Move direction is " << moveDirection << "\n";

    offset = {velocity.x, velocity.y};

    // switch (moveDirection)
    // {
    // case UP:
    //     offset = {velocity.x, velocity.y};
    //     break;
    // case DOWN:
    //     offset = {velocity.x, velocity.y};
    //     break;
    // case LEFT:
    //     offset = {velocity.x, velocity.y};
    //     break;
    // case RIGHT:
    //     offset = {velocity.x, velocity.y};
    //     break;
    // default:
    //     offset = {0.0, 0.0};
    //     break;
    // };
    const sf::Vector2f headPosition = {snakeBody->getHeadCoordinateX(), snakeBody->getHeadCoordinateY()};
    std::cout << "Offset is " << offset.x << " " << offset.y << "\n";
    std::cout << "Head position is " << headPosition.x << " " << headPosition.y << "\n";
    return headPosition + offset;
}


void Snake::addBody()
{
    sf::RectangleShape snakeBodyPart {{RECTANGLE_LENGTH, RECTANLGE_WIDTH}};
    snakeBodyPart.setPosition(addBodyHelper());
    snakeBody->addTail(snakeBodyPart);
}

LinkedList& Snake::getSnake() const
{
    if (!snakeBody)
        throw std::runtime_error("LinkedList::getHead() called on empty list");
    return *snakeBody;
}
