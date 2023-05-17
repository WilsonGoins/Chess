#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class Board {
public:
    bool gameOver;          // if the game is over or not

    vector<vector<Piece*>> board;       // 2d vector to represent the board
    Board();        // board constructor
    bool CheckKingSafety(int fromRow, int fromCol, int toRow, int toCol) const;
    ~Board() = default;
};
