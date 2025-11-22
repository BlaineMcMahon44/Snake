#include "node.h"

/**
 * @brief Constructs a node by setting next & prev to nullptr and then sets the data field
 *
 * @param snakePart - sf::RectangleShape reference
 */
Node::Node(const sf::RectangleShape& snakePart)
{
    next = nullptr;
    prev = nullptr;
    data = snakePart;
}
