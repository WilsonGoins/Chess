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
    welcomeText.setPosition(sf::Vector2f(window.getSize().x / 2.0f, 150));



    while (window.isOpen()) {
        // do these in main loop, so it constantly happens
        window.draw(welcomeImage);
        window.draw(welcomeText);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
    }

}

