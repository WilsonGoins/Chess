#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Castle.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Empty.h"

Board::Board() {
    gameOver = false;

    board.resize(8);        // resize the outer vector of board to a size of 8

    // make pawns
    for (int i = 0; i < 8; i++) {       // make black pawns in the 2nd row
        board.at(1).push_back(new Pawn(false, 1, i));
    }

    for (int i = 0; i < 8; i++) {       // make white pawns in the 7th row
        board.at(6).push_back(new Pawn(true, 6, i));
    }

    // make 1st row (black pieces)
    board.at(0).push_back(new Castle(false, 0, 0));
    board.at(0).push_back(new Knight(false, 0, 1));
    board.at(0).push_back(new Bishop(false, 0, 2));
    board.at(0).push_back(new Queen(false, 0, 3));
    board.at(0).push_back(new King(false, 0, 4));
    board.at(0).push_back(new Bishop(false, 0, 5));
    board.at(0).push_back(new Knight(false, 0, 6));
    board.at(0).push_back(new Castle(false, 0, 7));

    // make 8th row (white pieces)
    board.at(7).push_back(new Castle(true, 7, 0));
    board.at(7).push_back(new Knight(true, 7, 1));
    board.at(7).push_back(new Bishop(true, 7, 2));
    board.at(7).push_back(new Queen(true, 7, 3));
    board.at(7).push_back(new King(true, 7, 4));
    board.at(7).push_back(new Bishop(true, 7, 5));
    board.at(7).push_back(new Knight(true, 7, 6));
    board.at(7).push_back(new Castle(true, 7, 7));

    for (int i = 2; i < 6; i++) {     // make rows 3 - 6 (empty squares)
        for (int j = 0; j < 8; j++) {
            board.at(i).push_back(new Empty(i, j));
        }
    }
}

bool Board::CheckKingSafety(int fromRow, int fromCol, int toRow, int toCol) const {
    vector<vector<Piece*>> newBoard = board;        // make a copy of the board
    newBoard.at(toRow).at(toCol) = board.at(fromRow).at(fromCol);       // put the piece to be moved in new spot
    newBoard.at(fromRow).at(fromCol) = new Empty(fromRow, fromCol);         // make the old spot empty

    // if piece to be moved is black
    if (board.at(fromRow).at(fromCol)->GetValue() < 0) {
        // go through every piece of the opposite color
        for (const vector<Piece*>& row: newBoard) {        // go through every row
            for (Piece* piece: row) {                          // for every piece
                if (piece->GetValue() > 0) {                              // if it is the opposite color (white)
                    vector<vector<int>> moves = piece->GetMoves(newBoard, false);       // get the moves for that piece (don't need to check for self check)
                    for (const vector<int>& rows : moves) {         // each row in moves
                        for (int move : rows) {                     // each move
                            if (move == 2) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    // if piece to be moved is white
    if (board.at(fromRow).at(fromCol)->GetValue() < 0) {
        // go through every black piece
        for (const vector<Piece *> &row: newBoard) {        // go through every row
            for (Piece *piece: row) {                          // for every piece
                if (piece->GetValue() < 0) {                              // if it is the opposite color (black)
                    vector<vector<int>> moves = piece->GetMoves(newBoard,false);       // get the moves for that piece (don't need to check for self check)
                    for (const vector<int> &rows: moves) {         // each row in moves
                        for (int move: rows) {                     // each move
                            if (move == 2) {            // if the move is a 2 it is a check on the king
                                return false;               // so the move is not valid and we return false
                            }
                        }
                    }
                }
            }
        }
    }
    return true;        // if none of the opposite colored pieces are checking the king, return true (the king is safe)
}
