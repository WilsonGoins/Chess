#include <iostream>
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
    selectedMoves.resize(8);        // resize selected moves
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            selectedMoves.at(i).push_back(0);       // fill it with 0s
        }
    }

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
    // sprites to be loaded in
    sf::Sprite knight;
    sf::Sprite bishop;
    sf::Sprite castle;
    sf::Sprite queen;
    
    int rowToCheck;
    int colOfPromotion = -1;
    float displayHeight;
    int promotionChoice = -1;

    if (isWhite) {
        rowToCheck = 0;     // if we are looking for a white pawn, the row to check is the 1st row (0)
        displayHeight = 37.5;
        knight.setTexture(textures.wKnight);
        bishop.setTexture(textures.wBishop);
        castle.setTexture(textures.wCastle);
        queen.setTexture(textures.wQueen);
    } else {
        rowToCheck = 7;     // if it's black, we need to check in row 7
        displayHeight = 813.0;
        knight.setTexture(textures.bKnight);
        bishop.setTexture(textures.bBishop);
        castle.setTexture(textures.bCastle);
        queen.setTexture(textures.bQueen);
    }
    // check if we actually need to promote
    for (int i = 0; i < 8; i++) {       // iterator for columns
        if (abs(board.at(rowToCheck).at(i)->GetValue()) == 1) {     // if the piece in the desired row is a pawn
            colOfPromotion = i;
        }
    }
    if (colOfPromotion == -1) {     // if the column of promotion was not updated from -1 (we didn't find a pawn to promote) exit this foo
        return;
    }
    // format the sprites to the correct spots
    sf::Vector2f newSize(44.0f, 44.0f);     // new size for all pieces
    sf::Color rectColor(255, 255, 0);     // color for all pieces
    // knight
    knight.setScale(newSize.x / knight.getLocalBounds().width, newSize.y / knight.getLocalBounds().height);
    knight.setOrigin(knight.getLocalBounds().width / 2, knight.getLocalBounds().height / 2);
    knight.setPosition(165 + (colOfPromotion * 88.0f), displayHeight);
    sf::RectangleShape knightRect;
    knightRect.setSize(sf::Vector2f(50, 50));
    knightRect.setPosition(140 + (colOfPromotion) * 88.0f, displayHeight - 25);
    knightRect.setFillColor(rectColor);

    // bishop
    bishop.setScale(newSize.x / bishop.getLocalBounds().width, newSize.y / bishop.getLocalBounds().height);
    bishop.setOrigin(bishop.getLocalBounds().width / 2, bishop.getLocalBounds().height / 2);
    bishop.setPosition(165 + (colOfPromotion * 88.0f) + 55, displayHeight);
    sf::RectangleShape bishopRect;
    bishopRect.setSize(sf::Vector2f(50, 50));
    bishopRect.setPosition(140 + (colOfPromotion) * 88.0f + 55, displayHeight - 25);
    bishopRect.setFillColor(rectColor);
    // castle
    castle.setScale(newSize.x / castle.getLocalBounds().width, newSize.y / castle.getLocalBounds().height);
    castle.setOrigin(castle.getLocalBounds().width / 2, castle.getLocalBounds().height / 2);
    castle.setPosition(165 + (colOfPromotion * 88.0f) + 110, displayHeight);
    sf::RectangleShape castleRect;
    castleRect.setSize(sf::Vector2f(50, 50));
    castleRect.setPosition(140 + (colOfPromotion) * 88.0f + 110, displayHeight - 25);
    castleRect.setFillColor(rectColor);
    // queen
    queen.setScale(newSize.x / queen.getLocalBounds().width, newSize.y / queen.getLocalBounds().height);
    queen.setOrigin(queen.getLocalBounds().width / 2, queen.getLocalBounds().height / 2);
    queen.setPosition(165 + (colOfPromotion * 88.0f) + 165, displayHeight);
    sf::RectangleShape queenRect;
    queenRect.setSize(sf::Vector2f(50, 50));
    queenRect.setPosition(140 + (colOfPromotion) * 88.0f + 165, displayHeight - 25);
    queenRect.setFillColor(rectColor);

    sf::Mouse mouse;
    bool toLeave = false;
    while (window.isOpen()) {
        window.draw(knightRect);
        window.draw(bishopRect);
        window.draw(castleRect);
        window.draw(queenRect);
        window.draw(knight);
        window.draw(bishop);
        window.draw(castle);
        window.draw(queen);
        window.display();
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {      // if they close the window, close it
                window.close();
                return;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i click = mouse.getPosition(window);        // mouse position
                if (knightRect.getGlobalBounds().contains(click.x, click.y)) {
                    promotionChoice = 2;
                } else if (bishopRect.getGlobalBounds().contains(click.x, click.y)) {
                    promotionChoice = 3;
                } else if (castleRect.getGlobalBounds().contains(click.x, click.y)) {
                    promotionChoice = 4;
                } else if (queenRect.getGlobalBounds().contains(click.x, click.y)) {
                    promotionChoice = 5;
                }
            }
        }
        if (promotionChoice != -1) {      // if we selected a promotion, break and leave this while loop
            break;
        }
    }
    // now that we are out of the while loop and we now the piece we want to change, we should make that change
    if (promotionChoice == 2) {
        board.at(rowToCheck).at(colOfPromotion) = new Knight(isWhite, rowToCheck, colOfPromotion);
    } else if (promotionChoice == 3) {
        board.at(rowToCheck).at(colOfPromotion) = new Bishop(isWhite, rowToCheck, colOfPromotion);
    } else if (promotionChoice == 4) {
        board.at(rowToCheck).at(colOfPromotion) = new Castle(isWhite, rowToCheck, colOfPromotion);
    } else if (promotionChoice == 5) {
        board.at(rowToCheck).at(colOfPromotion) = new Queen(isWhite, rowToCheck, colOfPromotion);
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
        HighlightPiece(window);     // draw the highlight over that piece
        HighlightMoves(window);     // draw highlights over that piece's moves
    }


    // draw pieces on top of the board
    for (auto row : board) {
        for (auto piece : row) {
            window.draw(piece->DrawPiece(window, textures));
        }
    }
}

