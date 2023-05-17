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

    Pawn(bool isWhite, int row, int col);
    void MovePiece() override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, bool checkForKing) override;       // get all available moves
    int GetValue() override;
    void Promote();
};