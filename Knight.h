#include "Piece.h"
#pragma once

class Knight : public Piece {
public:
    int value;
    int row;
    int col;
    vector<vector<int>> currMoves;

    Knight(bool isWhite, int row, int col);
    void MovePiece() override;      // move the piece
    void GetMoves() override;       // get all available moves
    int GetValue() const;
};