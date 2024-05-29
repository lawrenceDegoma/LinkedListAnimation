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
    TextBox(float x, float y, float width, float height, sf::Font& font);

    void handleEvent(const sf::Event& event);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);

    void clearContent(); // Clear the content of the text box
    std::string getContent() const; // Get the content of the text box

    bool isActive() const;

private:
    void processInput(sf::Uint32 unicode);
    void deleteCharacter();
    void undo();
    void deleteCharacterBeforeCursor();

    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string content;
    UndoManager undoManager;
    bool active;
    Cursor cursor;
    unsigned int maxLength;
};

#endif //TEXTINPUTBOX_TEXTBOX_H
