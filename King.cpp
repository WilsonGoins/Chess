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

void King::GetMoves(vector<vector<Piece*>>& board) {
    if (value == -6) {      // for a black knight
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col - 1)->GetValue() >= 0) {     // 1 up, 1 left
                currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col)->GetValue() >= 0) {     // 1 up
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() >= 0) {      // 1 up, 1 right
                currMoves.at(row + 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col + 1)->GetValue() >= 0) {      // 1 right
                currMoves.at(row).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() >= 0) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col)->GetValue() >= 0) {      // 1 down
                currMoves.at(row - 1).at(col) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() >= 0) {      // 1 down, 1 left
                currMoves.at(row - 1).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col - 1)->GetValue() >= 0) {      // 1 left
                currMoves.at(row).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
    }

    // white king
    if (value == -6) {      // for a black knight
        try {       // try block to handle out of range exceptions
            if (board.at(row + 1).at(col - 1)->GetValue() <= 0) {     // 1 up, 1 left
                currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col)->GetValue() <= 0) {     // 1 up
                currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() <= 0) {      // 1 up, 1 right
                currMoves.at(row + 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col + 1)->GetValue() <= 0) {      // 1 right
                currMoves.at(row).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() <= 0) {      // 1 down, 1 right
                currMoves.at(row - 1).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col)->GetValue() <= 0) {      // 1 down
                currMoves.at(row - 1).at(col) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() <= 0) {      // 1 down, 1 left
                currMoves.at(row - 1).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row).at(col - 1)->GetValue() <= 0) {      // 1 left
                currMoves.at(row).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
    }
}

int King::GetValue() {
    return value;
}
