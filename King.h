#include "Piece.h"
#include "Images.h"
#include <vector>
using namespace std;
#pragma once

class King : public Piece {
public:
    int value;
    int row;
    int col;
    int numMoves;

    King(bool isWhite, int row, int col);
    void MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, int lastMove) override;       // get all available moves
    sf::Sprite DrawPiece(sf::RenderWindow& window, Images& textures) override;
    int GetValue() override;
    int GetNumMoves() override {return numMoves;}
};