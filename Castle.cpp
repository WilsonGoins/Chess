#include <iostream>
#include "Castle.h"
#include <stdexcept>
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

vector<vector<int>> Castle::GetMoves(vector<vector<Piece*>>& board) {
    vector<vector<int>> currMoves(8);       // list of spots that we will return at end
    for (vector<int> row : currMoves) {
        row.resize(8, 0);
    }

    // black castle
    if (value == -4) {
        // get moves up
        int tempRow1 = row;
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(col)->GetValue() == 0) {      // if empty spot
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() == 6) {        // white king
                    currMoves.at(tempRow1 - 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() > 0) {        // white piece
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // black piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves down
        int tempRow2 = row;
        try {
            while (true) {
                if (board.at(tempRow2 + 1).at(col)->GetValue() == 0) {      // empty
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2++;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() == 6) {        // white king
                    currMoves.at(tempRow2 + 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() > 0) {        // any white piece
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // any black piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves left
        int tempCol1 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol1 - 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1--;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() == 6) {
                    currMoves.at(row).at(tempCol1 - 1) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() > 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves right
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol2 + 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1++;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() == 6) {
                    currMoves.at(row).at(tempCol2 + 1) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() > 0) {
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    }

    // white pieces
    if (value == 4) {
        // get moves up
        int tempRow1 = row;
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(col)->GetValue() == 0) {
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() == -6) {
                    currMoves.at(tempRow1 - 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() < 0) {
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves down
        int tempRow2 = row;
        try {
            while (true) {
                if (board.at(tempRow2 + 1).at(col)->GetValue() == 0) {
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2++;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() == -6) {
                    currMoves.at(tempRow2 + 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() < 0) {
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves left
        int tempCol1 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol1 - 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1--;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() == -6) {
                    currMoves.at(row).at(tempCol1 - 1) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() < 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves right
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol2 + 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1++;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() == -6) {
                    currMoves.at(row).at(tempCol2 + 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() < 0) {
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    } return currMoves;
}

int Castle::GetValue() {
    return value;
}
