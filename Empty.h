#pragma once
#include "Piece.h"
using namespace std;

class Empty : public Piece {
public:
    int value;
    int row;
    int col;
    int numMoves = 0;

    Empty(int row, int col) {
        value = 0;
        this->row = row;
        this->col = col;
    }
    int GetValue() override {
        return value;
    }
    void MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) override {}
    sf::Sprite DrawPiece(sf::RenderWindow& window, Images& textures) override {sf::Sprite sprite; return sprite;};
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, int lastMove) override {
        vector<vector<int>> currMoves;      // vector of moves to return
        currMoves.resize(8);            // make it 2d
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                currMoves.at(j).push_back(0);       // initialize each value to 0
            }
        }
        return currMoves;
    }
    int GetNumMoves() override {return numMoves;}
};