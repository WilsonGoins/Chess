#include <iostream>
#include "Castle.h"
#include "Empty.h"
#include <stdexcept>
using namespace std;

Castle::Castle(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 4;
    } else {
        value = -4;
    }
    this->row = row;
    this->col = col;
}

void Castle::MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) {
    board.at(toRow).at(toCol) = board.at(row).at(col);          // make the to-spot the castle
    board.at(row).at(col) = new Empty(row, col);                        // make castle's curr spot empty
    row = toRow;    // update row
    col = toCol;    // update col
}

vector<vector<int>> Castle::GetMoves(vector<vector<Piece*>>& board) {
    vector<vector<int>> currMoves;      // vector of moves to return
    currMoves.resize(8);            // make it 2d
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);       // initialize each value to 0
        }
    }

    // black castle
    if (value == -4) {
        // get moves up
        int tempRow1 = row;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow1 - 1).at(col)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow1--;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {            // if it does put our king in check we don't add the move
                        tempRow1--;         // increment the row
                        continue;               // and continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves down
        int tempRow2 = row;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow2 + 1).at(col)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow1 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow2++;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {        // break if
                        tempRow2++;     // go another row up
                        continue;       // continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves left
        int tempCol1 = row;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(row).at(tempCol1 - 1)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempCol1--;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {            // if it does put our king in check we don't add the move
                        tempCol1--;         // increment the col
                        continue;               // and continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves right
        int tempCol2 = row;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(row).at(tempCol2 + 1)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(row).at(
                                tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempCol2++;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {            // if it does put our king in check we don't add the move
                        tempCol2++;         // increment the col
                        continue;               // and continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board
    }

    // white pieces
    if (value == 4) {
        // get moves up
        int tempRow1 = row;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow1 - 1).at(col)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                        currMoves.at(tempRow1 - 1).at(
                                col) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow1--;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {            // if it does put our king in check we don't add the move
                        tempRow1--;         // increment the row
                        continue;               // and continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves down
        int tempRow2 = row;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow2 + 1).at(col)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                        currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow2++;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {            // if it does put our king in check we don't add the move
                        tempRow2++;         // increment the row
                        continue;               // and continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves left
        int tempCol1 = col;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(row).at(tempCol1 - 1)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                        currMoves.at(row).at(
                                tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempCol1--;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {            // if it does put our king in check we don't add the move
                        tempCol1--;         // increment the col
                        continue;               // and continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves right
        int tempCol2 = col;     // temporary row to find moves
        try {
            while (true) {
                int nextPiece = board.at(row).at(tempCol2 + 1)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                        currMoves.at(row).at(
                                tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempCol2++;     // go another row up
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    } else {            // if it does put our king in check we don't add the move
                        tempCol2++;         // increment the col
                        continue;               // and continue
                    }
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board
    } return currMoves;
}

int Castle::GetValue() {
    return value;
}
