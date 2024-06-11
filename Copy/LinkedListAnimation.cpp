//
// Created by Lawrence Degoma on 5/22/24.
//

#include "LinkedListAnimation.h"


LinkedListAnimation::LinkedListAnimation(sf::Font& font)
        : window(sf::VideoMode(1280, 720), "Linked List Animation"),
          textBox(200.f, 40.f, 150.f, 30.f, font),
          font(font),
          pushBackButton(300.f, 550.f, 150.f, 30.f, font, "Push Back"),
          pushAtPositionButton(500.f, 550.f, 150.f, 30.f, font, "Push At Position"),
          removeFrontButton(700.f, 550.f, 150.f, 30.f, font, "Remove Front"),
          pushFrontButton(300.f, 500.f, 150.f, 30.f, font, "Push Front"),
          removeBackButton(500.f, 500.f, 150.f, 30.f, font, "Remove Back"),
          removeAtPositionButton(700.f, 500.f, 150.f, 30.f, font, "Remove At Position"),
          pushBackActive(false),
          pushAtPositionActive(false),
          removeFrontActive(false),
          isWaitingForPosition(false),
          pendingValue(0) {}

void LinkedListAnimation::run() {
    while (window.isOpen()) {
        handleEvents();
        update(sf::seconds(5.0f));
        render();
    }
}

void LinkedListAnimation::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (pushBackButton.isClicked(window)) {
            int value;
            try {
                value = std::stoi(textBox.getContent());
            } catch (std::invalid_argument&) {
                std::cerr << "Invalid input\n";
                return;
            }
            list.push_back(value);
            textBox.clearContent();
        }
        if (pushAtPositionButton.isClicked(window) && !isWaitingForPosition) {
            try {
                pendingValue = std::stoi(textBox.getContent());
                isWaitingForPosition = true;
                textBox.clearContent();
                textBox.setPlaceholder("Enter position");
            } catch (std::invalid_argument&) {
                std::cerr << "Invalid input\n";
                return;
            }
        }
        if (removeFrontButton.isClicked(window)) {
            list.removeNodeFromFront();
        }
        if (pushFrontButton.isClicked(window)) {
            int value;
            try {
                value = std::stoi(textBox.getContent());
            } catch (std::invalid_argument&) {
                std::cerr << "Invalid input\n";
                return;
            }
            list.push_front(value);
            textBox.clearContent();
        }
        if (removeBackButton.isClicked(window)) {
            list.removeNodeFromEnd();
        }
        if (removeAtPositionButton.isClicked(window) && !isWaitingForRemoval) {
            isWaitingForRemoval = true;
            textBox.clearContent();
            textBox.setPlaceholder("Enter position to remove");
        }

        textBox.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && textBox.isActive()) {
            if (isWaitingForPosition) {
                int position;
                try {
                    position = std::stoi(textBox.getContent());
                } catch (std::invalid_argument&) {
                    std::cerr << "Invalid input\n";
                    return;
                }
                list.push_at_position(pendingValue, position);
                textBox.clearContent();
                textBox.setPlaceholder("Enter value");
                isWaitingForPosition = false;
            } else if (isWaitingForRemoval) {
                int position;
                try {
                    position = std::stoi(textBox.getContent());
                } catch (std::invalid_argument&) {
                    std::cerr << "Invalid input\n";
                    return;
                }
                list.removeNodeFromPosition(position);
                textBox.clearContent();
                textBox.setPlaceholder("Enter value");
                isWaitingForRemoval = false;
            } else {
                int value;
                try {
                    value = std::stoi(textBox.getContent());
                } catch (std::invalid_argument&) {
                    std::cerr << "Invalid input\n";
                    return;
                }
                list.push_back(value);
                textBox.clearContent();
            }
        }
    }
}


void LinkedListAnimation::update(sf::Time deltaTime) {
    textBox.update(deltaTime);
}

void LinkedListAnimation::render() {
    window.clear(sf::Color::White);
    list.draw(window); // Draw the linked list
    textBox.render(window); // Draw the text input box
    // Draw buttons
    pushBackButton.draw(window);
    pushAtPositionButton.draw(window);
    removeFrontButton.draw(window);
    pushFrontButton.draw(window);
    removeBackButton.draw(window);
    removeAtPositionButton.draw(window);
    window.display();
}