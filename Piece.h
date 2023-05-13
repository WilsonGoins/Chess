#pragma once

class Piece {
public:
    virtual void MovePiece() = 0;
    virtual void GetMoves() = 0;
    virtual int GetValue() = 0;
    virtual ~Piece() = default;
};