#include "Piece.h"
#include <vector>
using namespace std;
#pragma once

class Queen : public Piece {
public:
    int value;
    int row;
    int col;
    int numMoves = 0;

    Queen(bool isWhite, int row, int col);
    void MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board) override;       // get all available moves
    int GetValue() override;
};