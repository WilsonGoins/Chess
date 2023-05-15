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

    if (value == -6) {      // for a black knight
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col - 1)->GetValue() == 6) {     // 1 down, 1 left
                currMoves.at(row + 1).at(col - 1) = 2;      // make that spot a 1 to indicate it is a valid move
            } else if (board.at(row + 1).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col)->GetValue() == 6) {     // 1 down
                currMoves.at(row + 1).at(col) = 2;      // make that spot a 1 to indicate it is a valid move
            } else if (board.at(row + 1).at(col)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == 6) {      // 1 down, 1 right
                currMoves.at(row + 1).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row + 1).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col + 1)->GetValue() == 6) {      // 1 down, 1 right
                currMoves.at(row).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() == 6) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col)->GetValue() == 6) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() == 6) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col - 1) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col - 1)->GetValue() == 6) {      // 1 down, 1 right
                currMoves.at(row).at(col - 1) = 2;                      // it is valid
            } else if (board.at(row).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
    }

    // white king
    if (value == 6) {      // for a black knight
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col - 1)->GetValue() == -6) {     // 1 down, 1 left
                currMoves.at(row + 1).at(col - 1) = 2;      // make that spot a 1 to indicate it is a valid move
            } else if (board.at(row + 1).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col)->GetValue() == -6) {     // 1 down
                currMoves.at(row + 1).at(col) = 2;      // make that spot a 1 to indicate it is a valid move
            } else if (board.at(row + 1).at(col)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() == -6) {      // 1 down, 1 right
                currMoves.at(row + 1).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row + 1).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col + 1)->GetValue() == -6) {      // 1 down, 1 right
                currMoves.at(row).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() == -6) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col + 1) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col)->GetValue() == -6) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() == -6) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col - 1) = 2;                      // it is valid
            } else if (board.at(row - 1).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col - 1)->GetValue() == -6) {      // 1 down, 1 right
                currMoves.at(row).at(col - 1) = 2;                      // it is valid
            } else if (board.at(row).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
    } return currMoves;
}

int King::GetValue() {
    return value;
}
