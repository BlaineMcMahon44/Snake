#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
class GameText
{
private:
    sf::Font font;
    std::optional<sf::Text> text;
public:
    GameText(const std::string& displayText, uint charSize, sf::Vector2f position);
    sf::Text getText() const;
};