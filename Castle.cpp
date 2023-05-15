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
    vector<vector<int>> currMoves(8);
    for (vector<int> row : currMoves) {
        row.resize(8, 0);
    }

    // black pieces
    if (value == -4) {
        // get moves up
        int tempRow1 = row;
        while (true) {
            try {
                if (board.at(tempRow1 - 1).at(col)->GetValue() == 0) {
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() == 6){
                    currMoves.at(tempRow1 - 1).at(col) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() > 0) {
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves down
        int tempRow2 = row;
        while (true) {
            try {
                if (board.at(tempRow2 + 1).at(col)->GetValue() == 0) {
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2++;
                } else if (board.at(tempRow1 + 1).at(col)->GetValue() == 6){
                    currMoves.at(tempRow1 + 1).at(col) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow1 + 1).at(col)->GetValue() > 0) {
                    currMoves.at(tempRow1 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves left
        int tempCol1 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol1 - 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1--;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() == 6){
                    currMoves.at(row).at(tempCol1 - 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() > 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves right
        int tempCol2 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol2 + 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1++;
                } else if (board.at(row).at(tempCol1 + 1)->GetValue() == 6){
                    currMoves.at(row).at(tempCol1 + 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(row).at(tempCol1 + 1)->GetValue() > 0) {
                    currMoves.at(row).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
    }

    // white pieces
    if (value == 4) {
        // get moves up
        int tempRow1 = row;
        while (true) {
            try {
                if (board.at(tempRow1 - 1).at(col)->GetValue() == 0) {
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() == -6){
                    currMoves.at(tempRow1 - 1).at(col) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() < 0) {
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves down
        int tempRow2 = row;
        while (true) {
            try {
                if (board.at(tempRow2 + 1).at(col)->GetValue() == 0) {
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2++;
                } else if (board.at(tempRow1 + 1).at(col)->GetValue() == -6){
                    currMoves.at(tempRow1 + 1).at(col) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow1 + 1).at(col)->GetValue() < 0) {
                    currMoves.at(tempRow1 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves left
        int tempCol1 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol1 - 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1--;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() == -6){
                    currMoves.at(row).at(tempCol1 - 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() < 0) {
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves right
        int tempCol2 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol2 + 1)->GetValue() == 0) {
                    currMoves.at(row).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1++;
                } else if (board.at(row).at(tempCol1 + 1)->GetValue() == -6){
                    currMoves.at(row).at(tempCol1 + 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(row).at(tempCol1 + 1)->GetValue() < 0) {
                    currMoves.at(row).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
    } return currMoves;
}

int Castle::GetValue() {
    return value;
}
