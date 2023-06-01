#pragma once
#include "Images.h"
#include <vector>
#include <stdexcept>
#include <SFML/Graphics.hpp>

using namespace std;

class Piece {
public:
    virtual void MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) = 0;
    virtual vector<vector<int>> GetMoves(vector<vector<Piece*>>& board, int lastMove) = 0;
    virtual sf::Sprite DrawPiece(sf::RenderWindow& window, Images& textures) = 0;
    virtual int GetValue() = 0;
    virtual ~Piece() = default;
    static bool CheckKingSafety(vector<vector<Piece*>>& board, bool isWhite) {
        int kingRow;
        int kingCol;
        // get the position of the king
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((board.at(i).at(j)->GetValue() == -6) and (not isWhite)) {
                    kingRow = i;
                    kingCol = j;
                } else if ((board.at(i).at(j)->GetValue() == 6) and (isWhite)) {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }

        // if black
        if (not isWhite) {
            // check vertical up file
            int tempRow1 = kingRow;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow1 - 1).at(kingCol)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow1--;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == 4) or (nextPiece == 5) or ((nextPiece == 6) and (tempRow1 == kingRow))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check vertical up file
            int tempRow2 = kingRow;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow2 + 1).at(kingCol)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow2++;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == 4) or (nextPiece == 5) or ((nextPiece == 6) and (tempRow2 == kingRow))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check horizontal left rank
            int tempCol1 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(kingRow).at(tempCol1 - 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempCol1--;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == 4) or (nextPiece == 5) or ((nextPiece == 6) and (tempCol1 == kingCol))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check horizontal right rank
            int tempCol2 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(kingRow).at(tempCol2 + 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempCol2--;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == 4) or (nextPiece == 5) or ((nextPiece == 6) and (tempCol2 == kingCol))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check up/left diagonal
            int tempRow3 = kingRow;
            int tempCol3 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow3 - 1).at(tempCol3 - 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow3--;     // increment row
                        tempCol3--;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == 3) or (nextPiece == 5) or ((nextPiece == 6) and (tempRow3 == kingRow) and (tempCol3 == kingCol))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check up/right diagonal
            int tempRow4 = kingRow;
            int tempCol4 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow4 - 1).at(tempCol4 + 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow4--;     // increment row
                        tempCol4++;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == 3) or (nextPiece == 5) or ((nextPiece == 6) and (tempRow4 == kingRow) and (tempCol4 == kingCol))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check down/left diagonal
            int tempRow5 = kingRow;
            int tempCol5 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow5 + 1).at(tempCol5 - 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow5++;     // increment row
                        tempCol5--;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == 3) or (nextPiece == 5) or ((nextPiece == 6) and (tempRow5 == kingRow) and (tempCol5 == kingCol))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check down/right diagonal
            int tempRow6 = kingRow;
            int tempCol6 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow6 + 1).at(tempCol6 + 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow6++;     // increment row
                        tempCol6++;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == 3) or (nextPiece == 5) or ((nextPiece == 6) and (tempRow6 == kingRow) and (tempCol6 == kingCol))) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check knight attacks
            // up 2, left 1
            try {
                if (board.at(kingRow - 2).at(kingCol - 1)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // up 2, right 1
            try {
                if (board.at(kingRow - 2).at(kingCol + 1)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // right 2, up 1
            try {
                if (board.at(kingRow - 1).at(kingCol + 2)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // right 2, down 1
            try {
                if (board.at(kingRow + 1).at(kingCol + 2)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // down 2, right 1
            try {
                if (board.at(kingRow + 2).at(kingCol + 1)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // down 2, left 1
            try {
                if (board.at(kingRow + 2).at(kingCol - 1)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // down 1, left 2
            try {
                if (board.at(kingRow + 1).at(kingCol - 2)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // up 1, left 2
            try {
                if (board.at(kingRow - 1).at(kingCol - 2)->GetValue() == 2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // check pawns
            // check down 1, left 1
            try {
                if (board.at(kingRow + 1).at(kingCol - 1)->GetValue() == 1) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // check down 1, right 1
            try {
                if (board.at(kingRow + 1).at(kingCol + 1)->GetValue() == 1) {
                    return false;
                }
            } catch (const out_of_range &e) {}

        } else if (isWhite) {        // if the king is white
            // check vertical up file
            int tempRow1 = kingRow;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow1 - 1).at(kingCol)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow1--;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == -4) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check vertical up file
            int tempRow2 = kingRow;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow2 + 1).at(kingCol)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow2++;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == -4) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check horizontal left rank
            int tempCol1 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(kingRow).at(tempCol1 - 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempCol1--;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == -4) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check horizontal right rank
            int tempCol2 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(kingRow).at(tempCol2 + 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempCol2--;     // increment row
                        continue;           // continue
                    } else if ((nextPiece == -4) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check up/left diagonal
            int tempRow3 = kingRow;
            int tempCol3 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow3 - 1).at(tempCol3 - 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow3--;     // increment row
                        tempCol3--;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == -3) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check up/right diagonal
            int tempRow4 = kingRow;
            int tempCol4 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow4 - 1).at(tempCol4 + 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow4--;     // increment row
                        tempCol4++;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == -3) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check down/left diagonal
            int tempRow5 = kingRow;
            int tempCol5 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow5 + 1).at(tempCol5 - 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow5++;     // increment row
                        tempCol5--;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == -3) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check down/right diagonal
            int tempRow6 = kingRow;
            int tempCol6 = kingCol;
            try {
                while (true) {
                    int nextPiece = board.at(tempRow6 + 1).at(tempCol6 + 1)->GetValue();
                    if (nextPiece == 0) {      // if empty spot
                        tempRow6++;     // increment row
                        tempCol6++;     // increment col
                        continue;           // continue
                    } else if ((nextPiece == -3) or (nextPiece == -5)) {   // if white castle or white queen
                        return false;
                    } else {        // if it's anything else (other black piece or other white piece)
                        break;
                    }
                }
            } catch (const out_of_range &e) {}

            // check knight attacks
            // up 2, left 1
            try {
                if (board.at(kingRow - 2).at(kingCol - 1)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // up 2, right 1
            try {
                if (board.at(kingRow - 2).at(kingCol + 1)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // right 2, up 1
            try {
                if (board.at(kingRow - 1).at(kingCol + 2)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // right 2, down 1
            try {
                if (board.at(kingRow + 1).at(kingCol + 2)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // down 2, right 1
            try {
                if (board.at(kingRow + 2).at(kingCol + 1)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // down 2, left 1
            try {
                if (board.at(kingRow + 2).at(kingCol - 1)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // down 1, left 2
            try {
                if (board.at(kingRow + 1).at(kingCol - 2)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // up 1, left 2
            try {
                if (board.at(kingRow - 1).at(kingCol - 2)->GetValue() == -2) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // check pawns
            // check up 1, left 1
            try {
                if (board.at(kingRow - 1).at(kingCol - 1)->GetValue() == -1) {
                    return false;
                }
            } catch (const out_of_range &e) {}

            // check up 1, right 1
            try {
                if (board.at(kingRow - 1).at(kingCol + 1)->GetValue() == -1) {
                    return false;
                }
            } catch (const out_of_range &e) {}
        }
        return true;
    }
    virtual int GetNumMoves() = 0;
};      // end of class
