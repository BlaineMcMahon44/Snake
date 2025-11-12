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
    snakeBody.push_back(snakeHead);
}

bool Snake::spawnSnake(sf::RectangleShape& snakeHead)
{
    Coordinates snakeSpawnCoordinates {};
    generateSpawnPoint(snakeSpawnCoordinates);
    std::cout << "Snake spawned at " << snakeSpawnCoordinates.xPos << " " << snakeSpawnCoordinates.yPos << "\n";
    snakeHead.setPosition({snakeSpawnCoordinates.xPos, snakeSpawnCoordinates.yPos});
    return true;
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
    moveDirection = direction;

    // Set the speed of snake in the correct direction
    setVelocity();

    // Get coordinates to validate if snake is in bounds
    const float xPos = snakeBody.at(0).getPosition().x;
    const float yPos = snakeBody.at(0).getPosition().y;

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
    std::cout << "snake size is" << snakeBody.size() << "\n";
    if (snakeBody.size() > 1)
    {
        std::rotate(snakeBody.rbegin(), snakeBody.rbegin() + 1, snakeBody.rend());
        snakeBody.at(0).move(velocity);
    }
}

// Return the snake head
const std::vector<sf::RectangleShape>& Snake::getSnake()
{
    return snakeBody;
}

void Snake::setVelocity()
{
    switch (moveDirection)
    {
        case UP:
            velocity = {0.0, -1.0};
            break;
        case DOWN:
            velocity = {0.0, 1.0};
            break;
        case LEFT:
            velocity = {-1.0, 0.0};
            break;
        case RIGHT:
            velocity = {1.0, 0.0};
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
    switch (moveDirection)
    {
    case UP:
        offset = {velocity.x, velocity.y + (1.0f + RECTANLGE_WIDTH)};
        break;
    case DOWN:
        offset = {velocity.x, velocity.y - (1.0f + RECTANLGE_WIDTH)};
        break;
    case LEFT:
        offset = {velocity.x + (1.0f + RECTANLGE_WIDTH), velocity.y};
        break;
    case RIGHT:
        offset = {velocity.x - (1.0f + RECTANLGE_WIDTH), velocity.y};
        break;
    default:
        offset = {0.0, 0.0};
        break;
    };
    const sf::Vector2f headPosition = snakeBody.at(0).getPosition();
    std::cout << "Offset is " << offset.x << " " << offset.y << "\n";
    return headPosition + offset;
}


void Snake::addBody()
{
    sf::RectangleShape snakeBodyPart {{RECTANGLE_LENGTH, RECTANLGE_WIDTH}};
    snakeBodyPart.setPosition(addBodyHelper());
    snakeBody.push_back(snakeBodyPart);
}
