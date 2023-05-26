#pragma once
#include "SFML/Graphics.hpp"

class Images {
public:
    sf::Texture welcomeImage;
    sf::Sprite chessBoard;

    Images() {
        // background image texture
        sf::Texture welcomeImageTexture;
        welcomeImage.loadFromFile("Images/chessImage4.jpg");

        // chess board sprite
        sf::Texture board;
        board.loadFromFile("Images/chessBoard.jpg");
        chessBoard.setTexture(board);
        // new size is 700x700. this makes it a square. 700 width leaves 200 pixels on each size, 700 height leaves 75 pixels on top and bottom
        sf::Vector2f chessBoardNewSize(700.0f, 700.0f);
        chessBoard.setScale(chessBoardNewSize.x / chessBoard.getLocalBounds().width, chessBoardNewSize.y / chessBoard.getLocalBounds().height);
    }
};