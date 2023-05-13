#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class Board {
public:
    vector<vector<Piece*>> board;
    Board();
};
