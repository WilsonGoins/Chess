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

void Knight::GetMoves(vector<vector<Piece*>>& board) {
    if (value == -2) {      // for a black knight
        try {       // try block to handle out of range exceptions
            if (board.at(row + 2).at(col - 1)->GetValue() >= 0) {     // 2 down, 1 left
                currMoves.at(row + 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 2).at(col + 1)->GetValue() >= 0) {     // 2 down, 1 right
                currMoves.at(row + 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 2)->GetValue() >= 0) {      // 1 down, 2 right
                currMoves.at(row + 1).at(col + 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col + 2)->GetValue() >= 0) {      // 1 up, 2 right
                currMoves.at(row - 1).at(col + 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 2).at(col + 1)->GetValue() >= 0) {      // 2 up, 1 right
                currMoves.at(row - 2).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 2).at(col - 1)->GetValue() >= 0) {      // 2 up, 1 left
                currMoves.at(row - 2).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col - 2)->GetValue() >= 0) {      // 1 up, 2 left
                currMoves.at(row - 1).at(col - 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col - 2)->GetValue() >= 0) {      // 1 down, 2 left
                currMoves.at(row + 1).at(col - 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
    }
    if (value == 2) {      // for a white knight
        try {       // try block to handle out of range exceptions
            if (board.at(row + 2).at(col - 1)->GetValue() <= 0) {     // 2 up, 1 left
                currMoves.at(row + 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 2).at(col + 1)->GetValue() <= 0) {     // 2 up, 1 right
                currMoves.at(row + 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col + 2)->GetValue() <= 0) {      // 1 up, 2 right
                currMoves.at(row + 1).at(col + 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col + 2)->GetValue() <= 0) {      // 1 down, 2 right
                currMoves.at(row - 1).at(col + 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 2).at(col + 1)->GetValue() <= 0) {      // 2 down, 1 right
                currMoves.at(row - 2).at(col + 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 2).at(col - 1)->GetValue() <= 0) {      // 2 down, 1 left
                currMoves.at(row - 2).at(col - 1) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row - 1).at(col - 2)->GetValue() <= 0) {      // 1 down, 2 left
                currMoves.at(row - 1).at(col - 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
        try {
            if (board.at(row + 1).at(col - 2)->GetValue() <= 0) {      // 1 up, 2 left
                currMoves.at(row + 1).at(col - 2) = 1;                      // it is valid
            }
        } catch (const out_of_range &e) {}
    }
}

int Knight::GetValue() {
    return value;
}
