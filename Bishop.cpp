#include "Bishop.h"
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
    vector<vector<int>> currMoves(8);       // make a vector of vectors to return later
    for (vector<int> row : currMoves) {
        row.resize(8, 0);           // initialize each element of the vector to 0
    }

    // black bishop
    if (value == -3) {
        // get moves diagonal up and right
        int tempRow1 = row;     // temporary row to find moves
        int tempCol1 = col;     // temporary column to find moves
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() == 0) {     // if spot is a 0 (empty)
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;     // go another row up
                    tempCol1++;     // go another column right
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() ==6) {      // if the spot is a 6 (white king)
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 2;      // make that spot a 2 to indicate it is check
                    break;      // exit while loop because we have hit a piece
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() >0) {       // if the spot is any positive number (white piece)
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;      // exit while loop
                } else {            // else would be if it is a negative number, in which case we exit while loop as well
                    break;
                }
            }
        } catch (const out_of_range &e) {}       // catch out of range exceptions if we try to access a square that is off the board
        // get moves diagonal up and left
        int tempRow2 = row;
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == 0) {     // if spot is empty
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2--;     // go another row up
                    tempCol2--;     // go another column left
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == 6) {      // if the spot is white king
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() > 0) {       // if it is any white piece
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // if it is a black piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and right
        int tempRow3 = row;
        int tempCol3 = col;
        try {
            while (true) {
                if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == 0) {     // if empty
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow3++;     // go down again
                    tempCol3++;     // go right again
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == 6) {      // if white king
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 2;      // make that spot a 2 to indicate it is a valid move
                    break;      // exit while loop
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() > 0) {       // if any white piece
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;
                    break;
                } else {        // if black piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and left
        int tempRow4 = row;
        int tempCol4 = col;
        try {
            while (true) {
                if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == 0) {     // empty
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4++;
                    tempCol4--;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == 6) {      // white king
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() > 0) {       // any white piece
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // black piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    }

    // white bishop
    if (value == 3) {
        // get moves diagonal up and right
        int tempRow1 = row;
        int tempCol1 = col;
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() == 0) {     // if empty spot
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                    tempCol1++;
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() == -6) {     // black king
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() < 0) {       // any black piece
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // any white piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal up and left
        int tempRow2 = row;
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == 0) {     // empty
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2--;
                    tempCol2--;
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == -6) {     // black king
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() < 0) {   // black piece
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // white piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and right
        int tempRow3 = row;
        int tempCol3 = col;
        try {
            while (true) {
                if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == 0) {
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow3++;
                    tempCol3++;
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == -6) {
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() < 0) {
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and left
        int tempRow4 = row;
        int tempCol4 = col;
        try {
            while (true) {
                if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == 0) {
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4++;
                    tempCol4--;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == -6) {
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() < 0) {
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    } return currMoves;         // return the list of all moves, 1 is a valid move, 0 is not a valid move, 2 is check
}

int Bishop::GetValue() {
    return value;
}
