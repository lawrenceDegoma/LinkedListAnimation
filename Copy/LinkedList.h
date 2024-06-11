//
// Created by Lawrence Degoma on 5/22/24.
//

#ifndef LINKEDLISTANIMATION_LINKEDLIST_H
#define LINKEDLISTANIMATION_LINKEDLIST_H

#include "Node.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class LinkedList {
private:
    Node* head;
    Node* tail;
    std::vector<Node*> nodes;
public:
    LinkedList();
    ~LinkedList();

    void push_front(int value);
    void push_back(int value);
    void push_at_position(int value, int position);

    void removeNodeFromFront();
    void removeNodeFromEnd();
    void removeNodeFromPosition(int position);

    void draw(sf::RenderWindow& window);
    void clear();

    std::vector<Node*> getNodes();
};


#endif //LINKEDLISTANIMATION_LINKEDLIST_H
