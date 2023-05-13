#pragma once
#include <vector>
using namespace std;
#include "Piece.h"

class Castle : public Piece {
public:
    int value;
    bool hasMoved;
    int row;
    int col;
    vector<vector<int>> currMoves;

    Castle(bool isWhite, int row, int col);
    void MovePiece() override;      // move the piece
    void GetMoves() override;       // get all available moves
    int GetValue() override;
};