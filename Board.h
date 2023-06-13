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
    bool gameOver = false;                 // if the game is over or not
    bool whiteWin = false;                  // if the game ended with a win for white
    bool stalemate = false;                 // if the game ended in a stalemate
    bool insuffMat = false;                 // true if there is insufficient material and game ends in a tie
    bool pieceSelected = false;             // if a piece is currently selected (would be false, if turns have just changed)
    int lastMove = -1;                   // a coordinate of the last move that will help us track en passant
    int selectedRow = -1;         // initialized to -1 for no reason
    int selectedCol = -1;           // these are for drawing highlights and general tracking
    vector<vector<int>> selectedMoves;
    float initTime = 600.0f;        // initial time of game (can be changed) is 600 seconds which is 10 minutes
    bool showExitOptions = false;       // if true, we will show options to start a new game or return to start at bottom of the screen
    bool needsReset = false;
    bool toExit = false;


    // all the sprites to be used
    mutable Images textures = Images();

    // information for white
    string whiteName = "none";          // whites user nam
    sf::Clock whiteClock;        // Clock object to keep track of white's time
    float whiteTime = 0.0f;      // whiteTime which will hold the temporary time for white constantly
    vector<Piece*> whitePieces;
    int whiteValue = 39;

    // information for black
    string blackName = "none";
    sf::Clock blackClock;               // same thing but for black
    float blackTime = 0.0f;
    vector<Piece*> blackPieces;
    int blackValue = 39;

    // functions
    void DrawBoard(sf::RenderWindow& window);
    void DrawFireworks(sf::RenderWindow& window, bool whiteWin);
    void DrawEndScreen(sf::RenderWindow& window);
    void HighlightPiece(sf::RenderWindow& window);
    void HighlightMoves(sf::RenderWindow& window);
    void UpdateSelection(int toRow, int toCol);
    void UpdateMaterialCount();
    void UpdateTime(sf::RenderWindow& window);
    void EndTurn(sf::RenderWindow& window, int clickRow, int clickCol);
    void CheckForEnd(bool isWhite);            // checks for mate or stalemate. returns -1 if mate, 0, if stalemated, 1 if play continues
    void CheckForPromote(sf::RenderWindow& window, bool isWhite);        // check if a pawn is at the end of the board, if so, it promotes it
    bool CheckValidMove(int row, int col);
    Board();        // board constructor
    Board(string whiteName, string blackName, float time);      // parameterized constructor for resetting games
    ~Board() = default;
};
