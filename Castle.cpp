#include <iostream>
#include "Castle.h"
using namespace std;

Castle::Castle(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 4;
    } else {
        value = -4;
    }
    hasMoved = false;
    this->row = row;
    this->col = col;
}

void Castle::MovePiece() {
    cout << "moving castle..." << endl;
}

void Castle::GetMoves() {

}

int Castle::GetValue() {
    return value;
}
