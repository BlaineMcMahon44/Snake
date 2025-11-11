#include "snake.h"
#include "utils.h"
#include "keyDetector.h"
#include "keyDetectorFactory.h"
#include "gameContext.h"
#include "gameWindow.h"
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>   
#include <memory>
#include <iostream>

int main() {
    // Create a game window
    auto gameWindow = GameWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");

    // Create snake
    Snake snake;

    // Set the initial direction to the left
    Direction currentDirection {LEFT};

    // Create a game context struct
    GameContext ctx {gameWindow, currentDirection};

    // Set the frame rate to 60, which is good enough for snake
    gameWindow.setFrameRate(FRAME_RATE);

    // Pointer to keyDetector base class

    // Run the window as long as the window is open
    while (gameWindow.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = gameWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                gameWindow.close();
        
            if (event->is<sf::Event::KeyPressed>())
            {
                const auto keyEvent = event->getIf<sf::Event::KeyPressed>();
                
                if (keyEvent)
                {
                    // Returns a pointer to the correct derived class
                    std::unique_ptr<DetectKey> keyDetector = keyDetectorFactory::createKeyDetector(keyEvent->code);
                    if (keyDetector)
                        keyDetector->doSomething(ctx);
                }
            }
                
        }

        // Always move rectangle 
        //snake.changeDirection(currentDirection);

        // Clear the window with black color
        gameWindow.clear(sf::Color::Black);

        // Draw the rectangle from earlier
        gameWindow.draw(snake.getSnake());

        // Display the window
        gameWindow.display();

    }
}