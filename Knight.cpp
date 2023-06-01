#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Knight.h"
#include "Empty.h"

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

void Knight::MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) {
    board.at(toRow).at(toCol) = board.at(row).at(col);          // make the to-spot the knight
    board.at(row).at(col) = new Empty(row, col);                        // make knight's curr spot empty
    row = toRow;    // update row
    col = toCol;    // update col
}

vector<vector<int>> Knight::GetMoves(vector<vector<Piece*>>& board, int lastMove) {
    vector<vector<int>> currMoves;      // vector of moves to return
    currMoves.resize(8);            // make it 2d
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);       // initialize each value to 0
        }
    }

    // black knight
    if (value == -2) {
        // 2 up, 1 left
        try {
            if (board.at(row - 2).at(col - 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 2).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row - 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 2 up, 1 right
        try {
            if (board.at(row - 2).at(col + 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 2).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row - 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up, 2 right
        try {
            if (board.at(row - 1).at(col + 2)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col + 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board
        
        // 1 down, 2 right
        try {
            if (board.at(row + 1).at(col + 2)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col + 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 2 down, 1 right
        try {
            if (board.at(row + 2).at(col + 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 2).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 2 down, 1 left
        try {
            if (board.at(row + 2).at(col - 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 2).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down, 2 left
        try {
            if (board.at(row + 1).at(col - 2)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col - 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up, 2 left
        try {
            if (board.at(row - 1).at(col - 2)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col - 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board
    }

    // white knight
    if (value == 2) {
        // 2 up, 1 left
        try {
            if (board.at(row - 2).at(col - 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 2).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 2 up, 1 right
        try {
            if (board.at(row - 2).at(col + 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 2).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up, 2 right
        try {
            if (board.at(row - 1).at(col + 2)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col + 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down, 2 right
        try {
            if (board.at(row + 1).at(col + 2)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col + 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col + 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 2 down, 1 right
        try {
            if (board.at(row + 2).at(col + 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 2).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row + 2).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 2 down, 1 left
        try {
            if (board.at(row + 2).at(col - 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 2).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row + 2).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down, 2 left
        try {
            if (board.at(row + 1).at(col - 2)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col - 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up, 2 left
        try {
            if (board.at(row - 1).at(col - 2)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col - 2) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col - 2) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board
    } return currMoves;
}

int Knight::GetValue() {
    return value;
}

sf::Sprite Knight::DrawPiece(sf::RenderWindow& window, Images& textures) {
    sf::Sprite sprite;
    if (value == -2) {
        sprite.setTexture(textures.bKnight);
    } else if (value == 2) {
        sprite.setTexture(textures.wKnight);
    }
    sf::Vector2f newSize(66.0f, 66.0f);
    sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(200.0f + (static_cast<float>(col) * 88.0f) + 44, 75.0f + (static_cast<float>(row) * 88.0f) + 44);
    return sprite;
    //window.draw(sprite);
}
