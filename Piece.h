#pragma once
#include <vector>
#include "Empty.h"

using namespace std;

class Piece {
public:
    virtual void MovePiece() = 0;
    virtual void GetMoves(vector<vector<Piece*>>& board) = 0;
    virtual int GetValue() = 0;
//    bool CheckKingSafety(const vector<vector<Piece*>>& board, int fromRow, int fromCol, int toRow, int toCol) {
//        vector<vector<Piece*>> newBoard = board;        // make a temporary copy of the board
//        newBoard.at(toRow).at(toCol) = board.at(fromRow).at(fromCol);       // put the piece we are moving in that spot
//        newBoard.at(fromRow).at(fromCol) = Empty(fromRow, fromCol);
//
//    }
    virtual ~Piece() = default;
};