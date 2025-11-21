#pragma once
#include "node.h"
#include <SFML/Graphics.hpp>
#include <memory>

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList();
    ~LinkedList();
    void addTail(const sf::RectangleShape& snakePart);
    void moveTailToHead(const sf::Vector2f& velocity);
    float getHeadCoordinateX() const;
    float getHeadCoordinateY() const;
    int getSize() const {return size;};
    const Node* getHead() const;
};
