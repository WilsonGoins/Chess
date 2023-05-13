#include "Piece.h"
#include <vector>
using namespace std;
#pragma once

class Bishop : public Piece {
public:
    int value;
    int row;
    int col;
    vector<vector<int>> currMoves;

    Bishop(bool isWhite, int row, int col);
    void MovePiece() override;      // move the piece
    void GetMoves(vector<vector<Piece*>>& board) override;       // get all available moves
    int GetValue() override;
};