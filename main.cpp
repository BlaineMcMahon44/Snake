#include "snake.h"
#include "utils.h"
#include "keyDetector.h"
#include "keyDetectorFactory.h"
#include "gameContext.h"
#include "gameWindow.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

int main() {
    auto gameWindow = GameWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");

    Snake snake;

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

        if (test < 2)
            snake.addBody();

        test++;

        // Clear the window with black color
        gameWindow.clear(sf::Color::Black);

        // Draw the rectangle from earlier
        gameWindow.draw(snake.getSnake().getHead());

        // Display the window
        gameWindow.display();

    }
}