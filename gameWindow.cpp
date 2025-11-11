#include "gameWindow.h"
#include <string>

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

bool GameWindow::isOpen()
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
    window.draw(snakeBody.at(0));
}