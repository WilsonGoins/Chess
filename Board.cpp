#include <iostream>
#include <ctime>
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
    board.resize(8);        // resize the outer vector of board to a size of 8
    selectedMoves.resize(8);        // resize selected moves
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            selectedMoves.at(i).push_back(0);       // fill it with 0s
        }
    }

    // make pawns
    for (int i = 0; i < 8; i++) {       // make black pawns in the 2nd row
        Piece* currPiece = new Pawn(false, 1, i);
        board.at(1).push_back(currPiece);
        blackPieces.push_back(currPiece);
    }

    for (int i = 0; i < 8; i++) {       // make white pawns in the 7th row
        Piece* currPiece = new Pawn(true, 6, i);
        board.at(6).push_back(currPiece);
        whitePieces.push_back(currPiece);
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
    // add these pieces to black pieces
    for (int i = 0; i < 8; i++) {
        blackPieces.push_back(board.at(0).at(i));
    }

    // make 8th row (white pieces)
    board.at(7).push_back(new Castle(true, 7, 0));
    board.at(7).push_back(new Knight(true, 7, 1));
    board.at(7).push_back(new Bishop(true, 7, 2));
    board.at(7).push_back(new Queen(true, 7, 3));
    board.at(7).push_back(new King(true, 7, 4));
    board.at(7).push_back(new Bishop(true, 7, 5));
    board.at(7).push_back(new Knight(true, 7, 6));
    board.at(7).push_back(new Castle(true, 7, 7));
    // add these pieces to black pieces
    for (int i = 0; i < 8; i++) {
        whitePieces.push_back(board.at(7).at(i));
    }


    for (int i = 2; i < 6; i++) {     // make rows 3 - 6 (empty squares)
        for (int j = 0; j < 8; j++) {
            board.at(i).push_back(new Empty(i, j));
        }
    }
}

Board::Board(string whiteName, string blackName, float time) {
    // things to carry over
    this->whiteName = whiteName;
    this->blackName = blackName;
    initTime = time;

    // from here on, everything else is the same
    board.resize(8);        // resize the outer vector of board to a size of 8
    selectedMoves.resize(8);        // resize selected moves
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            selectedMoves.at(i).push_back(0);       // fill it with 0s
        }
    }

    // make pawns
    for (int i = 0; i < 8; i++) {       // make black pawns in the 2nd row
        Piece* currPiece = new Pawn(false, 1, i);
        board.at(1).push_back(currPiece);
        blackPieces.push_back(currPiece);
    }

    for (int i = 0; i < 8; i++) {       // make white pawns in the 7th row
        Piece* currPiece = new Pawn(true, 6, i);
        board.at(6).push_back(currPiece);
        whitePieces.push_back(currPiece);
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
    // add these pieces to black pieces
    for (int i = 0; i < 8; i++) {
        blackPieces.push_back(board.at(0).at(i));
    }

    // make 8th row (white pieces)
    board.at(7).push_back(new Castle(true, 7, 0));
    board.at(7).push_back(new Knight(true, 7, 1));
    board.at(7).push_back(new Bishop(true, 7, 2));
    board.at(7).push_back(new Queen(true, 7, 3));
    board.at(7).push_back(new King(true, 7, 4));
    board.at(7).push_back(new Bishop(true, 7, 5));
    board.at(7).push_back(new Knight(true, 7, 6));
    board.at(7).push_back(new Castle(true, 7, 7));
    // add these pieces to black pieces
    for (int i = 0; i < 8; i++) {
        whitePieces.push_back(board.at(7).at(i));
    }


    for (int i = 2; i < 6; i++) {     // make rows 3 - 6 (empty squares)
        for (int j = 0; j < 8; j++) {
            board.at(i).push_back(new Empty(i, j));
        }
    }
}

