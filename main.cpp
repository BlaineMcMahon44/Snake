#include "snake.h"
#include "utils.h"
#include "keyDetector.h"
#include "keyDetectorFactory.h"
#include "gameContext.h"
#include "gameWindow.h"
#include "gameText.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "snakeFood.h"

int main()
{
    auto gameWindow = GameWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");

    Snake snake;

    auto food = std::make_unique<SnakeFood>();

    // Set the initial direction to the left
    Direction currentDirection {LEFT};

    GameContext ctx {gameWindow, currentDirection, false};

    gameWindow.setFrameRate(FRAME_RATE);

    auto titleText = GameText("Snake", 50, TITLE_TEXT_POSITION);
    auto menuText = GameText("Press enter to start", 30, MENU_TEXT_POSITION);

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

        // Clear the window with black color
        gameWindow.clear(sf::Color::Black);

        if (!ctx.isGameStarted)
        {
            gameWindow.drawText(titleText.getText());
            gameWindow.drawText(menuText.getText());
        }
        else
        {
            // Always move rectangle
            snake.changeDirection(currentDirection);

            // Draw the food
            if (food)
            {
                gameWindow.drawFood(food->getFood());
            }

            // Draw the rectangle from earlier
            gameWindow.drawSnake(snake.getSnake().getHead());
        }
        gameWindow.display();

    }
}
