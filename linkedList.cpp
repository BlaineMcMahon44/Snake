#include "linkedList.h"
#include <iostream>

/**
 * @brief Will deconstruct the linked list by creating a cur pointer
 * starts at the head of the linked list and while it is not null
 * create another pointer to the next node in the list and then delete the cur pointer
 * set head and tail to null pointers and reset size
 */
LinkedList::~LinkedList()
{
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * @breif Constructs a double-linked list and sets head and tail to null pointers, and size to 0
 */
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * @breif Adds a new node to the end of the tail of the double-linked list
 * Creates a new node raw pointer that has a new snake part
 * Connect the new node to the prev tail of the double-linked list
 * Connect the prev tail to the new node
 * Update the new tail and increment size
 *
 * @param snakePart - Reference to a sf::RectangleShape the data the new node will hold
 */
void LinkedList::addTail(const sf::RectangleShape& snakePart)
{
    Node* newNode = new Node(snakePart);
    size++;

    // If this is the first element
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }
}

/**
 * @breif Moves the tail node to in front of the head
 * Removes need to update every node in the double-linked list
 *
 * If a double-linked list is empty do nothing
 * If there's only one link, we just need to move head
 *
 * Otherwise get the head position and the velocity for position of newHead
 * Create a raw pointer to the tail of the linked-list and then move tail to prev
 * Make oldTail the head by setting pointers accordingly
 *
 * Finally set the position of new head to be in front of oldHead
 *
 * @param velocity - sf::Vector2f signifies the direction we are moving
 */
void LinkedList::moveTailToHead(const sf::Vector2f& velocity)
{
    if (!head) return;

    // Handle case for only one node in the list
    if (tail == head)
    {
        head->data.move(velocity);
        return;
    }

    sf::Vector2f newHeadPosition = head->data.getPosition() + velocity;
    Node* oldTail = tail;

    tail = tail->prev;
    tail->next = nullptr;

    oldTail->prev = nullptr;
    oldTail->next = head;

    head->prev = oldTail;
    head = oldTail;
    head->data.setPosition(newHeadPosition);

}

/**
 * @breif Get the head nodes sf::Rectangle x pos
 *
 * @return - float x position
 */
float LinkedList::getHeadCoordinateX() const
{
    return head->data.getPosition().x;
}

/**
 * @breif Get the head nodes sf::Rectangle y pos
 *
 * @return - float y position
 */
float LinkedList::getHeadCoordinateY() const
{
    return head->data.getPosition().y;
}

/**
 * @breif Get the tail nodes sf::Rectangle x pos
 *
 * @return - float x position
 */
float LinkedList::getTailCoordinateX() const
{
    return tail->data.getPosition().x;
}

/**
 * @breif Get the tail nodes sf::Rectangle y pos
 *
 * @return - float y position
 */
float LinkedList::getTailCoordinateY() const
{
    return tail->data.getPosition().y;
}

/**
 * @brief Return a raw pointer to the head of the double linked list
 *
 * @return - raw node pointer
 */
const Node* LinkedList::getHead() const
{
    if (!head)
        throw std::runtime_error("LinkedList::getHead() called on empty list");
    return head;
}

