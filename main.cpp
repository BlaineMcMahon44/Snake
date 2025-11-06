#include "snake.h"
#include "utils.h"
#include "keyDetector.h"
#include "keyDetectorFactory.h"
#include "gameContext.h"
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>   
#include <memory>
#include <iostream>

int main() {
    // Create window
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Snake");

    // Create snake
    Snake snake;

    // Set the initial direction to the left
    Direction currentDirection {LEFT};

    // Create a game context struct
    GameContext ctx {window, currentDirection};

    // Set the frame rate to 60 which is good enough for snake
    window.setFramerateLimit(60);

    // Create key objects to handle different keys
    std::unique_ptr<DetectKey> keyDetector;

    // Run the window as long as the window is open
    while (window.isOpen())
    {
        // Check all of the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        
            if (event->is<sf::Event::KeyPressed>())
            {
                const auto keyEvent = event->getIf<sf::Event::KeyPressed>();
                
                if (keyEvent)
                {
                    // Act on if a valid key was pressed
                    keyDetector = keyDetectorFactory::createKeyDetector(keyEvent->code);
                    if (keyDetector)
                        keyDetector->doSomething(ctx);
                }
            }
                
        }

        // Always move rectangle 
        snake.changeDirection(currentDirection);

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the rectangle from earlier
        window.draw((snake.getSnake()).at(0));

        // Display what we've drawn
        window.display();

        
    }
}