#include <iostream>
#include "Pawn.h"
#include "Empty.h"

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
    vector<vector<int>> currMoves;      // vector of moves to return
    currMoves.resize(8);            // make it 2d
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);       // initialize each value to 0
        }
    }

    // black pawn
    if (value == -1) {
        // 1 or 2 forward (down)
        try {
            if (board.at(row + 1).at(col)->GetValue() == 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
                // if we can go 1 forward, perhaps we can go 2 forward
                if (board.at(row + 2).at(col)->GetValue() == 0) {       // if next piece value is empty or white
                    vector<vector<Piece *>> newerBoard = board;        // make a copy of the board
                    newerBoard.at(row + 2).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newerBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newerBoard, false)) {  // if out king will still be safe
                        currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    }

                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 forward (down), 1 left
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() > 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}

        // 1 forward (down), 1 right
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() > 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}
    }

    // moves for white pawns
    if (value == 1) {
        // 1 or 2 forward (up)
        try {
            if (board.at(row - 1).at(col)->GetValue() == 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
                // if we can go 1 forward, perhaps we can go 2 forward
                if (board.at(row - 2).at(col)->GetValue() == 0) {       // if next piece value is empty or white
                    vector<vector<Piece *>> newerBoard = board;        // make a copy of the board
                    newerBoard.at(row - 2).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newerBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newerBoard, true)) {  // if out king will still be safe
                        currMoves.at(row - 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    }

                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 forward (down), 1 left
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() < 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}

        // 1 forward (down), 1 right
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() < 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}
    } return currMoves;
}

void Pawn::Promote() {
    ;
}

int Pawn::GetValue() {
    return value;
}
