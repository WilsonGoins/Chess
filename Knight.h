#include "Piece.h"
#include <vector>
using namespace std;
#pragma once

class Knight : public Piece {
public:
    int value;
    int row;
    int col;

    Knight(bool isWhite, int row, int col);
    void MovePiece() override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board) override;       // get all available moves
    int GetValue() override;
};