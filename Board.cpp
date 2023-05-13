#include "Board.h"
#include "Pawn.h"

Board::Board() {
    board.resize(8);        // make 8 rows
    for (vector<Piece*> col : board) {      // make 8 cols
        col.resize(8);
    }

    // make pawns
    for (int i = 0; i < 8; i++) {       // insert white pawns
        board.at(6).at(i) = new Pawn(true, 6, i);       // make a white pawn at row 6 column i
    }
    for (int i = 0; i < 8; i++) {       // insert black pawns
        board.at(1).at(i) = new Pawn(false, 1, i);       // make a black pawn at row 2 column i
    }

    // make castles
    board.at(0).at(0) = new Castle(false, 0, 0);        // black castle at row 0 column 0
    board.at(0).at(7) = new Castle(false, 0, 7);        // black castle at row 0 column 7
    board.at(7).at(0) = new Castle(true, 0, 0);         // white castle at row 0 column 0
    board.at(7).at(7) = new Castle(true, 0, 7);         // white castle at row 0 column 7

    // make knights
    board.at(0).at(1) = new Knight(false, 0, 1);        // black knight at row 0 column 1
    board.at(0).at(6) = new Knight(false, 0, 6);        // black knight at row 0 column 6
    board.at(7).at(1) = new Knight(true, 7, 1);         // white knight at row 7 column 1
    board.at(7).at(6) = new Knight(true, 7, 6);         // white knight at row 7 column 6

    // make bishops
    board.at(0).at(2) = new Bishop(false, 0, 2);        // black bishop at row 0 column 2
    board.at(0).at(5) = new Bishop(false, 0, 5);        // black bishop at row 0 column 5
    board.at(7).at(2) = new Bishop(true, 7, 2);         // white bishop at row 7 column 2
    board.at(7).at(5) = new Bishop(true, 7, 5);         // white bishop at row 7 column 5

    // make queens
    board.at(0).at(3) = new Queen(false, 0, 3);         // black queen at row 0 column 3
    board.at(7).at(3) = new Queen(true, 7, 3);          // white queen at row 7 column 3

    // make kings
    board.at(0).at(4) = new King(false, 0, 4);          // black king at row 0 column 4
    board.at(7).at(4) = new King(true, 7, 4);           // black king at row 7 column 4
}
