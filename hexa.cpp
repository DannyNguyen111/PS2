// Copyright 2025 Danny Nguyen

#include <cmath>
#include "hexa.hpp"
Hexaflake::Hexaflake(double length, int depth)
    : sideLength(length), recursionDepth(depth) {}
void Hexaflake::createHexaflake(double x, double y,
double length, int depth, sf::RenderWindow &window) {
    if (depth == 0) {
        return;
    }

    sf::Color colors[7] = {
      sf::Color::Red, sf::Color::Green, sf::Color::Blue,
      sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta,
      sf::Color::White
    };

    // Calculate the side length of each child hexagon
    double childLength = length / 3.0;

    double distX = childLength * 1.75;
    double distY = childLength * std::sqrt(3.0);

    // If this is the last recursion level, draw a filled hexagon
    if (depth == 1) {
        drawHexagon(x, y, length, window,  colors[(recursionDepth - depth) % 7]);
    } else {
        drawHexagonOutline(x, y, length, window, sf::Color::Transparent);
    }

    // Recurse on the center child
    createHexaflake(x, y, childLength, depth - 1, window);

    for (int i = 0; i < 6; ++i) {
        double offsetX = 0.0, offsetY = 0.0;
        switch (i) {
            case 0:
                offsetX = 0.0;
                offsetY = -distY * 1.18;
                break;
            case 1:
                offsetX = distX;
                offsetY = -distY / 1.667;
                break;
            case 2:
                offsetX = distX;
                offsetY = distY / 1.667;
                break;
            case 3:
                offsetX = 0.0;
                offsetY = distY * 1.18;
                break;
            case 4:
                offsetX = -distX;
                offsetY = distY / 1.667;
                break;
            case 5:
                offsetX = -distX;
                offsetY = -distY / 1.667;
                break;
        }
        createHexaflake(x + offsetX, y + offsetY, childLength, depth - 1, window);
    }
}

void Hexaflake::drawHexagon(double x, double y,
double length, sf::RenderWindow &window, sf::Color color) const {
    sf::CircleShape hexagon(length, 6);
    hexagon.setOrigin(length, length);  // origin at center
    hexagon.setPosition(x, y);
    hexagon.setRotation(0);
    hexagon.setFillColor(color);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(1);
    window.draw(hexagon);
}

void Hexaflake::drawHexagonOutline(double x, double y, double length,
sf::RenderWindow &window, sf::Color color) const {
    sf::CircleShape hexagon(length, 6);
    hexagon.setOrigin(length, length);
    hexagon.setPosition(x, y);
    hexagon.setRotation(0);
    hexagon.setFillColor(sf::Color::Transparent);
    hexagon.setOutlineColor(color);
    hexagon.setOutlineThickness(1);
    window.draw(hexagon);
}

