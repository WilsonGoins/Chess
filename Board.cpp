#include <iostream>
#include <ctime>
#include <cmath>
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
    // then, we should check for insufficient material
    // here we gather data on what kind of pieces each of us have
    bool wLoneKing = false;
    bool bLoneKing = false;
    bool wKingKnight = false;
    bool bKingKnight = false;
    bool wKingBishop = false;
    bool bKingBishop = false;
    bool w2Knights = false;
    bool b2Knights = false;
    if (whitePieces.size() == 1) { wLoneKing = true;}            // if white side has one piece, lone king is true for white
    if (blackPieces.size() == 1) {bLoneKing = true;}      // if black has one piece, lone king for black is true
    if ((whitePieces.size() == 2) or (blackPieces.size() == 2)) {
        if (whiteValue == 8) {wKingKnight = true;}              // if the value is 8, that is a king and a knight
        else if (whiteValue == 9) {wKingBishop = true;}       // if the value is a 9, that is a king and a bishop
        if (blackValue == 8) {bKingKnight = true;}          // if black value is an 8, that is king and a knight
        else if (blackValue == 9) {bKingBishop = true;}         // if black value is a 9 that is king and a bishop
    }
    if (whitePieces.size() == 3) {      // if white has 3 pieces
        for (Piece* piece : whitePieces) {          // for every piece in white pieces
            if ((piece->GetValue() != 6) or (piece->GetValue() != 2)) {w2Knights = false; break;}       // if it isn't a king or a knight, set to false and break
            w2Knights = true;       // if it is one of those, set to true and keep going
        }
    } else if (blackPieces.size() == 3) {
        for (Piece* piece : blackPieces) {
            if ((piece->GetValue() != -6) or (piece->GetValue() != -2)) {b2Knights = false; break;}
            b2Knights = true;
        }
    }
    // checks for insufficient material
    // lone kings
    if ((wLoneKing) and (bLoneKing)) {insuffMat = true; gameOver = true; return;}
    // king vs king/bishop
    else if (((wLoneKing) and (bKingBishop)) or ((bLoneKing) and (wKingBishop))) {insuffMat = true; gameOver = true; return;}
    // king vs king/knight
    else if (((wLoneKing) and (bKingKnight)) or ((bLoneKing) and (wKingKnight))) {insuffMat = true; gameOver = true; return;}
    // king/bishop vs king/bishop
    else if ((wKingBishop) and (bKingBishop)) {insuffMat = true; gameOver = true; return;}
    // king/knight vs king/knight
    else if ((wKingKnight) and (bKingKnight)) {insuffMat = true; gameOver = true; return;}
    // lastly check if we have lone king vs king/knight/knight
    if (((wLoneKing) and (b2Knights)) or ((bLoneKing) and (w2Knights))) {insuffMat = true; gameOver = true; return;}

    // now we will see if our players can make a move, if they can, play continues, if not we have stalemate or checkmate
    vector<Piece*> currPieces;
    if (isWhite) {currPieces = whitePieces;} else {currPieces = blackPieces;}       // assign currPieces to white or black pieces
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

