#include "snake.h"
#include "utils.h"
#include "keyDetector.h"
#include "keyDetectorFactory.h"
#include "gameContext.h"
#include "gameWindow.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "snakeFood.h"

int main() {
    auto gameWindow = GameWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");

    Snake snake;

    auto food = std::make_unique<SnakeFood>();

    // Set the initial direction to the left
    Direction currentDirection {LEFT};

    GameContext ctx {gameWindow, currentDirection};

    gameWindow.setFrameRate(FRAME_RATE);

    int test = 0;

    while (gameWindow.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = gameWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                gameWindow.close();
        
            if (event->is<sf::Event::KeyPressed>())
            {
                if (const auto keyEvent = event->getIf<sf::Event::KeyPressed>())
                {
                    // Returns a pointer to the correct derived class
                    if (const std::unique_ptr<DetectKey> keyDetector = keyDetectorFactory::createKeyDetector(keyEvent->code))
                        keyDetector->doSomething(ctx);
                }
            }
                
        }

        // Always move rectangle 
        snake.changeDirection(currentDirection);

        test++;

        // Clear the window with black color
        gameWindow.clear(sf::Color::Black);

        // Draw the food
        if (food)
        {
            gameWindow.drawFood(food->getFood());
        }

        // Draw the rectangle from earlier
        gameWindow.drawSnake(snake.getSnake().getHead());

        // Display the window
        gameWindow.display();

    }
}
