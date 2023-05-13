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

}
