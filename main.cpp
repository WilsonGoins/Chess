#include <iostream>
#include <vector>
#include "Board.h"
#include "Piece.h"
#include "Images.h"
using namespace std;
#include "SFML/Graphics.hpp"

void WelcomeScreen(sf::RenderWindow& window, Board& board);
int GameScreen(sf::RenderWindow& window, Board& board);

int main() {
    Board board = Board();          // board object to hold the majority of our data
    sf::RenderWindow window(sf::VideoMode(1100, 850), "Chess");     // window where everything happens
    WelcomeScreen(window, board);           // run the welcome screen
    int gameScreenResult = GameScreen(window, board);


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
    chessText.setPosition(sf::Vector2f(150, 150));        // put it in the top left
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
    sf::Text player1Name(p1Text, font, 40);
    player1Name.setFillColor(sf::Color::Black);
    player1Name.setPosition(sf::Vector2f(880, 100));
    // player 1 cursor
    sf::Text player1Cursor("|", font, 45);
    player1Cursor.setStyle(sf::Text::Bold);
    player1Cursor.setFillColor(sf::Color::Yellow);
    player1Cursor.setPosition(sf::Vector2f(player1Name.getLocalBounds().width + 880, 95));    // should be right after the player1 name
    // player 2 name text
    string p2Text = "P2";
    sf::Text player2Name(p2Text, font, 40);
    player2Name.setFillColor(sf::Color::Black);
    player2Name.setPosition(sf::Vector2f(880, 175));
    // player 2 cursor
    sf::Text player2Cursor("|", font, 45);
    player2Cursor.setStyle(sf::Text::Bold);
    player2Cursor.setFillColor(sf::Color::Yellow);
    player2Cursor.setPosition(sf::Vector2f(player2Name.getLocalBounds().width + 880, 170));       // right after player2 name
    // play button
    sf::Text playButton("Play", font, 60);
    playButton.setStyle(sf::Text::Bold);
    playButton.setFillColor(sf::Color::Yellow);
    playButton.setPosition(sf::Vector2f(playButton.getLocalBounds().width + 800, 745));       // right after player2 name
    cout << playButton.getLocalBounds().width << endl;
    // credits
    sf::Text credit1("Program Developer: Wilson Goins", font, 30);
    credit1.setStyle(sf::Text::Bold);
    credit1.setFillColor(sf::Color::Black);
    credit1.setPosition(sf::Vector2f(25, 745));       // right after player2 name
    sf::Text credit2("Program Illustrator: Madeleine Schutz", font, 30);
    credit2.setStyle(sf::Text::Bold);
    credit2.setFillColor(sf::Color::Black);
    credit2.setPosition(sf::Vector2f(25, 800));       // right after player2 name
//    // white pawn
//    sf::Texture whitePawn;
//    whitePawn.loadFromFile("Images/whitePawn.jpg");
//    sf::Sprite wPawn(whitePawn);
//    wPawn.scale(.1, .1);
//    wPawn.setPosition(sf::Vector2f(650, 100));
//    // black pawn
//    sf::Texture blackPawn;
//    blackPawn.loadFromFile("Images/blackPawn.jpg");
//    sf::Sprite bPawn(blackPawn);
//    bPawn.scale(.3, .3);
//    bPawn.setPosition(sf::Vector2f(650, 150));
//    // flip button
//    sf::Texture flipButton;
//    flipButton.loadFromFile("Images/flipButt.jpg");
//    sf::Sprite sprite;
//    sprite.setTexture(flipButton, true); // Enable alpha channel
//    sf::Image image = flipButton.copyToImage();
//    for (unsigned int x = 0; x < image.getSize().x; ++x) {
//        for (unsigned int y = 0; y < image.getSize().y; ++y) {
//            sf::Color pixel = image.getPixel(x, y);
//            // Check if the pixel is white (you may need to adjust the threshold)
//            if (pixel == sf::Color::White) {
//                pixel.a = 0; // Set the alpha channel to 0 (transparent)
//                image.setPixel(x, y, pixel);
//            }
//        }
//    }
//    flipButton.loadFromImage(image);
//    sprite.setTexture(flipButton);
//    sf::Sprite flipButt(flipButton);
//    flipButt.scale(.03, .03);
//    flipButt.setPosition(sf::Vector2f(600, 125));




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
        if ((P1Selected) and (visible)) {           // if player1 name is selected and it has been >0.5 seconds
            window.draw(player1Cursor);                                                 // draw it
        } else if ((not P1Selected) and (visible)){     // if player2 is selected, and it has been >0.5 seconds
            window.draw(player2Cursor);
        }
        sf::Vector2i hoverLocal = mouse.getPosition(window);        // get the mouse position
        if (playButton.getGlobalBounds().contains(hoverLocal.x, hoverLocal.y)) {
            playButton.setCharacterSize(65);
        } else {
            playButton.setCharacterSize(60);
        }
        window.draw(playButton);
        window.draw(credit1);
        window.draw(credit2);
//        window.draw(wPawn);
//        window.draw(bPawn);
//        window.draw(flipButt);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {      // if they close the window
                window.close();
                return;
            } else if (event.type == sf::Event::MouseButtonPressed) {       // if they click
                sf::Vector2i click = mouse.getPosition(window);        // get the mouse position
                if (p1Prompt.getGlobalBounds().contains(click.x, click.y)) {     // if they click player1's name
                    cout << click.x << endl;
                    P1Selected = true;          // player1 is selected
                    userName = p1Text;          // username equals the current player 1 name
                } else if (p2Prompt.getGlobalBounds().contains(click.x, click.y)) {
                    P1Selected = false;         // player2 is selected
                    userName = p2Text;          // set username equal to player2 name
                } else if (playButton.getGlobalBounds().contains(click.x, click.y)) {
                    board.userName1 = p1Text;                   // update the things we actually wanted from this screen
                    board.userName2 = p2Text;
                    board.user1IsWhite = player1White;
                    return;
                }
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

}

