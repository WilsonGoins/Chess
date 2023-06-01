#include "King.h"
#include "Empty.h"
#include <stdexcept>
#include <SFML/Graphics.hpp>

using namespace std;

King::King(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 6;
    } else {
        value = -6;
    }
    this->row = row;
    this->col = col;
    numMoves = 0;
}

void King::MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) {
    numMoves++;
    int moveDist = toCol - col;
    if (abs(moveDist) == 2) {        // if the distance of the move is 2 (meaning it is a castling move...)
        if (moveDist < 0) {         // if the move is negative, then col > toCol. so, we are moving left, so it's a queenside castle
            board.at(row).at(toCol) = board.at(row).at(col);        // king is assigned to new space
            board.at(row).at(col) = new Empty(row, col);                  // king spot is made empty
            board.at(row).at(0)->MovePiece(board, row, col - 1);        // move the castle
            row = toRow;            // row is updated (this should be the same though)
            col = toCol;            // col is updated
        } else if (moveDist > 0) {
            board.at(row).at(toCol) = board.at(row).at(col);        // king is assigned to new space
            board.at(row).at(col) = new Empty(row, col);                    // king spot is made empty
            board.at(row).at(7)->MovePiece(board, row, col + 1);        // move the castle
            row = toRow;            // row is updated (this should be the same though)
            col = toCol;            // col is updated
        }
    } else {        // if it isn't a castling move, proceed as normal
        board.at(toRow).at(toCol) = board.at(row).at(col);          // make the to-spot the knight
        board.at(row).at(col) = new Empty(row, col);                        // make knight's curr spot empty
        row = toRow;    // update row
        col = toCol;    // update col
    }
}

vector<vector<int>> King::GetMoves(vector<vector<Piece*>>& board, int lastMove) {
    vector<vector<int>> currMoves;      // vector of moves to return
    currMoves.resize(8);            // make it 2d
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);       // initialize each value to 0
        }
    }

    // black king
    if (value == -6) {
        // 1 up, 1 left
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up
        try {
            if (board.at(row - 1).at(col)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up, 1 right
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 right
        try {
            if (board.at(row).at(col + 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down, 1 right
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down
        try {
            if (board.at(row + 1).at(col)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down, 1 left
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 left
        try {
            if (board.at(row).at(col - 1)->GetValue() >= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, false)) {  // if out king will still be safe
                    currMoves.at(row).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // castling
        if (CheckKingSafety(board, false)) {        // if we are not in check
            if (numMoves == 0) {         //  if the king has not moved yet
                // check if rooks have moved
                if (board.at(0).at(0)->GetNumMoves() == 0) {        // if the queenside castle hasn't moved yet
                    // if the spaces between the queenside castle and the king are empty
                    if ((board.at(0).at(1)->GetValue() == 0) and (board.at(0).at(2)->GetValue() == 0) and (board.at(0).at(3)->GetValue() == 0)) {
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(0).at(3) = board.at(row).at(col);       // move the king towards queenside castle one space
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (CheckKingSafety(newBoard, false)) {  // if our king will still be safe
                            vector<vector<Piece *>> newerBoard = board;        // make a copy of the board
                            newerBoard.at(0).at(2) = board.at(row).at(col);       // move the king towards queenside castle one space
                            newerBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                            if (CheckKingSafety(newerBoard, false)) {
                                currMoves.at(0).at(2) = 1;
                            }
                        }
                    }
                }
                if (board.at(0).at(7)->GetNumMoves() == 0) {     // if the kingside castle hasn't moved yet
                    // if the spaces between kingside castle and king are empty
                    if ((board.at(0).at(5)->GetValue() == 0) and (board.at(0).at(6)->GetValue() == 0)) {
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(0).at(5) = board.at(row).at(col);       // move the king towards queenside castle one space
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (CheckKingSafety(newBoard, false)) {  // if our king will still be safe
                            vector <vector<Piece *>> newerBoard = board;        // make a copy of the board
                            newerBoard.at(0).at(6) = board.at(row).at(col);       // move the king towards queenside castle one space
                            newerBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                            if (CheckKingSafety(newerBoard, false)) {
                                currMoves.at(0).at(6) = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    // white king
    if (value == 6) {
        // 1 up, 1 left
        try {
            if (board.at(row - 1).at(col - 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if our king will still be safe
                    currMoves.at(row - 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up
        try {
            if (board.at(row - 1).at(col)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 up, 1 right
        try {
            if (board.at(row - 1).at(col + 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row - 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row - 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 right
        try {
            if (board.at(row).at(col + 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down, 1 right
        try {
            if (board.at(row + 1).at(col + 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down
        try {
            if (board.at(row + 1).at(col)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 down, 1 left
        try {
            if (board.at(row + 1).at(col - 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row + 1).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row + 1).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // 1 left
        try {
            if (board.at(row).at(col - 1)->GetValue() <= 0) {       // if next piece value is empty or white
                vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                newBoard.at(row).at(col - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                if (CheckKingSafety(newBoard, true)) {  // if out king will still be safe
                    currMoves.at(row).at(col - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                }
            }
        } catch (const out_of_range &e) {}    // catch out of range exceptions if we try to access a square that is off the board

        // castling
        if (CheckKingSafety(board, true)) {        // if we are not in check
            if (numMoves == 0) {         //  if the king has not moved yet
                // check if rooks have moved
                if (board.at(7).at(0)->GetNumMoves() == 0) {        // if the queenside castle hasn't moved yet
                    // if the spaces between the queenside castle and the king are empty
                    if ((board.at(7).at(1)->GetValue() == 0) and (board.at(7).at(2)->GetValue() == 0) and (board.at(7).at(3)->GetValue() == 0)) {
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(7).at(3) = board.at(row).at(col);       // move the king towards queenside castle one space
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (CheckKingSafety(newBoard, true)) {  // if our king will still be safe
                            vector<vector<Piece *>> newerBoard = board;        // make a copy of the board
                            newerBoard.at(7).at(2) = board.at(row).at(col);       // move the king towards queenside castle one space
                            newerBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                            if (CheckKingSafety(newerBoard, true)) {
                                currMoves.at(7).at(2) = 1;
                            }
                        }
                    }
                }
                if (board.at(7).at(7)->GetNumMoves() == 0) {     // if the kingside castle hasn't moved yet
                    // if the spaces between kingside castle and king are empty
                    if ((board.at(7).at(5)->GetValue() == 0) and (board.at(7).at(6)->GetValue() == 0)) {
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(7).at(5) = board.at(row).at(col);       // move the king towards queenside castle one space
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (CheckKingSafety(newBoard, true)) {  // if our king will still be safe
                            vector<vector<Piece *>> newerBoard = board;        // make a copy of the board
                            newerBoard.at(7).at(6) = board.at(row).at(col);       // move the king towards queenside castle one space
                            newerBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                            if (CheckKingSafety(newerBoard, true)) {
                                currMoves.at(7).at(6) = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return currMoves;
}

int King::GetValue() {
    return value;
}

sf::Sprite King::DrawPiece(sf::RenderWindow& window, Images& textures) {
    sf::Sprite sprite;
    if (value == -6) {
        sprite.setTexture(textures.bKing);
    } else if (value == 6) {
        sprite.setTexture(textures.wKing);
    }
    sf::Vector2f newSize(66.0f, 66.0f);     // a little bit smaller than the size of a single tile (88x88)
    sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(200.0f + (static_cast<float>(col) * 88.0f) + 44, 75.0f + (static_cast<float>(row) * 88.0f) + 44);
    return sprite;
    //window.draw(sprite);
}
