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


    // ***DELETE PAWNS***
//    for (int i = 0; i < 8; i++) {       // delete black pawns in the 2nd row
//        board.at(1).push_back(new Empty(1, i));
//    }
//
//    for (int i = 0; i < 8; i++) {       // delete white pawns in the 7th row
//        board.at(6).push_back(new Empty(6, i));
//    }


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
