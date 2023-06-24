#include <iostream>
#include <vector>
#include <cmath>
#include "Board.h"
#include "Piece.h"
#include "Images.h"
using namespace std;
#include "SFML/Graphics.hpp"

void WelcomeScreen(sf::RenderWindow& window, Board& board);
int GameScreen(sf::RenderWindow& window, Board& board);
void HandleClick(sf::RenderWindow& window, Board& board);

int main() {
    int gameScreenResult;
    while (true) {      // outer loop to go back to real beginning
        Board board = Board();          // board object to hold the majority of our data
        sf::RenderWindow window(sf::VideoMode(1100, 850), "Chess");     // window where everything happens
        WelcomeScreen(window, board);           // run the welcome screen
        while (true) {      // inner loop to go back to start of current game
            gameScreenResult = GameScreen(window, board);
            if (gameScreenResult == 0) {        // 0 means we need to go back to menu, so break out of here
                break;
            } else if (gameScreenResult == 1) {     // 1 means we need to reset the board
                board = Board(board.whiteName, board.blackName, board.initTime);        // make a new board and carry over unique attributes
            }
        }
    }
    return 0;
}

void WelcomeScreen(sf::RenderWindow& window, Board& board) {
    sf::Sprite welcomeImage(board.textures.welcomeImage);       // sprite for background image
    // resize sprite to fit on the screen
    welcomeImage.setScale(static_cast<float>(window.getSize().x) / welcomeImage.getTexture()->getSize().x,
    static_cast<float>(window.getSize().y) / welcomeImage.getTexture()->getSize().y);
    // load font
    sf::Font font;
    font.loadFromFile("Fonts/BodoniModa-VariableFont_opsz,wght.ttf");
    // draw the welcome text
    sf::Text chessText("Chess", font, 175);
    chessText.setFillColor(sf::Color::White);
    chessText.setOrigin(chessText.getLocalBounds().width / 2.0f - 150, chessText.getLocalBounds().height / 2.0f + 50);
    chessText.setPosition(sf::Vector2f(100, 150));        // put it in the top left
    // draw player 1 prompt
    sf::Text p1Prompt("Player 1:                            ", font, 40);      // lots of extra space so the clickable area is bigger
    p1Prompt.setFillColor(sf::Color::White);
    p1Prompt.setPosition(sf::Vector2f(710, 100));
    // draw player 2 prompt
    sf::Text p2Prompt("Player 2:                            ", font, 40);
    p2Prompt.setFillColor(sf::Color::White);
    p2Prompt.setPosition(sf::Vector2f(710, 175));
    // player 1 name text
    string p1Text = "P1";
    sf::Text player1Name(p1Text, font, 37);
    player1Name.setFillColor(sf::Color::Black);
    player1Name.setPosition(sf::Vector2f(872.5, 100));
    // player 1 cursor
    sf::Text player1Cursor("|", font, 45);
    player1Cursor.setStyle(sf::Text::Bold);
    player1Cursor.setFillColor(sf::Color::Yellow);
    player1Cursor.setPosition(sf::Vector2f(player1Name.getLocalBounds().width + 870, 95));    // should be right after the player1 name
    // player 2 name text
    string p2Text = "P2";
    sf::Text player2Name(p2Text, font, 37);
    player2Name.setFillColor(sf::Color::Black);
    player2Name.setPosition(sf::Vector2f(872.5, 175));
    // player 2 cursor
    sf::Text player2Cursor("|", font, 45);
    player2Cursor.setStyle(sf::Text::Bold);
    player2Cursor.setFillColor(sf::Color::Yellow);
    player2Cursor.setPosition(sf::Vector2f(player2Name.getLocalBounds().width + 870, 170));       // right after player2 name
    // play button
    sf::Text playButton("Play", font, 60);
    playButton.setStyle(sf::Text::Bold);
    playButton.setFillColor(sf::Color::Yellow);
    playButton.setPosition(sf::Vector2f(playButton.getLocalBounds().width + 800, 745));       // right after player2 name
    // credits
    sf::Text credit1("Program Developer: Wilson Goins", font, 30);
    credit1.setStyle(sf::Text::Bold);
    credit1.setFillColor(sf::Color::Black);
    credit1.setPosition(sf::Vector2f(25, 800));       // right after player2 name
    // white pawn
    sf::Vector2f topCoords(665, 95);
    sf::Sprite wPawn(board.textures.wPawn);
    wPawn.scale(.5, .5);
    wPawn.setPosition(topCoords);
    // black pawn
    sf::Vector2f bottomCoords(665, 170);
    sf::Sprite bPawn(board.textures.bPawn);
    bPawn.scale(.5, .5);
    bPawn.setPosition(bottomCoords);
    // flip button
    sf::Texture flipButton;
    flipButton.loadFromFile("Images/Classic/switchButton.png", sf::IntRect());
    sf::Sprite flipButt(flipButton);
    flipButt.scale(.35, .35);
    flipButt.setPosition(sf::Vector2f(580, 125));
    // time choice 1 (3 minutes)
    int timeChoice = -1;        // set time choice to -1, so we can tell if a time has been chosen yet
    sf::Color rectColor(255, 255, 255, 75);
    sf::RectangleShape time1Rect;
    time1Rect.setSize(sf::Vector2f(100, 60));
    time1Rect.setPosition(550, 270);
    time1Rect.setFillColor(rectColor);
    sf::Text time1(" 3:00 ", font, 40);
    time1.setFillColor(sf::Color::Black);
    time1.setPosition(sf::Vector2f(550, 275));
    // time choice 2 (5 minutes)
    sf::RectangleShape time2Rect;
    time2Rect.setSize(sf::Vector2f(100, 60));
    time2Rect.setFillColor(rectColor);
    time2Rect.setPosition(675, 270);
    sf::Text time2(" 5:00 ", font, 40);
    time2.setFillColor(sf::Color::Black);
    time2.setPosition(sf::Vector2f(675, 275));
    // time choice 3 (10 minutes)
    sf::RectangleShape time3Rect;
    time3Rect.setSize(sf::Vector2f(125, 60));
    time3Rect.setFillColor(rectColor);
    time3Rect.setPosition(800, 270);
    sf::Text time3(" 10:00 ", font, 40);
    time3.setFillColor(sf::Color::Black);
    time3.setPosition(sf::Vector2f(800, 275));
    // time choice 4 (10 minutes)
    sf::RectangleShape time4Rect;
    time4Rect.setSize(sf::Vector2f(125, 60));
    time4Rect.setFillColor(rectColor);
    time4Rect.setPosition(950, 270);
    sf::Text time4(" 60:00 ", font, 40);
    time4.setFillColor(sf::Color::Black);
    time4.setPosition(sf::Vector2f(950, 275));


    sf::Mouse mouse;        // mouse object to get position of the clicks
    sf::Clock clock;            // clock to facilitate blinking cursor
    bool P1Selected = true;     // boolean to know which name is being clicked on currently
    bool player1White = true;           // boolean to keep track of who is white
    bool visible = true;            // boolean to know if 0.5seconds has elapsed
    string userName = p1Text;           // username to save code by not having to switch between p1Text and p2Text

    while (window.isOpen()) {
        // do these in main loop, so it constantly happens
        window.draw(welcomeImage);      // draw background image
        window.draw(chessText);           // draw "CHESS"
        window.draw(p1Prompt);             // draw name prompt
        window.draw(p2Prompt);             // draw other name prompt
        player1Name.setString(p1Text);              // set the string of player 1 to be the updated player1 name
        player1Cursor.setPosition(sf::Vector2f(player1Name.getLocalBounds().width + 880, 95));        // reposition the cursor if the size of the text has changed
        window.draw(player1Name);           // draw player1 name
        player2Name.setString(p2Text);              // set the string of player 2 to be the updated player2 name
        player2Cursor.setPosition(sf::Vector2f(player2Name.getLocalBounds().width + 880, 170));
        window.draw(player2Name);               // draw the name
        if (clock.getElapsedTime().asSeconds() >= 0.5f) {           // if 0.5 seconds has passed
            visible = !visible;                     // then the cursor should be visible
            clock.restart();                        // restart the clock
        }
        if ((P1Selected) and (visible)) {           // if player1 name is selected, and it has been >0.5 seconds
            window.draw(player1Cursor);                                                 // draw it
        } else if ((not P1Selected) and (visible)){     // if player2 is selected, and it has been >0.5 seconds
            window.draw(player2Cursor);
        }
        sf::Vector2i hoverLocal = mouse.getPosition(window);        // get the mouse position
        if (playButton.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            playButton.setCharacterSize(65);
        } else if (time1Rect.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            time1.setFillColor(sf::Color::Yellow);
        } else if (time2Rect.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            time2.setFillColor(sf::Color::Yellow);
        } else if (time3Rect.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            time3.setFillColor(sf::Color::Yellow);
        } else if (time4Rect.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            time4.setFillColor(sf::Color::Yellow);
        } else {
            playButton.setCharacterSize(60);
            time1.setFillColor(sf::Color::Black);
            time2.setFillColor(sf::Color::Black);
            time3.setFillColor(sf::Color::Black);
            time4.setFillColor(sf::Color::Black);
        }
        window.draw(playButton);
        window.draw(credit1);
        if (timeChoice == 180) {
            time1.setFillColor(sf::Color::Yellow);
        } else if (timeChoice == 300) {
            time2.setFillColor(sf::Color::Yellow);
        } else if (timeChoice == 600) {
            time3.setFillColor(sf::Color::Yellow);
        } else if (timeChoice == 3600) {
            time4.setFillColor(sf::Color::Yellow);
        }
        window.draw(time1Rect);
        window.draw(time1);
        window.draw(time2Rect);
        window.draw(time2);
        window.draw(time3Rect);
        window.draw(time3);
        window.draw(time4Rect);
        window.draw(time4);
        if (player1White) {
            wPawn.setPosition(topCoords);
            bPawn.setPosition(bottomCoords);
        } else {
            wPawn.setPosition(bottomCoords);
            bPawn.setPosition(topCoords);
        }
        window.draw(wPawn);
        window.draw(bPawn);
        window.draw(flipButt);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {      // if they close the window
                exit(0);
            } else if (event.type == sf::Event::MouseButtonPressed) {       // if they click
                sf::Vector2i click = mouse.getPosition(window);        // get the mouse position
                if (p1Prompt.getGlobalBounds().contains(click.x, click.y)) {     // if they click player1's name
                    P1Selected = true;          // player1 is selected
                    userName = p1Text;          // username equals the current player 1 name
                } else if (p2Prompt.getGlobalBounds().contains(click.x, click.y)) {
                    P1Selected = false;         // player2 is selected
                    userName = p2Text;          // set username equal to player2 name
                } else if (time1Rect.getGlobalBounds().contains(click.x, click.y)) {
                    timeChoice = 180;
                } else if (time2Rect.getGlobalBounds().contains(click.x, click.y)) {
                    timeChoice = 300;
                } else if (time3Rect.getGlobalBounds().contains(click.x, click.y)) {
                    timeChoice = 600;
                } else if (time4Rect.getGlobalBounds().contains(click.x, click.y)) {
                    timeChoice = 3600;
                } else if ((playButton.getGlobalBounds().contains(click.x, click.y)) and (timeChoice != -1)) {
                    window.clear(sf::Color::White);
                    window.display();
                    if (player1White) {     // if player 1 is chosen to be white
                        board.whiteName = p1Text;       // then the white name is player 1's name
                        board.blackName = p2Text;
                    } else {                // if not...
                        board.whiteName = p2Text;       // the white name is player 2's name
                        board.blackName = p1Text;
                    }
                    board.initTime = timeChoice;        // update initial time to be whatever they chose
                    return;
                } else if (flipButt.getGlobalBounds().contains(click.x, click.y)) {
                    player1White = !player1White;
                }
                time1.setFillColor(sf::Color::Black);       // keep these here so that after every click all times are reset to black
                time2.setFillColor(sf::Color::Black);       // then only the currently chosen one is made yellow
                time3.setFillColor(sf::Color::Black);
                time4.setFillColor(sf::Color::Black);
            } else if (event.type == sf::Event::TextEntered) {      // checks if text was entered
                if (isalpha(static_cast<char>(event.text.unicode))) {       // checks if the text was a letter
                    if (userName.size() == 10) {            // if name length is at 10
                        continue;
                    } else {
                        userName += static_cast<char>(event.text.unicode);      // add current char to userName
                    }
                }
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::BackSpace) {
                    if ((userName.size() == 0) or (userName.size() == 1)) {
                        userName = "";
                    } else {
                        userName = userName.substr(0, userName.size() - 1);
                    }
                } else if (event.key.code == sf::Keyboard::Tab) {
                    if (P1Selected) {userName = p2Text;} else {userName = p1Text;}      // switch the selected name
                    P1Selected = !P1Selected;       // invert the current selection
                }
            }
        }
        if (P1Selected) {
            p1Text = userName;
        } else {
            p2Text = userName;
        }
        window.display();
    }
}

