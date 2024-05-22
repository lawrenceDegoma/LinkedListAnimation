//
// Created by Lawrence Degoma on 5/19/24.
//

#ifndef TEXTINPUTBOX_TEXTBOX_H
#define TEXTINPUTBOX_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Cursor.h"
#include "UndoManager.h"

class TextBox {
public:
    TextBox(float width, float height);

    void handleEvent(const sf::Event& event);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);

private:
    void processInput(sf::Uint32 unicode);
    void deleteCharacter();
    void deleteCharacterBeforeCursor();
    void undo();

    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string content;
    Cursor cursor;
    UndoManager undoManager;

    unsigned int maxLength;
    bool isActive;
};

#endif //TEXTINPUTBOX_TEXTBOX_H
