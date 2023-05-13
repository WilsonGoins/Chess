#pragma once
#include "Piece.h"
using namespace std;

class Empty : public Piece {
public:
    int value;
    int row;
    int col;

    Empty(int row, int col) {
        value = 0;
        this->row = row;
        this->col = col;
    }
    int GetValue() override {
        return value;
    }
    void MovePiece() override {}
    void GetMoves(vector<vector<Piece*>>& board) override {}
};