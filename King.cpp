#include "King.h"
#include <stdexcept>
using namespace std;

King::King(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 6;
    } else {
        value = -6;
    }
    this->row = row;
    this->col = col;
}

void King::MovePiece() {

}

vector<vector<int>> King::GetMoves(vector<vector<Piece*>>& board) {
    vector<vector<int>> currMoves(8);
    for (vector<int> row : currMoves) {
        row.resize(8, 0);
    }

    // black king
    if (value == -6) {
        // 1 down, 1 left
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col - 1)->GetValue() == 6) {
                currMoves.at(row + 1).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down
        try {
            if (board.at(row + 1).at(col)->GetValue() == 6) {
                currMoves.at(row + 1).at(col) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down, 1 right
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == 6) {
                currMoves.at(row + 1).at(col + 1) = 2;                      // put 2, meaning it is check
            } else if (board.at(row + 1).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 right
        try {
            if (board.at(row).at(col + 1)->GetValue() == 6) {
                currMoves.at(row).at(col + 1) = 2;                      // it is check
            } else if (board.at(row).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 1 right
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() == 6) {
                currMoves.at(row - 1).at(col + 1) = 2;                      // it is check
            } else if (board.at(row - 1).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up
        try {
            if (board.at(row - 1).at(col)->GetValue() == 6) {
                currMoves.at(row - 1).at(col) = 2;                      // it is check
            } else if (board.at(row - 1).at(col)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 1 left
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() == 6) {
                currMoves.at(row - 1).at(col - 1) = 2;                      // it is check
            } else if (board.at(row - 1).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 left
        try {
            if (board.at(row).at(col - 1)->GetValue() == 6) {
                currMoves.at(row).at(col - 1) = 2;                      // it is check
            } else if (board.at(row).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
    }

    // white king
    if (value == 6) {
        // 1 down, 1 left
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col - 1)->GetValue() == -6) {
                currMoves.at(row + 1).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down
        try {
            if (board.at(row + 1).at(col)->GetValue() == -6) {
                currMoves.at(row + 1).at(col) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down, 1 right
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == -6) {
                currMoves.at(row + 1).at(col + 1) = 2;                      // it is check
            } else if (board.at(row + 1).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 right
        try {
            if (board.at(row).at(col + 1)->GetValue() == -6) {
                currMoves.at(row).at(col + 1) = 2;                      // it is check
            } else if (board.at(row).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 1 right
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() == -6) {
                currMoves.at(row - 1).at(col + 1) = 2;                      // it is check
            } else if (board.at(row - 1).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up
        try {
            if (board.at(row - 1).at(col)->GetValue() == -6) {
                currMoves.at(row - 1).at(col) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 1 left
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() == -6) {
                currMoves.at(row - 1).at(col - 1) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 left
        try {
            if (board.at(row).at(col - 1)->GetValue() == -6) {
                currMoves.at(row).at(col - 1) = 2;                      // it is check
            } else if (board.at(row).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
    } return currMoves;
}

int King::GetValue() {
    return value;
}