void Board::DrawBoard(sf::RenderWindow& window) {
    // first lets make sure that neither of our players are out of time
    if ((whiteTurn) and (whiteTime >= initTime)) {          // check if white is out of time
        gameOver = true;        // game is over, whiteWin was false at the start and will stay false, stalemate is also false
    } else if ((not whiteTurn) and (blackTime >= initTime)) {       // check if black is out of time
        gameOver = true;        // game is over
        whiteWin = true;        // and white has won
    }

    // font
    sf::Font font;
    font.loadFromFile("Fonts/BodoniModa-VariableFont_opsz,wght.ttf");

    // draw the background image
    sf::Sprite welcomeImage(textures.welcomeImage);     // now we must resize it
    welcomeImage.setScale(static_cast<float>(window.getSize().x) / welcomeImage.getTexture()->getSize().x, static_cast<float>(window.getSize().y) / welcomeImage.getTexture()->getSize().y);
    window.draw(welcomeImage);

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

    // black pawn
    sf::RectangleShape blackRect;
    blackRect.setSize(sf::Vector2f(130, 130));      // set the size to be slightly bigger than the pawn itself
    blackRect.setFillColor(sf::Color(255, 255, 255));
    blackRect.setPosition(15, 315);
    sf::Sprite blackPawn(textures.bPawn);
    sf::Vector2f iconSize(125, 125);            // set new size
    blackPawn.setScale(iconSize.x / blackPawn.getLocalBounds().width, iconSize.y / blackPawn.getLocalBounds().height);      // resize it
    blackPawn.setPosition(15, 315);
    window.draw(blackRect);
    window.draw(blackPawn);
    // white pawn
    sf::RectangleShape whiteRect;
    whiteRect.setSize(sf::Vector2f(130, 130));      // set the size to be slightly bigger than the pawn itself
    whiteRect.setFillColor(sf::Color(0, 0, 0));
    whiteRect.setPosition(959, 315);
    sf::Sprite whitePawn(textures.wPawn);
    whitePawn.setScale(iconSize.x / whitePawn.getLocalBounds().width, iconSize.y / whitePawn.getLocalBounds().height);      // resize it
    whitePawn.setPosition(959, 315);
    window.draw(whiteRect);
    window.draw(whitePawn);
    // black name
    sf::RectangleShape blackNameRect;    
    blackNameRect.setSize(sf::Vector2f(160.0f, 40.0f)); 
    blackNameRect.setFillColor(sf::Color::Black); // Set the color of the line
    blackNameRect.setPosition(0.0f, 265.0f);
    sf::Text blackNameText(blackName, font, 25);
    blackNameText.setFillColor(sf::Color::White);
    blackNameText.setOrigin(blackNameText.getLocalBounds().width / 2, blackNameText.getLocalBounds().height / 2);
    blackNameText.setPosition(80, 280);
    window.draw(blackNameRect);        
    window.draw(blackNameText);
    // white name
    sf::RectangleShape whiteNameRect;
    whiteNameRect.setSize(sf::Vector2f(160.0f, 40.0f));
    whiteNameRect.setFillColor(sf::Color::White); // Set the color of the line
    whiteNameRect.setPosition(944.0f, 265.0f);
    sf::Text whiteNameText(whiteName, font, 25);
    whiteNameText.setFillColor(sf::Color::Black);
    whiteNameText.setOrigin(whiteNameText.getLocalBounds().width / 2, whiteNameText.getLocalBounds().height / 2);
    whiteNameText.setPosition(1024, 280);
    window.draw(whiteNameRect);
    window.draw(whiteNameText);

    // triangle to indicate whose turn it is
    sf::CircleShape turnIndicator;
    turnIndicator.setPointCount(3);
    turnIndicator.setRadius(45);
    turnIndicator.setFillColor(sf::Color::Yellow);
    turnIndicator.setRotation(180);
    turnIndicator.setOrigin(turnIndicator.getLocalBounds().width / 2, turnIndicator.getLocalBounds().height / 2);
    if (whiteTurn) {turnIndicator.setPosition(1030, 200);}      // set position
    else {turnIndicator.setPosition(85, 180);}
    if (not gameOver) {window.draw(turnIndicator);}     // if the game isn't over draw it

    // draw the clocks
    UpdateTime(window);

    // draw the ranks and files lines over the clocks
    sf::RectangleShape bottomLine;      // bottom line
    bottomLine.setSize(sf::Vector2f(784.0f, 40.0f)); // Set the length to be 20 more than the board on each side, and thickness of the line to be 40 pixels
    bottomLine.setFillColor(sf::Color::Blue); // Set the color of the line
    bottomLine.setPosition(160.0f, 779.0f);
    window.draw(bottomLine);        // top line
    sf::RectangleShape topLine;
    topLine.setSize(sf::Vector2f(784.0f, 40.0f)); // Set the length to be 20 more than the board on each side, and thickness of the line to be 40 pixels
    topLine.setFillColor(sf::Color::Blue); // Set the color of the line
    topLine.setPosition(160.0f, 35.0f);
    window.draw(topLine);
    sf::RectangleShape leftLine;      // left line
    leftLine.setSize(sf::Vector2f(784.0f, 40.0f)); // Set the length to be 20 more than the board on each side, and thickness of the line to be 40 pixels
    leftLine.setFillColor(sf::Color::Blue); // Set the color of the line
    leftLine.setPosition(200.0f, 35.0f);        // set position to be in line with start of board, since rotation will move it to the left
    leftLine.setRotation(90);       // rotate the line 90 degrees
    window.draw(leftLine);
    sf::RectangleShape rightLine;      // right line
    rightLine.setSize(sf::Vector2f(784.0f, 40.0f)); // Set the length to be 20 more than the board on each side, and thickness of the line to be 40 pixels
    rightLine.setFillColor(sf::Color::Blue); // Set the color of the line
    rightLine.setPosition(944.0f, 35.0f);        // set position to be +40 from end of board, since rotation will move it to the left
    rightLine.setRotation(90);       // rotate the line 90 degrees
    window.draw(rightLine);
    // now draw the ranks and file letters
    sf::Text bottomText("    A       B       C       D       E       F       G       H", font, 35);
    bottomText.setFillColor(sf::Color::Yellow);
    bottomText.setPosition(sf::Vector2f(200, 779));
    window.draw(bottomText);
    sf::Text topText("    A       B       C       D       E       F       G       H", font, 35);
    topText.setFillColor(sf::Color::Yellow);
    topText.setPosition(sf::Vector2f(200, 35));
    window.draw(topText);
    sf::Text leftText("    8        7        6       5        4        3        2       1", font, 35);
    leftText.setFillColor(sf::Color::Yellow);
    leftText.setPosition(sf::Vector2f(200, 75));
    leftText.setRotation(90);
    window.draw(leftText);
    sf::Text rightText("    8        7        6       5        4        3        2       1", font, 35);
    rightText.setFillColor(sf::Color::Yellow);
    rightText.setPosition(sf::Vector2f(944, 75));
    rightText.setRotation(90);
    window.draw(rightText);
    
    // write the black material count
    sf::Font materialFont;
    materialFont.loadFromFile("Fonts/CormorantGaramond-Regular.ttf");
    sf::RectangleShape bMatRect;      // black material count rectangle
    bMatRect.setSize(sf::Vector2f(160, 65.0f)); // Set the length to be 20 more than the board on each side, and thickness of the line to be 40 pixels
    bMatRect.setFillColor(sf::Color::Black); // Set the color of the line
    bMatRect.setPosition(0.0f, 515.0f);        // set position to be +40 from end of board, since rotation will move it to the left
    window.draw(bMatRect);
    string bMaterial = " Material Count\n\t\t" + to_string(blackValue) + " (";
    if (blackValue - whiteValue < 0) {bMaterial += to_string(blackValue - whiteValue) + ")";}       // it's a negative number, so the - will already be there
    else {bMaterial += "+" + to_string(blackValue - whiteValue) + ")";}
    sf::Text blackMaterial(bMaterial, materialFont, 25);
    blackMaterial.setFillColor(sf::Color::White);
    blackMaterial.setPosition(sf::Vector2f(0, 515));
    window.draw(blackMaterial);

    // write the white material count
    sf::RectangleShape wMatRect;      // right line
    wMatRect.setSize(sf::Vector2f(160.0f, 65.0f)); // Set the length to be 20 more than the board on each side, and thickness of the line to be 40 pixels
    wMatRect.setFillColor(sf::Color::White); // Set the color of the line
    wMatRect.setPosition(944.0f, 515.0f);        // set position to be +40 from end of board, since rotation will move it to the left
    window.draw(wMatRect);
    string wMaterial = " Material Count\n\t\t" + to_string(whiteValue) + " (";
    if (whiteValue - blackValue < 0) {wMaterial += to_string(whiteValue - blackValue) + ")";}       // it's a negative number, so the - will already be there
    else {wMaterial += "+" + to_string(whiteValue - blackValue) + ")";}
    sf::Text whiteMaterial(wMaterial, materialFont, 25);
    whiteMaterial.setFillColor(sf::Color::Black);
    whiteMaterial.setPosition(sf::Vector2f(944, 515));
    window.draw(whiteMaterial);

    if ((gameOver) and (not stalemate) and (not insuffMat)) {       // if there was a winner, draw a crown
        sf::Sprite crownSprite(textures.crownTexture);
        crownSprite.setScale(130 / crownSprite.getLocalBounds().width, 150 / crownSprite.getLocalBounds().height);
        crownSprite.setOrigin(crownSprite.getLocalBounds().width / 2, crownSprite.getLocalBounds().height);       // set the origin to the bottom middle
        if (whiteWin) {crownSprite.setPosition(1022, 290);} else {crownSprite.setPosition(80, 290);}        // set the position based on who won
        window.draw(crownSprite);
    }

    // restart button for black
    sf::Sprite bRestart(textures.restartButton);
    bRestart.setScale(50 / bRestart.getLocalBounds().width, 50 / bRestart.getLocalBounds().height);         // resize to 50x50
    bRestart.setPosition(20, 585);            // top to icons have 160 pixels of space. each are 50 pixels wide. so 20 pixel separation on either side of each icon
    textures.globalBounds.emplace("bRestartGame", bRestart.getGlobalBounds());      // add the black restart button to global bounds
    window.draw(bRestart);
    // restart button for white
    sf::Sprite wRestart(textures.restartButton);
    wRestart.setScale(50 / wRestart.getLocalBounds().width, 50 / wRestart.getLocalBounds().height);         // resize to 50x50
    wRestart.setPosition(964, 585);            // top to icons have 160 pixels of space. each are 50 pixels wide. so 20 pixel separation on either side of each icon
    textures.globalBounds.emplace("wRestartGame", wRestart.getGlobalBounds());      // add the white restart button to global bounds
    window.draw(wRestart);
    // exit game for black
    sf::Sprite bExit(textures.exitGame);
    bExit.setScale(50 / bExit.getLocalBounds().width, 50 / bExit.getLocalBounds().height);         // resize to 50x50
    bExit.setPosition(90, 585);            // top to icons have 160 pixels of space. each are 50 pixels wide. so 20 pixel separation on either side of each icon
    textures.globalBounds.emplace("bExitGame", bExit.getGlobalBounds());      // add the black exit button to global bounds
    window.draw(bExit);
    // exit game for white
    sf::Sprite wExit(textures.exitGame);
    wExit.setScale(50 / wExit.getLocalBounds().width, 50 / wExit.getLocalBounds().height);         // resize to 50x50
    wExit.setPosition(1034, 585);            // top to icons have 160 pixels of space. each are 50 pixels wide. so 20 pixel separation on either side of each icon
    textures.globalBounds.emplace("wExitGame", wExit.getGlobalBounds());      // add the white exit button to global bounds
    window.draw(wExit);
    if (not gameOver) {     // if the game isn't over
        // make the surrender button for black
        sf::Sprite bSurrender(textures.surrenderFlag);
        bSurrender.setScale(100 / bSurrender.getLocalBounds().width, 75 / bSurrender.getLocalBounds().height);         // resize to 50x50
        bSurrender.setPosition(30, 625);            // top to icons have 160 pixels of space. each are 50 pixels wide. so 20 pixel separation on either side of each icon
        // make the surrender button for white
        sf::Sprite wSurrender(textures.surrenderFlag);
        wSurrender.setScale(100 / wSurrender.getLocalBounds().width, 75 / wSurrender.getLocalBounds().height);         // resize to 50x50
        wSurrender.setPosition(974, 625);            // top to icons have 160 pixels of space. each are 50 pixels wide. so 20 pixel separation on either side of each icon
        textures.globalBounds.emplace("bSurrenderGame", bSurrender.getGlobalBounds());      // add the black surrender button to global bounds
        textures.globalBounds.emplace("wSurrenderGame", wSurrender.getGlobalBounds());      // add the white surrender button to global bounds
        window.draw(wSurrender);        // draw the buttons
        window.draw(bSurrender);
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
    // end border
    sf::Sprite background(textures.endBorder);      // load in the sprite
    sf::Vector2f bgSize(500.0f, 500.0f);        // set the size to 300x300
    background.setScale(bgSize.x / background.getLocalBounds().width,bgSize.y / background.getLocalBounds().height);
    background.setPosition((704.0 / 2) - 50, 75 + (704.0 / 2) - 250);       // set it to the middle of the screen
    float bgXMiddle = background.getPosition().x + 250;
    float bgYMiddle = background.getPosition().y + 250;

    // font
    sf::Font font;
    font.loadFromFile("Fonts/BodoniModa-VariableFont_opsz,wght.ttf");
    // outcome and congrats text
    string outcomeText;
    if (stalemate) {
        outcomeText = "Stalemate!";
    } else if (insuffMat) {
        outcomeText = "Insufficient\n   Material";      // 2 spaces
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
    if ((not stalemate) and (not insuffMat)) {
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
        if (stalemate) {
            // tie text
            tieText.setFillColor(sf::Color::White);
            tieText.setOrigin(tieText.getLocalBounds().width / 2.0f, tieText.getLocalBounds().height / 2.0f);
            tieText.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle - 100));        // put it in the top middle of the background
        } else if (insuffMat) {
            tieText.setFillColor(sf::Color::White);
            tieText.setOrigin(tieText.getLocalBounds().width / 2.0f, tieText.getLocalBounds().height / 2.0f);
            tieText.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle - 40));        // tie text goes a little lower
            outcome.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle - 140));       // outcome text goes a little lower
        }
    }
    sf::Color rectColor(0, 0, 0, 75);
    // return to board button
    sf::RectangleShape returnRect;
    returnRect.setSize(sf::Vector2f(330, 60));
    returnRect.setOrigin(returnRect.getLocalBounds().width / 2, returnRect.getLocalBounds().height / 2);
    returnRect.setPosition(bgXMiddle, bgYMiddle + 110);
    returnRect.setFillColor(rectColor);
    sf::Text returnOption(" Return To Board ", font, 40);
    returnOption.setFillColor(sf::Color::White);
    returnOption.setOrigin(returnRect.getLocalBounds().width / 2, returnRect.getLocalBounds().height / 2);
    returnOption.setPosition(sf::Vector2f(bgXMiddle, bgYMiddle + 112));
    // new game button
    sf::RectangleShape newRect;
    newRect.setSize(sf::Vector2f(197, 60));
    newRect.setOrigin(newRect.getLocalBounds().width / 2, newRect.getLocalBounds().height / 2);
    newRect.setPosition(bgXMiddle - 100, bgYMiddle + 35);
    newRect.setFillColor(rectColor);
    sf::Text newOption(" New Game ", font, 35);
    newOption.setFillColor(sf::Color::White);
    newOption.setOrigin(newRect.getLocalBounds().width / 2, newRect.getLocalBounds().height / 2);
    newOption.setPosition(sf::Vector2f(bgXMiddle - 100, bgYMiddle + 40));
    // change settings button that takes them back to the start screen
    sf::RectangleShape menuRect;
    menuRect.setSize(sf::Vector2f(160, 60));
    menuRect.setOrigin(menuRect.getLocalBounds().width / 2, menuRect.getLocalBounds().height / 2);
    menuRect.setPosition(bgXMiddle + 105, bgYMiddle + 35);
    menuRect.setFillColor(rectColor);
    sf::Text menuOption(" Settings ", font, 35);
    menuOption.setFillColor(sf::Color::White);
    menuOption.setOrigin(menuRect.getLocalBounds().width / 2, menuRect.getLocalBounds().height / 2);
    menuOption.setPosition(sf::Vector2f(bgXMiddle + 110, bgYMiddle + 40));


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

        DrawBoard(window);       // draw the board
        window.draw(background);        // draw the new border over it
        window.draw(outcome);
        window.draw(returnRect);
        window.draw(returnOption);
        window.draw(newRect);
        window.draw(newOption);
        window.draw(menuRect);
        window.draw(menuOption);
        // draw text based on outcome
        if ((stalemate) or (insuffMat)) {window.draw(tieText);}
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

