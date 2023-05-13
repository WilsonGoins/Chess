#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class Board {
public:
    bool gameOver;

    vector<vector<Piece*>> board;
    Board();
};
