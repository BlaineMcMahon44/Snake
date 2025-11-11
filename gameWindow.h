#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>   
#include <memory>
#include <iostream>
#include <string>


#pragma once

class GameWindow {
private:
    sf::RenderWindow window;

public:
    GameWindow(const unsigned int windowWidth, const unsigned int windowHeight, const std::string& description);
    void setFrameRate(int frameRate);
    bool isOpen();
    std::optional<sf::Event> pollEvent();
    void close();
    void clear(sf::Color color);
    void display();
    void draw(const std::vector<sf::RectangleShape>& snake);
};