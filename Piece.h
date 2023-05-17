#pragma once
#include <vector>
using namespace std;

class Piece {
public:
    virtual void MovePiece() = 0;
    virtual vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, bool checkForKing) = 0;
    virtual int GetValue() = 0;
    virtual ~Piece() = default;
    bool CheckKingSafety(vector<vector<Piece*>>& board, bool isWhite) const {
        // if black
        if (not isWhite) {
            ;
        }
        return true;
    }
};

// for CheckKingSafety() we are going to treat the king like a queen in that we will go through all files and ranks and see if it looks
// at another piece. we must also make sure that it is the right king of piece. for example if we go straight up and hit a piece, we must make
// sure that piece is a castle, if it was a knight or a bishop it would not be checking us and thus would not matter.