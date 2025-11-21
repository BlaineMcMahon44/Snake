#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Node
{
public:
    explicit Node(const sf::RectangleShape& snakePart);
    ~Node() = default;
    Node* next;
    Node* prev;
    sf::RectangleShape data;
};