void Board::CheckForEnd(bool isWhite) {
    // first lets make sure that neither of our players are out of time
//    if ((isWhite) and (whiteTime <= 0.0f)) {
//        gameOver = true;        // game is over, whiteWin was false at the start and will stay false, stalemate is also false
//        return;
//    } else if ((not isWhite) and (blackTime <= 0.0f)) {
//        gameOver = true;        // game is over
//        whiteWin = true;        // and white has won
//        return;
//    }
    // then we will go through each piece of whoever turn it is and check if those pieces can make a move. If they cannot make a move it is either checkmate or stalemate
    vector<Piece*> currPieces;
    if (isWhite) {
        currPieces = whitePieces;
    } else {
        currPieces = blackPieces;
    }
    Piece* currPiece;
    for (Piece* piece : currPieces) {
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
                    return;       // there is a possible move, so it is not mate or stalemate, so don't change any class attributes
                }
            }
        }
    }
    // if we have reached this point we have gone through all pieces of our color and found no possible moves
    if (Piece::CheckKingSafety(board, isWhite)) {       // so if we are not in check...
        gameOver = true;        // game is over
        stalemate = true;       // stalemate is true
        return;
    } else if (isWhite) {            // if we reached here it means the king is not safe. So if we are white, then black wins
        gameOver = true;        // game is over, whiteWin is false because black has won, and stalemate is still false
        return;          // so return
    } else if (!isWhite) {
        gameOver = true;        // the game is over
        whiteWin = true;        // white has won, stalemate is still false
        return;
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
                exit(0);
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

    // if there is a piece selected and the game isn't over yet
    if ((pieceSelected) and (not gameOver)) {
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
                if (board.at(i).at(j)->GetValue() == 0) {       // if the spot is a blank space
                    sf::CircleShape highlightCircle;
                    highlightCircle.setRadius(32.0f);
                    highlightCircle.setOrigin(highlightCircle.getLocalBounds().width / 2, highlightCircle.getLocalBounds().height / 2);
                    highlightCircle.setPosition(200.0f + (j * 88.0f) + 44.0f, 75.0f + (i * 88.0f) + 44.0f);
                    highlightCircle.setFillColor(blankColor);
                    window.draw(highlightCircle);
                } else if (board.at(i).at(j)->GetValue() != 0) {        // if it is an opposing piece
                    sf::RectangleShape highlightRect;               // make a new square
                    highlightRect.setSize(sf::Vector2f(88, 88));        // each tile is 88x88 big
                    highlightRect.setPosition(200.0f + (j) * 88.0f, 75.0f + (i * 88.0f));       // set position
                    highlightRect.setFillColor(captureColor);               // make it red
                    window.draw(highlightRect);
                }
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
    UpdateMaterialCount();          // update the material count for black and white
    CheckForEnd(whiteTurn);      // this function assumes the turn has already ended and checks if the new player has possible moves
}

void Board::UpdateMaterialCount() {
    vector<Piece*> wPieces;
    vector<Piece*> bPieces;
    int whiteVal = 0;
    int blackVal = 0;
    for (vector<Piece*> row : board) {
        for (Piece* piece : row) {
            int tempVal = piece->GetValue();
            if (tempVal == 1) {
                whiteVal += 1;
                wPieces.push_back(piece);
            } else if (tempVal == -1) {
                blackVal += 1;
                bPieces.push_back(piece);
            } else if (tempVal == 2) {
                whiteVal += 3;
                wPieces.push_back(piece);
            } else if (tempVal == -2) {
                blackVal += 3;
                bPieces.push_back(piece);
            } else if (tempVal == 3) {
                whiteVal += 3;
                wPieces.push_back(piece);
            } else if (tempVal == -3) {
                blackVal += 3;
                bPieces.push_back(piece);
            } else if (tempVal == 4) {
                whiteVal += 5;
                wPieces.push_back(piece);
            } else if (tempVal == -4) {
                blackVal += 5;
                bPieces.push_back(piece);
            } else if (tempVal == 5) {
                whiteVal += 9;
                wPieces.push_back(piece);
            } else if (tempVal == -5) {
                blackVal += 9;
                bPieces.push_back(piece);
            } else if (tempVal == 6) {          // we don't add to value because the king is invaluable
                wPieces.push_back(piece);
            } else if (tempVal == -6) {
                bPieces.push_back(piece);
            }
        }
    }
    whiteValue = whiteVal;
    blackValue = blackVal;
    whitePieces = wPieces;
    blackPieces = bPieces;
}

void Board::DrawEndScreen(sf::RenderWindow &window) {
    DrawFireworks(window, whiteWin);        // draw fireworks to show winner, if any
    // end border
    sf::Sprite background(textures.endBorder);      // load in the sprite
    sf::Vector2f bgSize(500.0f, 500.0f);        // set the size to 300x300
    background.setScale(bgSize.x / background.getLocalBounds().width,bgSize.y / background.getLocalBounds().height);
    background.setPosition((704 / 2) - 50, 75 + (704 / 2) - 250);       // set it to the middle of the screen
    float bgXMiddle = background.getPosition().x + 250;
    float bgYMiddle = background.getPosition().y + 250;

    // font
    sf::Font font;
    font.loadFromFile("Fonts/BodoniModa-VariableFont_opsz,wght.ttf");
    // outcome and congrats text
    string outcomeText;
    if (stalemate) {
        outcomeText = "Stalemate!";
    } else if (whiteWin) {
        outcomeText = "White wins!";
    } else if (not whiteWin) {
        outcomeText = "Black wins!";
    }
    // outcome
    sf::Text outcome(outcomeText, font, 55);
    outcome.setFillColor(sf::Color::Yellow);
    outcome.setOrigin(outcome.getLocalBounds().width / 2.0f, outcome.getLocalBounds().height / 2.0f);
    outcome.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle - 175));        // put it in the top middle of the background

    sf::Text congrats("Congratulations:", font, 40);
    sf::Text congratsName;
    sf::Text tieText("It's a tie!", font, 40);
    if (not stalemate) {
        // congratulations
        congrats.setFillColor(sf::Color::White);
        congrats.setOrigin(congrats.getLocalBounds().width / 2.0f, congrats.getLocalBounds().height / 2.0f);
        congrats.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle - 100));        // put it in the top middle of the background
        // congrats name
        string tempName;
        if (whiteWin) {tempName = whiteName;} else {tempName = blackName;}
        congratsName.setString(tempName);
        congratsName.setFont(font);
        congratsName.setCharacterSize(40);
        congratsName.setFillColor(sf::Color::White);
        congratsName.setOrigin(congratsName.getLocalBounds().width / 2.0f, congratsName.getLocalBounds().height / 2.0f);
        congratsName.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle - 50));        // put it in the top middle of the background
    } else {
        // tie text
        tieText.setFillColor(sf::Color::White);
        tieText.setOrigin(tieText.getLocalBounds().width / 2.0f, tieText.getLocalBounds().height / 2.0f);
        tieText.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle - 100));        // put it in the top middle of the background
    }
    sf::Color rectColor(0, 0, 0, 75);
    // return to board button
    sf::RectangleShape returnRect;
    returnRect.setSize(sf::Vector2f(330, 60));
    returnRect.setOrigin(returnRect.getLocalBounds().width / 2, returnRect.getLocalBounds().height / 2);
    returnRect.setPosition(bgXMiddle, bgYMiddle + 100);
    returnRect.setFillColor(rectColor);
    sf::Text returnOption(" Return To Board ", font, 40);
    returnOption.setFillColor(sf::Color::White);
    returnOption.setOrigin(returnRect.getLocalBounds().width / 2, returnRect.getLocalBounds().height / 2);
    returnOption.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle + 102));
    // new game button
    sf::RectangleShape newRect;
    newRect.setSize(sf::Vector2f(197, 60));
    newRect.setOrigin(newRect.getLocalBounds().width / 2, newRect.getLocalBounds().height / 2);
    newRect.setPosition(bgXMiddle - 100, bgYMiddle + 25);
    newRect.setFillColor(rectColor);
    sf::Text newOption(" New Game ", font, 35);
    newOption.setFillColor(sf::Color::White);
    newOption.setOrigin(newRect.getLocalBounds().width / 2, newRect.getLocalBounds().height / 2);
    newOption.setPosition(sf::Vector2f(bgXMiddle - 100, bgYMiddle + 30));
    // change settings button that takes them back to the start screen
    sf::RectangleShape menuRect;
    menuRect.setSize(sf::Vector2f(162, 60));
    menuRect.setOrigin(menuRect.getLocalBounds().width / 2, menuRect.getLocalBounds().height / 2);
    menuRect.setPosition(bgXMiddle + 105, bgYMiddle + 25);
    menuRect.setFillColor(rectColor);
    sf::Text menuOption(" Settings ", font, 35);
    menuOption.setFillColor(sf::Color::White);
    menuOption.setOrigin(menuRect.getLocalBounds().width / 2, menuRect.getLocalBounds().height / 2);
    menuOption.setPosition(sf::Vector2f(bgXMiddle + 110, bgYMiddle + 30));


    sf::Mouse mouse;
    while (window.isOpen()) {
        sf::Vector2i hoverLocal = mouse.getPosition(window);        // get the mouse position
        if (newRect.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            newOption.setFillColor(sf::Color::Yellow);
        } else if (returnRect.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            returnOption.setFillColor(sf::Color::Yellow);
        } else if (menuRect.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            menuOption.setFillColor(sf::Color::Yellow);
        } else {
            newOption.setFillColor(sf::Color::White);
            returnOption.setFillColor(sf::Color::White);
            menuOption.setFillColor(sf::Color::White);
        }

        DrawBoard(window, whiteTurn);       // draw the board
        window.draw(background);        // draw the new border over it
        window.draw(outcome);
        window.draw(returnRect);
        window.draw(returnOption);
        window.draw(newRect);
        window.draw(newOption);
        window.draw(menuRect);
        window.draw(menuOption);
        // draw text based on outcome
        if (stalemate) {window.draw(tieText);}
        else {window.draw(congrats); window.draw(congratsName);}
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {      // if they close the window, close it
                exit(0);
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i click = mouse.getPosition(window);        // mouse position
                if (returnRect.getGlobalBounds().contains(click.x, click.y)) {
                    showExitOptions = true;
                } else if (newRect.getGlobalBounds().contains(click.x, click.y)) {
                    needsReset = true;
                } else if (menuRect.getGlobalBounds().contains(click.x, click.y)) {
                    toExit = true;
                }
                lastMove = -69;
                return;
            }
        }
    }
}

