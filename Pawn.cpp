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
}

void Pawn::MovePiece() {
    cout << "moving pawn..." << endl;
}

vector<vector<int>> Pawn::GetMoves(vector<vector<Piece*>>& board) {
    vector<vector<int>> currMoves(8);
    for (vector<int> row : currMoves) {
        row.resize(8, 0);
    }

    if (value == -1) {      // get moves for black pawn
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col)->GetValue() == 0) {     // if the space in front of the pawn is empty
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                try {
                    if (not hasMoved) {     // if pawn hasn't moved yet
                        if (board.at(row + 2).at(col)->GetValue() == 0) {     // if the space 2 in front of the pawn is empty
                            currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                        }
                    }
                } catch (const out_of_range &e) {}
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() == 6) {      // if the spot diagonal left is a white piece
                currMoves.at(row + 1).at(col - 1) = 2;                      // it is valid
            } else if (board.at(row + 1).at(col - 1)->GetValue() > 0) {
                currMoves.at(row + 1).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == 6) {      // if the spot diagonal left is a white piece
                currMoves.at(row + 1).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row + 1).at(col + 1)->GetValue() > 0) {
                currMoves.at(row + 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range& e) {}
    }

    // moves for white pawns
    if (value == -1) {      // get moves for black pawn
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col)->GetValue() == 0) {     // if the space in front of the pawn is empty
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                try {
                    if (not hasMoved) {     // if pawn hasn't moved yet
                        if (board.at(row + 2).at(col)->GetValue() == 0) {     // if the space 2 in front of the pawn is empty
                            currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                        }
                    }
                } catch (const out_of_range &e) {}
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() == -6) {      // if the spot diagonal left is a white piece
                currMoves.at(row + 1).at(col - 1) = 2;                      // it is valid
            } else if (board.at(row + 1).at(col - 1)->GetValue() < 0) {
                currMoves.at(row + 1).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == -6) {      // if the spot diagonal left is a white piece
                currMoves.at(row + 1).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row + 1).at(col + 1)->GetValue() < 0) {
                currMoves.at(row + 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range& e) {}
    } return currMoves;
}

void Pawn::Promote() {
    ;
}

int Pawn::GetValue() {
    return value;
}
