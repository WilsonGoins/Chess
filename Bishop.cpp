#include "Bishop.h"
#include "Empty.h"
#include <stdexcept>
using namespace std;

Bishop::Bishop(bool isWhite, int row, int col) {        // constructor
    if (isWhite) {      // if the piece is white
        value = 3;          // set the value to 3
    } else {            // if the piece is black
        value = -3;         // set the value to -3
    }
    this->row = row;    // set the row to row
    this->col = col;    // set the column to column
}

void Bishop::MovePiece() {

}

vector<vector<int>> Bishop::GetMoves(vector<vector<Piece*>>& board) {
    vector<vector<int>> currMoves;      // vector of moves to return
    currMoves.resize(8);            // make it 2d
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);       // initialize each value to 0
        }
    }

    // black bishop
    if (value == -3) {
        // get moves diagonal up and right
        int tempRow1 = row;     // temporary row to find moves
        int tempCol1 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(
                            col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow1--;     // go another row up
                            tempCol1++;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (
                const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves diagonal up and left
        int tempRow2 = row;     // temporary row to find moves
        int tempCol2 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow2 - 1).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow1--;     // go another row up
                            tempCol1--;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (
                const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves diagonal down and right
        int tempRow3 = row;     // temporary row to find moves
        int tempCol3 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow3 - 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow3++;     // go another row up
                            tempCol3++;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (
                const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves diagonal up and left
        int tempRow4 = row;     // temporary row to find moves
        int tempCol4 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue();
                if (nextPiece >= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow4 + 1).at(tempCol4 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow4++;     // go another row up
                            tempCol4--;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (
                const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board
    }


    // white bishop
    if (value == 3) {
        // get moves diagonal up and right
        int tempRow1 = row;     // temporary row to find moves
        int tempCol1 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow1--;     // go another row up
                            tempCol1++;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (
                const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves diagonal up and left
        int tempRow2 = row;     // temporary row to find moves
        int tempCol2 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow2 - 1).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow1--;     // go another row up
                            tempCol1--;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (
                const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves diagonal down and right
        int tempRow3 = row;     // temporary row to find moves
        int tempCol3 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow3 - 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow3++;     // go another row up
                            tempCol3++;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (
                const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board

        // get moves diagonal up and left
        int tempRow4 = row;     // temporary row to find moves
        int tempCol4 = col;     // temporary column to find moves
        try {
            while (true) {
                int nextPiece = board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue();
                if (nextPiece <= 0) {     // if spot is a 0 or a white piece
                    vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                    newBoard.at(tempRow4 + 1).at(tempCol4 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                    newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                    if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                        currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                        if (nextPiece == 0) {       // if the spot is empty, continue
                            tempRow4++;     // go another row up
                            tempCol4--;     // go another column right
                            continue;       // restart while loop
                        } else {        // if the spot is a white piece
                            break;
                        }
                    }      // if it does put our king in check we just go back to while loop and check next spot
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board
    }
    return currMoves;         // return the list of all moves, 1 is a valid move, 0 is not a valid move
}

int Bishop::GetValue() {
    return value;
}
