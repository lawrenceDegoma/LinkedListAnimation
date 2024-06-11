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
    void setPlaceholder(const std::string& text);

    void clearContent();
    std::string getContent() const;
    bool isActive() const;

private:
    void processInput(sf::Uint32 unicode);
    void deleteCharacter();
    void undo();
    void deleteCharacterBeforeCursor();

    sf::RectangleShape box;
    sf::Text text;
    sf::Text placeholder;
    std::string content;
    unsigned int maxLength;
    bool active;
    Cursor cursor;
    UndoManager undoManager;
    void setContent(const std::string& content);
};

#endif //TEXTINPUTBOX_TEXTBOX_H
