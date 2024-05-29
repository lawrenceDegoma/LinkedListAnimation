//
// Created by Lawrence Degoma on 5/22/24.
//

#ifndef LINKEDLISTANIMATION_LINKEDLISTANIMATION_H
#define LINKEDLISTANIMATION_LINKEDLISTANIMATION_H

#include "LinkedList.h"
#include "TextBox.h"
#include "Button.h"

class LinkedListAnimation {
public:
    LinkedListAnimation(sf::Font& font);

    void run();

private:
    sf::RenderWindow window;
    LinkedList list;
    TextBox textBox;
    Button pushBackButton;
    Button pushAtPositionButton;
    Button removeFrontButton;
    Button pushFrontButton;
    Button removeBackButton;
    sf::Font font;
    bool pushBackActive;
    bool pushAtPositionActive;
    bool removeFrontActive;

    void handleEvents();
    void update(sf::Time deltaTime);
    void render();
};


#endif //LINKEDLISTANIMATION_LINKEDLISTANIMATION_H