int GameScreen(sf::RenderWindow& window, Board& board) {
    while (window.isOpen()) {       // while window is open
        if (board.toExit) {return 0;}         // if we need to go back to menu return 0
        else if (board.needsReset) {return 1;}         // if we need to reset the board return 1

        board.DrawBoard(window);          // draw everything on the screen
        // when we reach this point it will have been after the game has ended (if it did) so here we will put up a screen to show that
        if ((board.gameOver) and (board.lastMove != -69)) {      // last move is set to -69 after we go through the end screen, so that it only happens once
            window.display();                   // update previous move
            board.DrawEndScreen(window);        // do end screen
        }
        window.display();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {      // if they close the window
                exit(0);  // return -1 to indicate game over
            } else if (event.type == sf::Event::MouseButtonPressed) {
                HandleClick(window, board);
            }
        }
    }
    return 0;
}

void HandleClick(sf::RenderWindow& window, Board& board) {
    sf::Mouse mouse;
    sf::Vector2i click = mouse.getPosition(window);        // mouse position
    int clickRow = floor((click.y - 75) / 88);        // click height divided by the height of one tile, starting at the top of the board (75 pixels down)
    int clickCol = floor((click.x - 200) / 88);       // click width divided by the length of one tile, starting at left of the board (200 pixels in)

    if ((board.textures.globalBounds.at("chessBoard").contains(click.x, click.y)) and (not board.gameOver)) {    // if the click is on the board and the game isn't over
        if (board.pieceSelected) {      // if there is a piece selected already
            // the click they just made will be there desired location
            if (board.CheckValidMove(clickRow, clickCol)) {       // so check if that location is a valid move
                board.EndTurn(window, clickRow, clickCol);      // if so, this function will move the piece and update necessary class attributes
            } else {        // if it isn't valid
                board.UpdateSelection(clickRow, clickCol);      // update their selection (they may have clicked on a different one of their own pieces)
            }
        } else {            // if a piece isn't already selected, update it because now it is
            board.UpdateSelection(clickRow, clickCol);
        }
    } else {        // if the click was not on the board
        if ((board.textures.globalBounds.at("bRestartGame").contains(click.x, click.y)) or (board.textures.globalBounds.at("wRestartGame").contains(click.x, click.y))) {        // if clicked on new game
            board.needsReset = true;            // set this to true if either of the reset buttons were clicked
        } else if ((board.textures.globalBounds.at("bExitGame").contains(click.x, click.y)) or (board.textures.globalBounds.at("wExitGame").contains(click.x, click.y))) {
            board.toExit = true;
        } else if ((board.textures.globalBounds.at("wSurrenderGame").contains(click.x, click.y)) and (board.whiteTurn)) {       // if white surrender button and it's white's turn
            board.gameOver = true;
        } else if ((board.textures.globalBounds.at("bSurrenderGame").contains(click.x, click.y)) and (not board.whiteTurn)) {       // if black surrender and black's turn
            board.gameOver = true;
            board.whiteWin = true;      // white win is now true
        }
    }
}