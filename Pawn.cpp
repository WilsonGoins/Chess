#include <iostream>
using namespace std;
#include "Pawn.h"

Pawn::Pawn(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 1;
    } else {
        value = -1;
    }
    hasMoved = false;
    this->row = row;
    this->col = col;

}

void Pawn::MovePiece() {
    cout << "moving pawn..." << endl;
}

void Pawn::GetMoves() {
    ;
}

void Pawn::Promote() {
    ;
}

int Pawn::GetValue() const {
    return value;
}