void Board::HighlightPiece(sf::RenderWindow& window) {
    if (board.at(selectedRow).at(selectedCol)->GetValue() == 0) {       // if the piece is an empty square just return
        return;
    } else if ((board.at(selectedRow).at(selectedCol)->GetValue() < 0) and (whiteTurn)) {           // if it's a black piece, and it's white's turn
        return;
    } else if ((board.at(selectedRow).at(selectedCol)->GetValue() > 0) and (not whiteTurn)) {         // if it's a white piece, and it's black's turn
        return;
    }

    sf::Color highlightColor(255, 255, 0);        // color
    sf::RectangleShape highlightRect;
    highlightRect.setSize(sf::Vector2f(88, 88));        // each tile is 88x88 big
    highlightRect.setPosition(200.0f + (selectedCol) * 88.0f, 75.0f + (selectedRow * 88.0f));       // set position to whatever square in the top left
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

void Board::HighlightMoves(sf::RenderWindow &window) {
    // we want this function to highlight all the possible moves for a piece at row, col
    sf::Color blankColor(255, 255, 0);        // color to be drawn on blank spot
    sf::Color captureColor(255, 0, 0);        // color to be drawn on capturing spot

    // loop through every move in the piece's move set
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (selectedMoves.at(i).at(j) == 1) {        // if the move is a 1
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
        selectedMoves = board.at(toRow).at(toCol)->GetMoves(board, lastMove);
    } else if ((board.at(toRow).at(toCol)->GetValue() < 0) and (not whiteTurn)) {       // if it's blacks turn and a black piece was clicked on
        pieceSelected = true;     // there is a click on the board so pieceSelected is now true (empties are still pieces)
        selectedRow = toRow;       // update the row
        selectedCol = toCol;       // update the column
        selectedMoves = board.at(toRow).at(toCol)->GetMoves(board, lastMove);
    } else if (board.at(toRow).at(toCol)->GetValue() == 0) {
        pieceSelected = false;
    }
}

void Board::EndTurn(sf::RenderWindow& window, int clickRow, int clickCol) {       // this moves the piece, and also adjusts certain class attributes that need to be updated
    board.at(selectedRow).at(selectedCol)->MovePiece(board, clickRow, clickCol);      // make the move
    lastMove = (clickRow * 8) + clickCol;     // update last move to wherever the piece just moved
    whiteTurn = !whiteTurn;     // flip whose turn it is
    pieceSelected = false;        // deselect any pieces
    CheckForPromote(window, !whiteTurn);        // this will check for pawn promotes, we do !whiteTurn, because we already switched it
}
