#include "LinkedListAnimation.h"

int main() {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font file 'arial.ttf'");
    }

    LinkedListAnimation animation(font);
    animation.run();

    return 0;
}
