#include "gameWindow.h"
#include <string>
#include <iostream>

GameWindow::GameWindow(const unsigned int windowWidth, const unsigned int windowHeight, const std::string& description) 
: window(sf::VideoMode({windowWidth, windowHeight}), description)
{}

void GameWindow::setFrameRate(const int frameRate)
{
    window.setFramerateLimit(frameRate);
}

std::optional<sf::Event> GameWindow::pollEvent()
{
    return window.pollEvent();
}

bool GameWindow::isOpen() const
{
    if (window.isOpen())
        return true;
    return false;
}

void GameWindow::close()
{
    window.close();
}

void GameWindow::clear(sf::Color color)
{
    window.clear(color);
}

void GameWindow::display()
{
    window.display();
}

void GameWindow::draw(const std::vector<sf::RectangleShape>& snakeBody)
{
    for (sf::RectangleShape bodyPart: snakeBody)
    {
        std::cout << "X pos: " << bodyPart.getPosition().x << " Y Pos: "<< bodyPart.getPosition().y  << "\n";
        window.draw(bodyPart);
    }
}