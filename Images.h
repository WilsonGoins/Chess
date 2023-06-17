#pragma once
#include "SFML/Graphics.hpp"
using namespace std;

class Images {
public:
    string directory = "Images/Classic/";
    map<string, sf::FloatRect> globalBounds;
    sf::Texture welcomeImage;
    sf::Texture endBorder;
    sf::Texture chessBoard;
    sf::Texture wPawn;
    sf::Texture bPawn;
    sf::Texture wKnight;
    sf::Texture bKnight;
    sf::Texture wBishop;
    sf::Texture bBishop;
    sf::Texture wQueen;
    sf::Texture bQueen;
    sf::Texture wCastle;
    sf::Texture bCastle;
    sf::Texture wKing;
    sf::Texture bKing;
    sf::Texture crownTexture;
    sf::Texture surrenderFlag;
    sf::Texture restartButton;
    sf::Texture exitGame;

    Images() {
        // background image texture
        welcomeImage.loadFromFile("Images/Classic/chessImage5.jpg");

        // end border screen base
        endBorder.loadFromFile("Images/Classic/endBorder.PNG");

        // chess board texture
        chessBoard.loadFromFile(directory + "chessBoard.PNG");

        // white pawn
        wPawn.loadFromFile(directory + "wPawn.PNG");

        // black pawn
        bPawn.loadFromFile(directory + "bPawn.PNG");

        // white knight
        wKnight.loadFromFile(directory + "wKnight.PNG");

        // black knight
        bKnight.loadFromFile(directory + "bKnight.PNG");

        // white bishop
        wBishop.loadFromFile(directory + "wBishop.PNG");

        // black bishop
        bBishop.loadFromFile(directory + "bBishop.PNG");

        // white castle
        wCastle.loadFromFile(directory + "wCastle.PNG");

        // black castle
        bCastle.loadFromFile(directory + "bCastle.PNG");

        // white queen
        wQueen.loadFromFile(directory + "wQueen.PNG");

        // black queen
        bQueen.loadFromFile(directory + "bQueen.PNG");

        // white king
        wKing.loadFromFile(directory + "wKing.PNG");

        // black king
        bKing.loadFromFile(directory + "bKing.PNG");

        // crown
        crownTexture.loadFromFile("Images/Classic/crown.PNG");

        // surrender flag
        surrenderFlag.loadFromFile("Images/Classic/surrenderFlag.PNG");

        // restart button
        restartButton.loadFromFile("Images/Classic/restartButton.PNG");

        // exit button
        exitGame.loadFromFile("Images/Classic/exitGame.PNG");
    }

    void ChangeDirectory() {
        if (directory == "Images/Classic/") {       // change from classic to animated
            directory = "Images/Animated/";
        } else if (directory == "Images/Animated/") {       // change from animated to classic
            directory = "Images/Classic/";
        }
    }
};