void Board::DrawFireworks(sf::RenderWindow &window, bool whiteWin) {
    if (stalemate) {return;}        // if it was a stalemate, return

    sf::sleep(sf::seconds(0.5));

    int kingRow;
    int kingCol;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((board.at(i).at(j)->GetValue() == 6) and (whiteWin)) {      // if white king and white won
                kingRow = i;
                kingCol = j;
            } else if ((board.at(i).at(j)->GetValue() == -6) and (not whiteWin)) {      // if black king and black won
                kingRow = i;
                kingCol = j;
            }
        }
    }

    sf::Vector2f newSize(66.0f, 66.0f);
    sf::Sprite firework1(textures.fireworks);
    firework1.setScale(newSize.x / firework1.getLocalBounds().width, newSize.y / firework1.getLocalBounds().height);
    firework1.setPosition(200 + (kingCol * 88), 75 + (kingRow * 88) + 15);

    DrawBoard(window, whiteTurn);
    window.draw(firework1);
    window.display();
    sf::sleep(sf::seconds(0.6));      // let the board sleep for 0.3 seconds

    DrawBoard(window, whiteTurn);
    firework1.setPosition(200 + (kingCol * 88) + 38, 75 + (kingRow * 88) + 15);
    window.draw(firework1);
    window.display();
    sf::sleep(sf::seconds(0.6));      // let the board sleep for 0.3 seconds

    DrawBoard(window, whiteTurn);
    firework1.setPosition(200 + (kingCol * 88) + 10, 75 + (kingRow * 88) + 15);
    window.draw(firework1);
    window.display();
    sf::sleep(sf::seconds(1.6));      // let the board sleep for 1 second before returning
}
