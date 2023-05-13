#pragma once
#include "Board.h"

class Piece {
public:
    virtual void MovePiece() = 0;
    virtual void GetMoves() = 0;
    virtual ~Piece() = 0;
};