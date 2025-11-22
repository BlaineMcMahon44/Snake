#pragma once
#include "node.h"
#include <SFML/Graphics.hpp>
#include <memory>

/**
 * @breif double-linked list class that is responsible for holding nodes and size
 */
class LinkedList
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    /**
     * @breif constructor that creates a double-linked list with raw head and tail pointers that point to nullptr
     */
    LinkedList();

    /**
     * @breif deconstructor that handles traverses the double-linked list and deletes each node
     */
    ~LinkedList();

    /**
     * @breif Add a new node to the double-linked list at the tail of the list, also increments size
     *
     * @param snakePart - data portion that node will contain sf::RectangleShape
     */
    void addTail(const sf::RectangleShape& snakePart);

    /**
     * @brief Move the tail one RECTANGLE_LENGTH in front of the current head to simulate snake movement
     *
     * @param velocity - sf::Vector2f reference which will indicate which indicates direction of snake
     */
    void moveTailToHead(const sf::Vector2f& velocity);

    /**
     * @breif Retrieve the x coordinate from the node that head is pointing to
     *
     * @return - float value of the x position of the head of the snake
     */
    float getHeadCoordinateX() const;

    /**
     * @breif Retrieve the y coordinate from the node that head is pointing to
     *
     * @return - float value of the y position of the head of the snake
     */
    float getHeadCoordinateY() const;

    /**
     * @breif Retrieve the y coordinate from the node that tail is pointing to
     *
     * @return - float value of the y position of the head of the snake
     */
    float getTailCoordinateX() const;

    /**
     * @breif Retrieve the y coordinate from the node that tail is pointing to
     *
     * @return - float value of the y position of the head of the snake
     */
    float getTailCoordinateY() const;

    /**
     * @breif Will get the size of the linked list
     *
     * @return - int indicating number of nodes the linked list is holding
     */
    int getSize() const {return size;};

    /**
     * @breif Retrieve a pointer to the head node of the linked list
     *
     * @return - raw pointer to the head of the linked list
     */
    const Node* getHead() const;
};
