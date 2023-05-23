#pragma once
#include "Piece.h"
#include "SFML/Graphics.hpp"
#include "Images.h"
#include <vector>
using namespace std;

class Board {
public:
    bool gameOver;          // if the game is over or not
    Images textures;
    string userName1 = "none";
    string userName2 = "none";
    bool user1IsWhite = true;
    vector<vector<Piece*>> board;       // 2d vector to represent the board

    int CheckForEnd(bool isWhite);            // checks for mate or stalemate. returns -1 if mate, 0, if stalemated, 1 if play continues
    int CheckForPromote(bool isWhite);        // check if a pawn is at the end of the board, if so returns the column of that pawn, if not returns -1
    Board();        // board constructor
    ~Board() = default;
};
