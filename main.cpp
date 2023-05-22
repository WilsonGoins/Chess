#include <iostream>
#include <vector>
#include "Board.h"
#include "Piece.h"
#include "Images.h"
using namespace std;
#include "SFML/Graphics.hpp"

void WelcomeScreen(sf::RenderWindow& window, Images& images, string& user1, string& user2, bool& user1White);
int main() {
    string user1;
    string user2;
    bool user1White;
    sf::RenderWindow window(sf::VideoMode(1100, 850), "Chess");
    Images images = Images();
    WelcomeScreen(window, images, user1, user2, user1White);
    cout << "done" << endl;

    return 0;
}

void WelcomeScreen(sf::RenderWindow& window, Images& images, string& user1, string& user2, bool& user1White) {
    sf::Sprite welcomeImage(images.welcomeImage);       // sprite for background image
    // resize sprite to fit on the screen
    welcomeImage.setScale(static_cast<float>(window.getSize().x) / welcomeImage.getTexture()->getSize().x,
    static_cast<float>(window.getSize().y) / welcomeImage.getTexture()->getSize().y);
    // load font
    sf::Font font;
    font.loadFromFile("Fonts/BodoniModa-VariableFont_opsz,wght.ttf");
    // draw the welcome text
    sf::Text welcomeText("Chess", font, 175);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setOrigin(welcomeText.getLocalBounds().width / 2.0f - 150, welcomeText.getLocalBounds().height / 2.0f + 50);
    welcomeText.setPosition(sf::Vector2f(150, 150));
    // draw player 1 prompt
    sf::Text player1Prompt("Player 1:", font, 40);
    player1Prompt.setFillColor(sf::Color::White);
    player1Prompt.setOrigin(player1Prompt.getLocalBounds().width / 2.0f - 150, player1Prompt.getLocalBounds().height / 2.0f + 50);
    player1Prompt.setPosition(sf::Vector2f(650, 125));
    // draw player 2 prompt
    sf::Text player2Prompt("Player 2:", font, 40);
    player2Prompt.setFillColor(sf::Color::White);
    player2Prompt.setOrigin(player2Prompt.getLocalBounds().width / 2.0f - 150, player2Prompt.getLocalBounds().height / 2.0f + 50);
    player2Prompt.setPosition(sf::Vector2f(650, 200));
    // player 1 name text
    sf::Text player1Name("P1", font, 40);
    player1Name.setFillColor(sf::Color::Black);
    player1Name.setPosition(sf::Vector2f(890, 55));
    float player1Width = player1Name.getLocalBounds().width;
    // player 1 cursor
    sf::Text player1Cursor("|", font, 45);
    player1Cursor.setStyle(sf::Text::Bold);
    player1Cursor.setFillColor(sf::Color::Yellow);
    player1Cursor.setPosition(sf::Vector2f(player1Width + 890, 50));
    // player 2 name text
    sf::Text player2Name("P2", font, 40);
    player2Name.setFillColor(sf::Color::Black);
    player2Name.setPosition(sf::Vector2f(890, 130));
    float player2Width = player2Name.getLocalBounds().width;
    // player 2 cursor
    sf::Text player2Cursor("|", font, 45);
    player2Cursor.setStyle(sf::Text::Bold);
    player2Cursor.setFillColor(sf::Color::Yellow);
    player2Cursor.setPosition(sf::Vector2f(player2Width + 890, 124));



    sf::Mouse mouse;
    sf::Clock clock;
    bool P1Selected = true;
    bool visible = true;
    while (window.isOpen()) {
        // do these in main loop, so it constantly happens
        window.draw(welcomeImage);
        window.draw(welcomeText);
        window.draw(player1Prompt);
        window.draw(player2Prompt);
        window.draw(player1Name);
        window.draw(player2Name);
        if (clock.getElapsedTime().asSeconds() >= 0.5f) {
            visible = !visible;
            clock.restart();
        }
        if ((P1Selected) and (visible)) {
            window.draw(player1Cursor);
        } else if ((not P1Selected) and (visible)){
            window.draw(player2Cursor);
        }
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i click = mouse.getPosition(window);        // get the mouse position
                if (player1Name.getGlobalBounds().contains(click.x, click.y)) {
                    P1Selected = true;
                } else if (player2Name.getGlobalBounds().contains(click.x, click.y)) {
                    P1Selected = false;
                }
            }
        }
    }

}

