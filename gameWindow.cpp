#include "gameWindow.h"
#include <string>
#include <iostream>

/**
 * @class GameWindow
 * @brief A lightweight wrapper around sf::RenderWindow that manages
 *        window creation, event polling, drawing, and lifecycle operations.
 *
 * This class abstracts away raw SFML window handling and adds higher-level
 * utility methods such as optional-returning event polling and drawing an
 * entire linked list of snake body nodes.
 */
GameWindow::GameWindow(const unsigned int windowWidth, const unsigned int windowHeight, const std::string& description) 
: window(sf::VideoMode({windowWidth, windowHeight}), description)
{}

/**
 * @brief Sets the maximum frame rate for the window.
 *
 * @param frameRate The frame limit per second.
 *
 * This forwards directly to SFML’s `setFramerateLimit` to avoid running
 * the game loop at an unbounded rate.
 */
void GameWindow::setFrameRate(const int frameRate)
{
    window.setFramerateLimit(frameRate);
}

/**
 * @breif Polls the window for a pending event.
 *
 * @return std::optional<sf::Event>
 *         contains an event if one was received, otherwise std::nullptr
 *
 * Wrapping this in `std::optional` allows for (auto event = window.pollEvent() {...}
 */
std::optional<sf::Event> GameWindow::pollEvent()
{
    return window.pollEvent();
}

/**
 * @breif Checks if the window is still open
 *
 * @return true if open, false otherwise.
 */
bool GameWindow::isOpen() const
{
    if (window.isOpen())
        return true;
    return false;
}

/**
 * @breif Closes the window
 *
 * Calls SFML's `RenderWindow::close()` to signal termination of the window
 */
void GameWindow::close()
{
    window.close();
}

/**
 * @breif Clears window with specified color
 *
 * @param color the background color to use for the window
 */
void GameWindow::clear(const sf::Color color)
{
    window.clear(color);
}

/**
 * @breif displays everything that was drawn in the window
 *
 * Calls SFML's `RenderWindow::display()` to show the window
 */
void GameWindow::display()
{
    window.display();
}

/**
 * @brief Draws each rectangle that is a part of the snake
 *
 * @param snakeHead pointer to the head of the snake
 *
 * Create a tmp pointer copy the head to iterate through the linked list and pass the sf::Rectangle
 * to the window draw function which calls `RenderWindow::draw` method
 */
void GameWindow::drawSnake(const Node* snakeHead)
{
    const Node* bodyPart = snakeHead;
    while (bodyPart)
    {
        std::cout << "X pos: " << bodyPart->data.getPosition().x << " Y Pos: "<< bodyPart->data.getPosition().y  << "\n";
        window.draw(bodyPart->data);
        bodyPart = bodyPart->next;
    }

}

void GameWindow::drawFood(const sf::RectangleShape& food)
{
    window.draw(food);
}