#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

/**
 * @breif Node class which stores a next and prev raw pointer
 * Holds sf::RectangleShape as data field
 */
class Node
{
public:
    /**
     * @brief Constructor which takes in a new snakePart
     *
     * @param snakePart - sf::RectangleShape reference
     */
    explicit Node(const sf::RectangleShape& snakePart);

    /**
     * @brief Set to default since the linked list handle deleting nodes
     */
    ~Node() = default;
    Node* next;
    Node* prev;
    sf::RectangleShape data;
};