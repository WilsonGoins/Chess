#include <stdexcept>
#include "Knight.h"
using namespace std;

Knight::Knight(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 2;
    } else {
        value = -2;
    }
    this->row = row;
    this->col = col;
}

void Knight::MovePiece() {

}

vector<vector<int>> Knight::GetMoves(vector<vector<Piece*>>& board) {
    vector<vector<int>> currMoves(8);
    for (vector<int> row : currMoves) {
        row.resize(8, 0);
    }

    // black knight
    if (value == -2) {
        // 2 down, 1 left
        try {       // try block to handle out of range exceptions
            if (board.at(row + 2).at(col - 1)->GetValue() == 6) {
                currMoves.at(row + 2).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 2).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row + 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 2 down, 1 right
        try {
            if (board.at(row + 2).at(col + 1)->GetValue() == 6) {
                currMoves.at(row + 2).at(col + 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 2).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row + 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down, 2 right
        try {
            if (board.at(row + 1).at(col + 2)->GetValue() == 6) {
                currMoves.at(row + 1).at(col + 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col + 2)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 2 right
        try {
            if (board.at(row - 1).at(col + 2)->GetValue() == 6) {
                currMoves.at(row - 1).at(col + 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 1).at(col + 2)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 2 up, 1 right
        try {
            if (board.at(row - 2).at(col + 1)->GetValue() == 6) {
                currMoves.at(row - 2).at(col + 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 2).at(col + 1)->GetValue() >= 0) {
                currMoves.at(row - 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 2 up, 1 left
        try {
            if (board.at(row - 2).at(col - 1)->GetValue() == 6) {
                currMoves.at(row - 2).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 2).at(col - 1)->GetValue() >= 0) {
                currMoves.at(row - 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 2 left
        try {
            if (board.at(row - 1).at(col - 2)->GetValue() == 6) {
                currMoves.at(row - 1).at(col - 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 1).at(col - 2)->GetValue() >= 0) {
                currMoves.at(row - 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down, 2 left
        try {
            if (board.at(row + 1).at(col - 2)->GetValue() == 6) {
                currMoves.at(row + 1).at(col - 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col - 2)->GetValue() >= 0) {
                currMoves.at(row + 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
    }

    // white knight
    if (value == 2) {
        // 2 down, 1 left
        try {       // try block to handle out of range exceptions
            if (board.at(row + 2).at(col - 1)->GetValue() == -6) {
                currMoves.at(row + 2).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 2).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row + 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 2 down, 1 right
        try {
            if (board.at(row + 2).at(col + 1)->GetValue() == -6) {
                currMoves.at(row + 2).at(col + 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 2).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row + 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down, 2 right
        try {
            if (board.at(row + 1).at(col + 2)->GetValue() == -6) {
                currMoves.at(row + 1).at(col + 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col + 2)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 2 right
        try {
            if (board.at(row - 1).at(col + 2)->GetValue() == -6) {
                currMoves.at(row - 1).at(col + 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 1).at(col + 2)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 2 up, 1 right
        try {
            if (board.at(row - 2).at(col + 1)->GetValue() == -6) {
                currMoves.at(row - 2).at(col + 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 2).at(col + 1)->GetValue() <= 0) {
                currMoves.at(row - 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 2 up, 1 left
        try {
            if (board.at(row - 2).at(col - 1)->GetValue() == -6) {
                currMoves.at(row - 2).at(col - 1) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 2).at(col - 1)->GetValue() <= 0) {
                currMoves.at(row - 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 up, 2 left
        try {
            if (board.at(row - 1).at(col - 2)->GetValue() == -6) {
                currMoves.at(row - 1).at(col - 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row - 1).at(col - 2)->GetValue() <= 0) {
                currMoves.at(row - 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        // 1 down, 2 left
        try {
            if (board.at(row + 1).at(col - 2)->GetValue() == -6) {
                currMoves.at(row + 1).at(col - 2) = 2;      // make that spot a 2 to indicate it is check
            } else if (board.at(row + 1).at(col - 2)->GetValue() <= 0) {
                currMoves.at(row + 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
    } return currMoves;
}

int Knight::GetValue() {
    return value;
}
