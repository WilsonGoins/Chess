#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class Pawn : public Piece {
public:
    int value;
    int row;
    int col;
    int numMoves = 0;

    Pawn(bool isWhite, int row, int col);
    void MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board) override;       // get all available moves
    int GetValue() override;
    void Promote();
};