#include "Bishop.h"
#include <stdexcept>
using namespace std;

Bishop::Bishop(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 3;
    } else {
        value = -3;
    }
    this->row = row;
    this->col = col;
}

void Bishop::MovePiece() {

}

void Bishop::GetMoves(vector<vector<Piece*>>& board) {
    if (value == -3) {
        // get moves diagonal up and right
        int tempRow1 = row;
        int tempCol1 = col;
        while (true) {
            try {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() >= 0) {
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                    tempCol1++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves diagonal up and left
        int tempRow2 = row;
        int tempCol2 = col;
        while (true) {
            try {
                if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() >= 0) {
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2--;
                    tempCol2--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves diagonal down and right
        int tempRow3 = row;
        int tempCol3 = col;
        while (true) {
            try {
                if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() >= 0) {
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow3++;
                    tempCol3++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves diagonal down and left
        int tempRow4 = row;
        int tempCol4 = col;
        while (true) {
            try {
                if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() >= 0) {
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4++;
                    tempCol4--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
    }

    // white pieces
    if (value == 3) {
        // get moves diagonal up and right
        int tempRow1 = row;
        int tempCol1 = col;
        while (true) {
            try {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() <= 0) {
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                    tempCol1++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves diagonal up and left
        int tempRow2 = row;
        int tempCol2 = col;
        while (true) {
            try {
                if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() <= 0) {
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2--;
                    tempCol2--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves diagonal down and right
        int tempRow3 = row;
        int tempCol3 = col;
        while (true) {
            try {
                if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() <= 0) {
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow3++;
                    tempCol3++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves diagonal down and left
        int tempRow4 = row;
        int tempCol4 = col;
        while (true) {
            try {
                if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() <= 0) {
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4++;
                    tempCol4--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
    }
}

int Bishop::GetValue() {
    return value;
}
