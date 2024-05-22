//
// Created by Lawrence Degoma on 5/22/24.
//

#ifndef LINKEDLISTANIMATION_LINKEDLISTANIMATION_H
#define LINKEDLISTANIMATION_LINKEDLISTANIMATION_H

#include "LinkedList.h"

class LinkedListAnimation {
private:
    LinkedList list;
    sf::RenderWindow window;
public:
    LinkedListAnimation();
    void run();
};


#endif //LINKEDLISTANIMATION_LINKEDLISTANIMATION_H
