//
// Created by Lawrence Degoma on 5/21/24.
//

#ifndef BINARYSEARCHTREESFML_BUTTON_H
#define BINARYSEARCHTREESFML_BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(float x, float y, float width, float height, sf::Font& font, std::string text);
    void draw(sf::RenderWindow& window);
    bool isClicked(sf::RenderWindow& window);

private:
    sf::RectangleShape button;
    sf::Text buttonText;
};


#endif //BINARYSEARCHTREESFML_BUTTON_H
