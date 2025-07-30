// Copyright 2025 Danny Nguyen
#ifndef HEXA_HPP
#define HEXA_HPP

#include <SFML/Graphics.hpp>

class Hexaflake {
 public:
    // Constructor: initial side length and recursion depth
    Hexaflake(double length, int depth);

    // Recursively draw the hexa­flake centered at (x, y) with a given side length and depth
    void createHexaflake(double x, double y, double length, int depth, sf::RenderWindow &window);

 private:
    double sideLength;
    int recursionDepth;

    // Draw a filled, pointy‐topped hexagon (used at depth == 1)
    void drawHexagon(double x, double y, double length,
    sf::RenderWindow &window, sf::Color color) const;

    // Draw only the outline of a pointy‐topped hexagon (used at depth > 1)
    void drawHexagonOutline(double x, double y, double length,
    sf::RenderWindow &window, sf::Color color) const;
};

#endif  // HEXA_HPP
