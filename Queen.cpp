#include "Queen.h"
using namespace std;

Queen::Queen(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 5;
    } else {
        value = -5;
    }
    this->row = row;
    this->col = col;
}

void Queen::MovePiece() {

}

void Queen::GetMoves() {

}

int Queen::GetValue() const {
    return value;
}
