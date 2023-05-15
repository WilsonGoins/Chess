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
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board) override {
        vector<vector<int>> res;
        res.resize(8);
        for (vector<int> row : res) {
            row.resize(8, 0);
        }
        return res;
    }
};