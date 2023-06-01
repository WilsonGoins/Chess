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
    lastMove = -1;
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
            vector<vector<int>> possibleMoves = currPiece->GetMoves(board, lastMove);     // get moves for the current piece
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

void Board::DrawBoard(sf::RenderWindow& window, bool whiteTurn) {
    window.clear(sf::Color::Blue);   // clear the window to have a blue background

    // sprite for the board
    sf::Sprite chessBoard(textures.chessBoard);
    // new size is 704x704. this makes it a square. 700 width leaves 198 pixels on each size, 700 height leaves 73 pixels on top and bottom
    // 704x704 also makes it so our chess board is divisible by 64 for a total of 64 different 88x88 squares
    sf::Vector2f chessBoardNewSize(704.0f, 704.0f);
    // scale the board
    chessBoard.setScale(chessBoardNewSize.x / chessBoard.getLocalBounds().width, chessBoardNewSize.y / chessBoard.getLocalBounds().height);
    chessBoard.setPosition(200, 75);        // set position of the board
    textures.globalBounds.emplace("chessBoard", chessBoard.getGlobalBounds());
    window.draw(chessBoard);        // draw the board

    // if there is a piece selected
    if (pieceSelected) {
        HighlightPiece(window, selectedRow, selectedCol);     // draw the highlight over that piece
        HighlightMoves(window, selectedRow, selectedCol);     // draw highlights over that piece's moves
    }


    // draw pieces on top of the board
    for (auto row : board) {
        for (auto piece : row) {
            window.draw(piece->DrawPiece(window, textures));
        }
    }
}

void Board::HighlightPiece(sf::RenderWindow& window, int row, int col) {
    if (board.at(row).at(col)->GetValue() == 0) {       // if the piece is an empty square just return
        return;
    } else if ((board.at(row).at(col)->GetValue() < 0) and (whiteTurn)) {           // if it's a black piece, and it's white's turn
        return;
    } else if ((board.at(row).at(col)->GetValue() > 0) and (not whiteTurn)) {         // if it's a white piece, and it's black's turn
        return;
    }

    sf::Color highlightColor(255, 255, 0);        // color
    sf::RectangleShape highlightRect;
    highlightRect.setSize(sf::Vector2f(88, 88));        // each tile is 88x88 big
    highlightRect.setPosition(200.0f + (col) * 88.0f, 75.0f + (row * 88.0f));       // set position to whatever square in the top left
    highlightRect.setFillColor(highlightColor);
    window.draw(highlightRect);
}

bool Board::CheckValidMove(int toRow, int toCol) {
    // we should now check if their click is on one of the moves they can make
    vector<vector<int>> currMoves = board.at(selectedRow).at(selectedCol)->GetMoves(board, lastMove);       // selected pieces moves
    if (currMoves.at(toRow).at(toCol) == 1) {           // if their desired spot is a 1 (valid move) return true
        return true;
    } else {
        return false;       // if not, return false
    }
}

void Board::HighlightMoves(sf::RenderWindow &window, int row, int col) {
    // we want this function to highlight all the possible moves for a piece at row, col
    vector<vector<int>> moves = board.at(row).at(col)->GetMoves(board, lastMove);   // get the current moves
    sf::Color blankColor(255, 255, 0);        // color to be drawn on blank spot
    sf::Color captureColor(255, 0, 0);        // color to be drawn on capturing spot

    // loop through every move in the piece's move set
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (moves.at(i).at(j) == 1) {        // if the move is a 1
                sf::RectangleShape highlightRect;               // make a new square
                highlightRect.setSize(sf::Vector2f(88, 88));        // each tile is 88x88 big
                highlightRect.setPosition(200.0f + (j) * 88.0f, 75.0f + (i * 88.0f));       // set position
                if (board.at(i).at(j)->GetValue() == 0) {       // if the spot is a blank space
                    highlightRect.setFillColor(blankColor);         // make the square yellow
                } else if (board.at(i).at(j)->GetValue() != 0) {        // if it is a opposing piece
                    highlightRect.setFillColor(captureColor);               // make it red
                }
                window.draw(highlightRect);     // draw it
            }
        }
    }
}

void Board::UpdateSelection(int toRow, int toCol) {
    if ((board.at(toRow).at(toCol)->GetValue() > 0) and (whiteTurn)) {        // if it is white's turn and a white piece was clicked on
        pieceSelected = true;     // there is a click on the board so pieceSelected is now true (empties are still pieces)
        selectedRow = toRow;       // update the row
        selectedCol = toCol;       // update the column
    } else if ((board.at(toRow).at(toCol)->GetValue() < 0) and (not whiteTurn)) {       // if it's blacks turn and a black piece was clicked on
        pieceSelected = true;     // there is a click on the board so pieceSelected is now true (empties are still pieces)
        selectedRow = toRow;       // update the row
        selectedCol = toCol;       // update the column
    } else if (board.at(toRow).at(toCol)->GetValue() == 0) {
        pieceSelected = false;
    }
}
