#include "Bishop.h"
using namespace std;

Bishop::Bishop(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 3;
    } else {
        value = -3;
    }
    this->row = row;
    this->col = col;
}

void Bishop::MovePiece() {

}

void Bishop::GetMoves() {

}

int Bishop::GetValue() {
    return value;
}
