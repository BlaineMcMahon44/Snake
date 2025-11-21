#include "node.h"

Node::Node(const sf::RectangleShape& snakePart)
{
    next = nullptr;
    prev = nullptr;
    data = snakePart;
}
