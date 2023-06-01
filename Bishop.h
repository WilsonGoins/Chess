#include "Piece.h"
#include "Images.h"
#include <vector>
using namespace std;
#pragma once

class Bishop : public Piece {           // bishop class that inherits from piece
public:
    int value;      // the piece's value, 3 or -3
    int row;        // its row position
    int col;        // its column position
    int numMoves = 0;

    Bishop(bool isWhite, int row, int col);         // constructor
    void MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) override;      // move the piece
    vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, int lastMove) override;       // get all available moves
    sf::Sprite DrawPiece(sf::RenderWindow& window, Images& textures) override;
    int GetValue() override;        // get the pieces value
    int GetNumMoves() override {return numMoves;}
};