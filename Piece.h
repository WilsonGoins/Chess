#pragma once
#include <vector>
using namespace std;

class Piece {
public:
    virtual void MovePiece() = 0;
    virtual vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, bool checkForKing) = 0;
    virtual int GetValue() = 0;
    virtual ~Piece() = default;
    bool CheckKingSafety(vector<vector<Piece*>>& board, int fromRow, int fromCol) const {
        // if piece to be moved is black
        if (board.at(fromRow).at(fromCol)->GetValue() < 0) {
            // go through every piece of the opposite color
            for (const vector<Piece*>& row: board) {        // go through every row
                for (Piece* piece: row) {                          // for every piece
                    if (piece->GetValue() > 0) {                              // if it is the opposite color (white)
                        vector<vector<int>> moves = piece->GetMoves(board, false);       // get the moves for that piece (don't need to check for self check)
                        for (const vector<int>& rows : moves) {         // each row in moves
                            for (int move : rows) {                     // each move
                                if (move == 2) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        // if piece to be moved is white
        if (board.at(fromRow).at(fromCol)->GetValue() < 0) {
            // go through every black piece
            for (const vector<Piece *> &row: board) {        // go through every row
                for (Piece *piece: row) {                          // for every piece
                    if (piece->GetValue() < 0) {                              // if it is the opposite color (black)
                        vector<vector<int>> moves = piece->GetMoves(board,false);       // get the moves for that piece (don't need to check for self check)
                        for (const vector<int> &rows: moves) {         // each row in moves
                            for (int move: rows) {                     // each move
                                if (move == 2) {            // if the move is a 2 it is a check on the king
                                    return false;               // so the move is not valid and we return false
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;        // if none of the opposite colored pieces are checking the king, return true (the king is safe)
    }
};