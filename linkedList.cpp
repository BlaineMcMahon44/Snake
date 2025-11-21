#include "linkedList.h"
#include <iostream>
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

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}


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
        head->next = newNode;
        tail = tail->next;
    }
}

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

float LinkedList::getHeadCoordinateX() const
{
    return head->data.getPosition().x;
}

float LinkedList::getHeadCoordinateY() const
{
    return head->data.getPosition().y;
}

const Node* LinkedList::getHead() const
{
    if (!head)
        throw std::runtime_error("LinkedList::getHead() called on empty list");
    return head;
}

