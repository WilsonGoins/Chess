#include "Knight.h"
using namespace std;

Knight::Knight(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 2;
    } else {
        value = -2;
    }
    this->row = row;
    this->col = col;
}

void Knight::MovePiece() {

}

void Knight::GetMoves() {

}

int Knight::GetValue() const {
    return value;
}
