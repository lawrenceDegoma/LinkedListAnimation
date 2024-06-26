#include "TextBox.h"

TextBox::TextBox(float x, float y, float width, float height, sf::Font& font)
        : box(sf::Vector2f(width, height)), maxLength(100), active(false),
          cursor(text.getCharacterSize()) {
    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font file 'arial.ttf'");
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(5.f, 5.f);

    placeholder.setFont(font);
    placeholder.setCharacterSize(24);
    placeholder.setFillColor(sf::Color(200, 200, 200)); // Lighter color for placeholder
    placeholder.setPosition(5.f, 5.f);

    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2.f);
}

void TextBox::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        // Ignore Enter key
        if (event.text.unicode != '\n' && event.text.unicode != '\r') {
            processInput(event.text.unicode);
        }
    } else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Delete) {
            deleteCharacterBeforeCursor();
        } else if (event.key.code == sf::Keyboard::Z && (event.key.control || event.key.system)) {
            undo();
        } else if (event.key.code == sf::Keyboard::Enter) {
            // Prevent cursor from moving to a new line
            // Just handle the enter key without deactivating the textbox
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (box.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            active = true;
        } else {
            active = false;
        }
    }
}

void TextBox::update(sf::Time deltaTime) {
    cursor.update(deltaTime);
}

void TextBox::render(sf::RenderWindow& window) {
    window.draw(box);
    if (content.empty() && !active) {
        window.draw(placeholder);
    } else {
        window.draw(text);
        if (active) {
            cursor.render(window);
        }
    }
}

void TextBox::processInput(sf::Uint32 unicode) {
    if (unicode < 128 && content.length() < maxLength) {
        content += static_cast<char>(unicode);
        text.setString(content);
        cursor.updatePosition(text.findCharacterPos(content.size()));
        undoManager.saveState(content);
    }
}

void TextBox::deleteCharacter() {
    if (!content.empty()) {
        content.pop_back();
        text.setString(content);
        cursor.updatePosition(text.findCharacterPos(content.size()));
        undoManager.saveState(content);
    }
}

void TextBox::undo() {
    content = undoManager.undo();
    text.setString(content);
    cursor.updatePosition(text.findCharacterPos(content.size()));
}

void TextBox::deleteCharacterBeforeCursor() {
    if (!content.empty() && cursor.getPosition() > 0) {
        content.erase(cursor.getPosition() - 1, 1);
        text.setString(content);
        cursor.moveLeft();
        cursor.updatePosition(text.findCharacterPos(cursor.getPosition()));
        undoManager.saveState(content);
    }
}

void TextBox::clearContent() {
    content.clear();
    text.setString("");
}

std::string TextBox::getContent() const {
    return content;
}

bool TextBox::isActive() const {
    return active;
}

void TextBox::setPlaceholder(const std::string& text) {
    placeholder.setString(text);
}

void TextBox::setContent(const std::string& newContent) {
    content = newContent;
    text.setString(content);
    cursor.updatePosition(text.findCharacterPos(content.size()));
}