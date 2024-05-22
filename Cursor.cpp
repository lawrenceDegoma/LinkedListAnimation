//
// Created by Lawrence Degoma on 5/19/24.
//

#include "Cursor.h"

Cursor::Cursor(unsigned int size)
        : cursor(sf::Vector2f(2.f, static_cast<float>(size))), blinkTime(sf::Time::Zero), visible(true) {
    cursor.setFillColor(sf::Color::Black);
}

void Cursor::update(sf::Time deltaTime) {
    blinkTime += deltaTime;
    if (blinkTime >= sf::seconds(0.5f)) {
        visible = !visible;
        blinkTime = sf::Time::Zero;
    }
}

void Cursor::render(sf::RenderWindow& window) {
    if (visible) {
        window.draw(cursor);
    }
}

void Cursor::updatePosition(sf::Vector2f position) {
    cursor.setPosition(position.x + 2, position.y); // Adjust the position of the cursor
}

unsigned int Cursor::getPosition() const {
    return position;
}

void Cursor::moveLeft() {
    if (position > 0) {
        position--;
    }
}