void Board::UpdateTime(sf::RenderWindow& window) {
    if (lastMove == -1) {           // if a move has not been made yet
        whiteClock.restart();     // restart the white clock, so we don't count the time on start screen
        blackClock.restart();
    }
    if ((whiteTurn) and (lastMove != -1) and (not gameOver)) {        // if it's whites turn and the game isn't over
        sf::Time tempTime = whiteClock.restart();       // get the time since we were last here
        whiteTime += tempTime.asSeconds();      // add it to white's total time taken
        blackClock.restart();        // restart the black clock so that the time does not keep going when we don't want it to
    } else if ((not whiteTurn) and (lastMove != -1) and (not gameOver)) {    // if it's black's turn and the game isn't over
        sf::Time tempTime = blackClock.restart();       // get the time since we were last here
        blackTime += tempTime.asSeconds();      // add it to black's total time taken
        whiteClock.restart();        // restart the white clock so that the time does not keep going when we don't want it to
    }
    // now we have to floats, blackTime and whiteTime that have the updated total amounts of time each has taken
    float blackRemaining = initTime - blackTime;                // so, now we should calculate the time they have left
    if (blackRemaining < 0.0f) {blackRemaining = 0.0f;}             // set time equal to 0 if it is less than 0 so we don't go into negatives
    float whiteRemaining = initTime - whiteTime;
    if (whiteRemaining < 0.0f) {whiteRemaining = 0.0f;}
    string blackMins = to_string(static_cast<int>(floor(blackRemaining / 60)));         // get the minutes taken
    if ((stoi(blackMins) < 10) and (blackMins.size() == 1)) {blackMins = "0" + blackMins;}     // if black minutes is only one digit add a 0 in front
    string blackSecs = to_string(static_cast<int>(blackRemaining) % 60);              // and the seconds taken
    if ((stoi(blackSecs) < 10) and (blackSecs.size() == 1)) {blackSecs = "0" + blackSecs;}     // if black minutes is only one digit add a 0 in front
    string whiteMins = to_string(static_cast<int>(floor(whiteRemaining / 60)));
    if ((stoi(whiteMins) < 10) and (whiteMins.size() == 1)) {whiteMins = "0" + whiteMins;}     // if black minutes is only one digit add a 0 in front
    string whiteSecs = to_string(static_cast<int>(whiteRemaining) % 60);
    if ((stoi(whiteSecs) < 10) and (whiteSecs.size() == 1)) {whiteSecs = "0" + whiteSecs;}     // if black minutes is only one digit add a 0 in front
    // now we draw the black time
    sf::Font font;      // font
    font.loadFromFile("Fonts/BodoniModa-VariableFont_opsz,wght.ttf");
    sf::RectangleShape blackRect;         // rectangle for white clock
    blackRect.setSize(sf::Vector2f(200, 50));       // we want it to cover the whole left side
    blackRect.setPosition(0, 450);
    blackRect.setFillColor(sf::Color::Black);
    sf::Text blackTime((blackMins + ":" + blackSecs), font, 40);
    blackTime.setFillColor(sf::Color::White);
    blackTime.setOrigin(blackTime.getLocalBounds().width / 2, blackTime.getLocalBounds().height / 2);
    blackTime.setPosition(sf::Vector2f(80, 465));       // position it 15 from the start of screen
    window.draw(blackRect);
    window.draw(blackTime);
    // now we draw the white time
    sf::RectangleShape whiteRect;         // rectangle for white clock
    whiteRect.setSize(sf::Vector2f(200, 50));
    whiteRect.setPosition(904, 450);
    whiteRect.setFillColor(sf::Color::White);
    sf::Text whiteTime((whiteMins + ":" + whiteSecs), font, 40);
    whiteTime.setFillColor(sf::Color::Black);
    whiteTime.setOrigin(whiteTime.getLocalBounds().width / 2, whiteTime.getLocalBounds().height / 2);
    whiteTime.setPosition(sf::Vector2f(1022, 465));
    window.draw(whiteRect);
    window.draw(whiteTime);
}


