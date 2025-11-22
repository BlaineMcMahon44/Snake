#pragma once
#include "node.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>   
#include <memory>
#include <iostream>
#include <string>

/**
 * @class GameWindow
 *
 * @brief wrapper class around sf::RenderWindow providing simplified window management
 */
class GameWindow {
private:
    sf::RenderWindow window;

public:
    /**
     * @breif Construct a sf::RenderWindow with a given width, height, and description
     *
     * @param windowWidth  - Width of the window in pixels
     * @param windowHeight - Height of the window in pixels
     * @param description  - Title of the window
     */
    GameWindow(const unsigned int windowWidth, const unsigned int windowHeight, const std::string& description);

    /**
     * @breif Bounds the framerate of the window
     *
     * @param frameRate - Number of frames that will run per second
     */
    void setFrameRate(int frameRate);

    /**
     * @brief Checks whether the window is open or not
     *
     * @return boolean value depending on if a window is open or not
     */
    bool isOpen() const;

    /**
     * @brief Polls the window for events
     *
     * @return sf::Event or nullptr
     */
    std::optional<sf::Event> pollEvent();

    /**
     * @breif Closes the window
     */
    void close();

    /**
     * @breif Clears window with the desired color
     *
     * @param color - Color to clear a window with
     */
    void clear(sf::Color color);

    /**
     * @breif Displays the window
     */
    void display();

    /**
     * @breif Draws the entire snake to a window
     *
     * @param snakeHead - pointer to the head of the snake
     */
    void draw(const Node* snakeHead);
};