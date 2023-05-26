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
//    textures = Images();
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
    board.at(0).push_back(new Queen(false, 0,3));
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

int Board::CheckForEnd(bool isWhite) {
    Piece* currPiece;
    for (const vector<Piece*>& row : board) {
        for (Piece* piece : row) {
            if ((piece->GetValue() > 0) and (isWhite)) {        // if the piece is white, and we are checking for mate against white
                currPiece = piece;      // update current piece
            } else if ((piece->GetValue() < 0) and (not isWhite)) {     // if the piece is black, and we are checking for mate against black
                currPiece = piece;
            } else {
                continue;
            }
            vector<vector<int>> possibleMoves = currPiece->GetMoves(board);     // get moves for the current piece
            for (const vector<int>& rows: possibleMoves) {
                for (int move : rows) {
                    if (move == 1) {        // if there is a 1, it represents a possible move
                        return 1;       // there is a possible move, so it is not mate or stalemate
                    }
                }
            }
        }
    }
    if ((isWhite) and (whiteTime <= 0.0f)) {
        return 2;
    } else if ((not isWhite) and (blackTime <= 0.0f)) {
        return 2;
    }
    // if we have reached this point we have gone through all pieces of our color and found no possible moves
    if (Piece::CheckKingSafety(board, isWhite)) {       // so if we are not in check...
        return 0;                                               // return 0 because it must be stalemate
    } else {            // if we are in  check, then it is mate
        return -1;          // so return -1
    }
}

void Board::CheckForPromote(sf::RenderWindow& window, bool isWhite) {
    int rowToCheck;
    if (isWhite) {
        rowToCheck = 0;     // if we are looking for a white pawn, the row to check is the 1st row (0)
    } else {
        rowToCheck = 7;     // if it's black, we need to check in row 7
    }

    int promotionChoice;
    for (int i = 0; i < 8; i++) {       // iterator for columns
        if (abs(board.at(rowToCheck).at(i)->GetValue()) == 1) {     // if the piece in the desired row is a pawn
            sf::Mouse mouse;
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {      // if they close the window, close it
                        window.close();
                        return;
                    } else if (event.type == sf::Event::MouseButtonPressed) {
                        // if the click is on one of the images to promote, return that number or something
                    }
                }
            }
        }
    }
}

void Board::DrawBoard(sf::RenderWindow& window, bool whiteTurn) const {
    sf::Sprite chessBoard = textures.chessBoard;
    chessBoard.setPosition(200, 75);
    window.draw(chessBoard);
}