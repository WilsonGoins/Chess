#pragma once
#include "Piece.h"

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
    void GetMoves() override {}
};