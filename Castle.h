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

    Castle(bool isWhite, int row, int col);
    void MovePiece() override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board) override;       // get all available moves
    int GetValue() override;
};