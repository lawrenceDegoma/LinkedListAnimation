//
// Created by Lawrence Degoma on 5/22/24.
//

#include "LinkedListAnimation.h"

LinkedListAnimation::LinkedListAnimation() : window(sf::VideoMode(800, 600), "Linked List Animation") {}

void LinkedListAnimation::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    int value;
                    std::cout << "Enter value to add at front: ";
                    std::cin >> value;
                    list.push_front(value);
                }
                if (event.key.code == sf::Keyboard::Num2) {
                    int value;
                    std::cout << "Enter value to add at end: ";
                    std::cin >> value;
                    list.push_back(value);
                }
                if (event.key.code == sf::Keyboard::Num3) {
                    int value, position;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    std::cout << "Enter position: ";
                    std::cin >> position;
                    list.push_at_position(value, position);
                }
                if (event.key.code == sf::Keyboard::Num4) {
                    list.removeNodeFromFront();
                }
                if (event.key.code == sf::Keyboard::Num5) {
                    list.removeNodeFromEnd();
                }
                if (event.key.code == sf::Keyboard::Num6) {
                    int position;
                    std::cout << "Enter position: ";
                    std::cin >> position;
                    list.removeNodeFromPosition(position);
                }
            }
        }

        window.clear(sf::Color::White);
        list.draw(window);
        window.display();
    }
}