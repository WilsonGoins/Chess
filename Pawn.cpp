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

vector<vector<int>> Pawn::GetMoves(vector<vector<Piece*>>& board, bool checkForKing) {
    vector<vector<int>> currMoves;      // vector of moves to return
    currMoves.resize(8);            // make it 2d
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);       // initialize each value to 0
        }
    }

    // black pawn
    if (value == -1) {
        // check for 1 up
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col)->GetValue() == 0) {     // if the space in front of the pawn is empty
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    }
                } else {        // if we don't care about king's safety
                    currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
                // if we can move one up, maybe we can move 2 up
                if (not hasMoved) {     // if pawn hasn't moved yet
                    if (board.at(row + 2).at(col)->GetValue() == 0) {     // if the space 2 in front of the pawn is empty
                        if (checkForKing) {     // if we are told to check for king
                            vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                            newBoard.at(row + 2).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                            newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                            if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                                currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                            }
                        } else {        // if we don't care about king
                            currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                        }
                    }
                }
            }
        } catch (const out_of_range &e) {}
        // 1 down, 1 left
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() == 6) {      // if the spot diagonal left is a white piece
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
                    }
                } else {
                    currMoves.at(row + 1).at(col - 1) = 2;                      // it is check
                }
            } else if (board.at(row + 1).at(col - 1)->GetValue() > 0) {
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is valid
                    }
                } else {
                    currMoves.at(row + 1).at(col - 1) = 1;                      // it is valid
                }
            }
        } catch (const out_of_range &e) {}
        // 1 down, 1 right
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == 6) {      // if the spot diagonal left is a white piece
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col + 1) = 2;      // make that spot a 2 to indicate it is check
                    }
                } else {
                    currMoves.at(row + 1).at(col + 1) = 2;                      // it is check
                }
            } else if (board.at(row + 1).at(col + 1)->GetValue() > 0) {
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is valid
                    }
                } else {
                    currMoves.at(row + 1).at(col + 1) = 1;                      // it is valid
                }
            }
        } catch (const out_of_range& e) {}
    }

    // moves for white pawns
    if (value == 1) {
        // check for 1 up
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col)->GetValue() == 0) {     // if the space in front of the pawn is empty
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    }
                } else {        // if we don't care about king's safety
                    currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
                // if we can move one up, maybe we can move 2 up
                if (not hasMoved) {     // if pawn hasn't moved yet
                    if (board.at(row + 2).at(col)->GetValue() == 0) {     // if the space 2 in front of the pawn is empty
                        if (checkForKing) {     // if we are told to check for king
                            vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                            newBoard.at(row + 2).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                            newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                            if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                                currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                            }
                        } else {        // if we don't care about king
                            currMoves.at(row + 2).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                        }
                    }
                }
            }
        } catch (const out_of_range &e) {}
        // 1 down, 1 left
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() == -6) {      // if the spot diagonal left is a white piece
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
                    }
                } else {
                    currMoves.at(row + 1).at(col - 1) = 2;                      // it is check
                }
            } else if (board.at(row + 1).at(col - 1)->GetValue() < 0) {
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is valid
                    }
                } else {
                    currMoves.at(row + 1).at(col - 1) = 1;                      // it is valid
                }
            }
        } catch (const out_of_range &e) {}
        // 1 down, 1 right
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == -6) {      // if the spot diagonal left is a white piece
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col + 1) = 2;      // make that spot a 2 to indicate it is check
                    }
                } else {
                    currMoves.at(row + 1).at(col + 1) = 2;                      // it is check
                }
            } else if (board.at(row + 1).at(col + 1)->GetValue() < 0) {
                if (checkForKing) {     // if we are told to check for king
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row + 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, row, col)) {  // if this move doesn't put our king in check
                        currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is valid
                    }
                } else {
                    currMoves.at(row + 1).at(col + 1) = 1;                      // it is valid
                }
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
