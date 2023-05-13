#include "Queen.h"
#include <stdexcept>
using namespace std;

Queen::Queen(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 5;
    } else {
        value = -5;
    }
    this->row = row;
    this->col = col;
}

void Queen::MovePiece() {

}

void Queen::GetMoves(vector<vector<Piece*>>& board) {
    if (value == -5) {
        // get moves diagonal up and right
        int tempRow1 = row;
        int tempCol1 = col;
        while (true) {
            try {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() >= 0) {
                    currMoves.at(tempRow1 - 1).at(
                            tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
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
                    currMoves.at(tempRow2 - 1).at(
                            tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
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
                    currMoves.at(tempRow3 + 1).at(
                            tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
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
                    currMoves.at(tempRow4 + 1).at(
                            tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4++;
                    tempCol4--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves up
        int tempRow5 = row;
        while (true) {
            try {
                if (board.at(tempRow5 - 1).at(col)->GetValue() >= 0) {
                    currMoves.at(tempRow5 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow5--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves down
        int tempRow6 = row;
        while (true) {
            try {
                if (board.at(tempRow6 + 1).at(col)->GetValue() >= 0) {
                    currMoves.at(tempRow6 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow6++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves left
        int tempCol5 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol5 - 1)->GetValue() >= 0) {
                    currMoves.at(row).at(tempCol5 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol5--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves right
        int tempCol6 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol6 + 1)->GetValue() >= 0) {
                    currMoves.at(row).at(tempCol6 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol6++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
    }

    // white queen
    if (value == 5) {
        // get moves diagonal up and right
        int tempRow1 = row;
        int tempCol1 = col;
        while (true) {
            try {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() <= 0) {
                    currMoves.at(tempRow1 - 1).at(
                            tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
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
                    currMoves.at(tempRow2 - 1).at(
                            tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
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
                    currMoves.at(tempRow3 + 1).at(
                            tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
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
                    currMoves.at(tempRow4 + 1).at(
                            tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4++;
                    tempCol4--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves up
        int tempRow5 = row;
        while (true) {
            try {
                if (board.at(tempRow5 - 1).at(col)->GetValue() <= 0) {
                    currMoves.at(tempRow5 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow5--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves down
        int tempRow6 = row;
        while (true) {
            try {
                if (board.at(tempRow6 + 1).at(col)->GetValue() <= 0) {
                    currMoves.at(tempRow6 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow6++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves left
        int tempCol5 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol5 - 1)->GetValue() <= 0) {
                    currMoves.at(row).at(tempCol5 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol5--;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
        // get moves right
        int tempCol6 = col;
        while (true) {
            try {
                if (board.at(row).at(tempCol6 + 1)->GetValue() <= 0) {
                    currMoves.at(row).at(tempCol6 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol6++;
                } else {
                    break;
                }
            } catch (const out_of_range &e) {
                break;
            }
        }
    }
}

int Queen::GetValue() {
    return value;
}
