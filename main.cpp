// Copyright 2025 Danny Nguyen

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "hexa.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <side length L> <recursion depth N>\n";
        return 1;
    }

    double L = std::stod(argv[1]);
    int N = std::stoi(argv[2]);

    if (L <= 0 || N < 0) {
        std::cerr << "Side length must be positive and depth non-negative.\n";
        return 1;
    }

    const unsigned int windowSize = 800;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Hexaflake");
    window.setFramerateLimit(60);

    Hexaflake hexaflake(L, N);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        hexaflake.createHexaflake(windowSize / 2.0, windowSize / 2.0, L, N, window);

        window.display();
    }

    return 0;
}

