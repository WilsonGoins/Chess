#pragma once
#include "SFML/Graphics.hpp"
using namespace std;

class Images {
public:
    string directory = "Images/Classic/";
    map<string, sf::FloatRect> globalBounds;
    sf::Texture welcomeImage;
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

    Images() {
        // background image texture
        welcomeImage.loadFromFile("Images/chessImage4.jpg");

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
    }

    void ChangeDirectory() {
        if (directory == "Images/Classic/") {       // change from classic to animated
            directory = "Images/Animated/";
        } else if (directory == "Images/Animated/") {       // change from animated to classic
            directory = "Images/Classic/";
        }
    }
};