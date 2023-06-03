#pragma once
#include "Piece.h"
#include "SFML/Graphics.hpp"
#include "Images.h"
#include <vector>
using namespace std;

class Board {
public:
    // general information about the game
    vector<vector<Piece*>> board;       // 2d vector to represent the board
    bool whiteTurn = true;
    bool gameOver;                  // if the game is over or not
    bool pieceSelected = false;             // if a piece is currently selected (would be false, if turns have just changed)
    int selectedRow = -1;         // initialized to -1 for no reason
    int selectedCol = -1;           // these are for drawing highlights and general tracking
    vector<vector<int>> selectedMoves;
    int lastMove;                   // a coordinate of the last move that will help us track en passant
    float initTime = 600.0f;        // initial time of game (can be changed) is 600 seconds which is 10 minutes


    // all the sprites to be used
    mutable Images textures = Images();

    // information for white
    string whiteName = "none";          // whites user nam
    sf::Clock whiteClock;        // Clock object to keep track of time
    float whiteTime = 0.0f;      // whiteTime which will hold the temporary time for white constantly

    // information for black
    string blackName = "none";
    sf::Clock blackClock;               // same thing but for black
    float blackTime = 0.0f;

    // functions
    void DrawBoard(sf::RenderWindow& window, bool whiteTurn);
    void HighlightPiece(sf::RenderWindow& window);
    void HighlightMoves(sf::RenderWindow& window);
    void UpdateSelection(int toRow, int toCol);
    void EndTurn(sf::RenderWindow& window, int clickRow, int clickCol);
    bool CheckValidMove(int row, int col);
    int CheckForEnd(bool isWhite);            // checks for mate or stalemate. returns -1 if mate, 0, if stalemated, 1 if play continues
    void CheckForPromote(sf::RenderWindow& window, bool isWhite);        // check if a pawn is at the end of the board, if so, it promotes it
    Board();        // board constructor
    ~Board() = default;
};
