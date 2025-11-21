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

void GameWindow::draw(const Node* snakeHead)
{
    const Node* bodyPart = snakeHead;
    while (bodyPart)
    {
        std::cout << "X pos: " << bodyPart->data.getPosition().x << " Y Pos: "<< bodyPart->data.getPosition().y  << "\n";
        window.draw(bodyPart->data);
        bodyPart = bodyPart->next;
    }

}