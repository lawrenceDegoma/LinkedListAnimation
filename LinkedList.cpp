//
// Created by Lawrence Degoma on 5/22/24.
//

#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    nodes.push_back(newNode);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    nodes.push_back(newNode);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::push_at_position(int value, int position) {
    if (position <= 0) {
        push_front(value);
        return;
    }

    Node* newNode = new Node(value);
    nodes.push_back(newNode);
    Node* current = head;
    for (int i = 0; current != nullptr && i < position; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        push_back(value);
    } else {
        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev != nullptr) {
            current->prev->next = newNode;
        }
        current->prev = newNode;
        if (newNode->prev == nullptr) {
            head = newNode;
        }
    }
}

void LinkedList::removeNodeFromFront() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    nodes.erase(std::remove(nodes.begin(), nodes.end(), temp), nodes.end());
    delete temp;
}

void LinkedList::removeNodeFromEnd() {
    if (tail == nullptr) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    nodes.erase(std::remove(nodes.begin(), nodes.end(), temp), nodes.end());
    delete temp;
}

void LinkedList::removeNodeFromPosition(int position) {
    if (position <= 0) {
        removeNodeFromFront();
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < position; ++i) {
        current = current->next;
    }

    if (current == nullptr) return;

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    nodes.erase(std::remove(nodes.begin(), nodes.end(), current), nodes.end());
    delete current;
}


void LinkedList::draw(sf::RenderWindow& window) {
    float nodeWidth = 80.0f;
    float nodeHeight = 50.0f;
    float arrowLength = 20.0f;
    float arrowHeadSize = 10.0f;
    float spacing = 50.0f;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return;
    }

    // Draw nodes and arrows
    Node* current = head;
    while (current != nullptr) {
        // Draw node body
        sf::RectangleShape rectangle(sf::Vector2f(nodeWidth, nodeHeight));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setOutlineThickness(2);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setPosition(spacing, 100.0f);
        window.draw(rectangle);

        // Draw node data
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(current->data));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(spacing + 25.0f, 100.0f + 10.0f);
        window.draw(text);

        // Draw arrows
        if (current->next != nullptr) {
            // Arrow to next node
            sf::VertexArray arrow(sf::Lines, 2);
            arrow[0].position = sf::Vector2f(spacing + nodeWidth, 125.0f + nodeHeight / 2); // Start point
            arrow[1].position = sf::Vector2f(spacing + nodeWidth + arrowLength, 125.0f + nodeHeight / 2); // End point
            arrow[0].color = sf::Color::Black;
            arrow[1].color = sf::Color::Black;
            window.draw(arrow);

            // Draw arrowhead
            sf::ConvexShape arrowHead;
            arrowHead.setPointCount(3);
            arrowHead.setPoint(0, sf::Vector2f(spacing + nodeWidth + arrowLength - arrowHeadSize, 125.0f + nodeHeight / 2 - arrowHeadSize / 2));
            arrowHead.setPoint(1, sf::Vector2f(spacing + nodeWidth + arrowLength - arrowHeadSize, 125.0f + nodeHeight / 2 + arrowHeadSize / 2));
            arrowHead.setPoint(2, sf::Vector2f(spacing + nodeWidth + arrowLength, 125.0f + nodeHeight / 2));
            arrowHead.setFillColor(sf::Color::Black);
            window.draw(arrowHead);
        }
        if (current->prev != nullptr) {
            // Arrow to previous node
            sf::VertexArray arrow(sf::Lines, 2);
            arrow[0].position = sf::Vector2f(spacing - arrowLength, 125.0f + nodeHeight / 2); // Start point
            arrow[1].position = sf::Vector2f(spacing, 125.0f + nodeHeight / 2); // End point
            arrow[0].color = sf::Color::Black;
            arrow[1].color = sf::Color::Black;
            window.draw(arrow);

            // Draw arrowhead
            sf::ConvexShape arrowHead;
            arrowHead.setPointCount(3);
            arrowHead.setPoint(0, sf::Vector2f(spacing - arrowLength + arrowHeadSize, 125.0f + nodeHeight / 2 - arrowHeadSize / 2));
            arrowHead.setPoint(1, sf::Vector2f(spacing - arrowLength + arrowHeadSize, 125.0f + nodeHeight / 2 + arrowHeadSize / 2));
            arrowHead.setPoint(2, sf::Vector2f(spacing - arrowLength, 125.0f + nodeHeight / 2));
            arrowHead.setFillColor(sf::Color::Black);
            window.draw(arrowHead);
        }

        spacing += nodeWidth + arrowLength; // Increase spacing for next node
        current = current->next;
    }
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    nodes.clear();
}

std::vector<Node*> LinkedList::getNodes() {
    return nodes;
}