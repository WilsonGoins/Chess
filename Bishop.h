#include "Piece.h"
#include <vector>
using namespace std;
#pragma once

class Bishop : public Piece {           // bishop class that inherits from piece
public:
    int value;      // the piece's value, 3 or -3
    int row;        // its row position
    int col;        // its column position

    Bishop(bool isWhite, int row, int col);         // constructor
    void MovePiece() override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, bool checkForKing) override;       // get all available moves
    int GetValue() override;        // get the pieces value
};