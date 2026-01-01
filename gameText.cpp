#include "gameText.h"
#include "utils.h"
#include <filesystem>
#include <iostream>
GameText::GameText(const std::string& displayText, uint charSize, const sf::Vector2f position)
{
    std::cout << std::filesystem::current_path() << std::endl;
    if (!font.openFromFile("ARCADECLASSIC.TTF"))
    {
        throw std::runtime_error("Failed to load font");
    }
    if (!text)
    {
        text.emplace(font, displayText, charSize);
        text->setFillColor(sf::Color::White);
        text->setPosition(position);
    }
}

sf::Text GameText::getText() const
{
    return text.value();
}
