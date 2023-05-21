#pragma once
#include "SFML/Graphics.hpp"

class Images {
public:
    sf::Texture welcomeImage;
    Images() {
        welcomeImage.loadFromFile("Images/chessImage4.jpg");
    }
};