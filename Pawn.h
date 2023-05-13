#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class Pawn : public Piece {
public:
    int value;
    bool hasMoved;
    int row;
    int col;
    vector<vector<int>> currMoves;

    Pawn(bool isWhite, int row, int col);
    void MovePiece() override;      // move the piece
    void GetMoves() override;       // get all available moves
    int GetValue() const;
    void Promote();
};