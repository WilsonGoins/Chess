#include <iostream>
#include "Pawn.h"
using namespace std;

Pawn::Pawn(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 1;
    } else {
        value = -1;
    }
    hasMoved = false;
    this->row = row;
    this->col = col;
    currMoves.resize(8);
    for (vector<int> rows : currMoves) {
        rows.resize(8, 0);      // make each spot a 0 to indicate it is an invalid move
    }

}

void Pawn::MovePiece() {
    cout << "moving pawn..." << endl;
}

void Pawn::GetMoves(vector<vector<Piece*>>& board) {
    if (value == -1) {      // get moves for black pawn
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col)->GetValue() == 0) {     // if the space in front of the pawn is empty
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (not hasMoved) {     // if pawn hasn't moved yet
                if (board.at(row + 2).at(col)->GetValue() == 0) {     // if the space 2 in front of the pawn is empty
                    currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() > 0) {      // if the spot diagonal left is a white piece
                currMoves.at(row + 1).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() > 0) {      // if the diagonal right is a white piece
                currMoves.at(row + 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range& e) {}
    }

    // moves for white pawns
    if (value == 1) {      // get moves for black pawn
        try {       // try block to handle out of range exceptions
            if (board.at(row - 1).at(col)->GetValue() == 0) {     // if the space in front of the pawn is empty
                currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (not hasMoved) {     // if pawn hasn't moved yet
                if (board.at(row - 2).at(col)->GetValue() == 0) {     // if the space 2 in front of the pawn is empty
                    currMoves.at(row - 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() < 0) {      // if the spot diagonal left is a black piece
                currMoves.at(row - 1).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() < 0) {      // if the diagonal right is a black piece
                currMoves.at(row - 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range& e) {}
    }
}

void Pawn::Promote() {
    ;
}

int Pawn::GetValue() {
    return value;
}
