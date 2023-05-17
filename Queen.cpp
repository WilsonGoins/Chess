#include "Queen.h"
#include "Empty.h"
#include <stdexcept>
using namespace std;

Queen::Queen(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 5;
    } else {
        value = -5;
    }
    this->row = row;
    this->col = col;
}

void Queen::MovePiece() {

}

vector<vector<int>> Queen::GetMoves(vector<vector<Piece*>>& board, bool checkForKing) {
    vector<vector<int>> currMoves;
    currMoves.resize(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);
        }
    }

    // black queen
    if (value == -5) {
        // get moves diagonal up and right
        int tempRow1 = row;
        int tempCol1 = col;
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() == 0) {     // empty
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempRow1--;     // go another row up
                            tempCol1++;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                    tempCol1++;
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal up and left
        int tempRow2 = row;
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempRow2--;     // go another row up
                            tempCol2--;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2--;
                    tempCol2--;
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and right
        int tempRow3 = row;
        int tempCol3 = col;
        try {
            while (true) {

                if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempRow3++;     // go another row up
                            tempCol3++;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow3++;
                    tempCol3++;
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and left
        int tempRow4 = row;
        int tempCol4 = col;
        try {
            while (true) {
                if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow4 - 1).at(tempCol4 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempRow3--;     // go another row up
                            tempCol3++;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4--;
                    tempCol4++;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow4 - 1).at(tempCol4 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow4 - 1).at(tempCol4 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves up
        int tempRow5 = row;
        try {
            while (true) {
                if (board.at(tempRow5 - 1).at(col)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow5 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempRow5--;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow5 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow5--;
                } else if (board.at(tempRow5 - 1).at(col)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow5 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow5 - 1).at(col) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow5 - 1).at(col)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow5 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow5 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves down
        int tempRow6 = row;
        try {
            while (true) {
                if (board.at(tempRow6 + 1).at(col)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow6 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempRow6++;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow6 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow6++;
                } else if (board.at(tempRow6 + 1).at(col)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow6 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow6 + 1).at(col) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow6 + 1).at(col)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow6 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow6 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves left
        int tempCol5 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol5 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol5 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempCol5--;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol5 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol5--;
                } else if (board.at(row).at(tempCol5 - 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol5 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol5 - 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(row).at(tempCol5 - 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol5 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol5 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves right
        int tempCol6 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol6 + 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol6++) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            tempCol6++;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol6 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol6++;
                } else if (board.at(row).at(tempCol6 + 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol6++) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol6 + 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(row).at(tempCol6 + 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol6++) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, false)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol6 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    }
    // white queen
    if (value == 5) {
        // get moves diagonal up and right
        int tempRow1 = row;
        int tempCol1 = col;
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() == 0) {     // empty
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempRow1--;     // go another row up
                            tempCol1++;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                    tempCol1++;
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow1 - 1).at(tempCol1 + 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(tempCol1 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(tempCol1 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal up and left
        int tempRow2 = row;
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempRow2--;     // go another row up
                            tempCol2--;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2--;
                    tempCol2--;
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(tempRow2 - 1).at(tempCol2 - 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 - 1).at(tempCol2 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 - 1).at(tempCol2 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and right
        int tempRow3 = row;
        int tempCol3 = col;
        try {
            while (true) {

                if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempRow3++;     // go another row up
                            tempCol3++;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow3++;
                    tempCol3++;
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow3 + 1).at(tempCol3 + 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow3 + 1).at(tempCol3 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow3 + 1).at(tempCol3 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves diagonal down and left
        int tempRow4 = row;
        int tempCol4 = col;
        try {
            while (true) {
                if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow4 - 1).at(tempCol4 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempRow3--;     // go another row up
                            tempCol3++;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow4--;
                    tempCol4++;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow4 - 1).at(tempCol4 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow4 + 1).at(tempCol4 - 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow4 - 1).at(tempCol4 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow4 + 1).at(tempCol4 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves up
        int tempRow5 = row;
        try {
            while (true) {
                if (board.at(tempRow5 - 1).at(col)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow5 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempRow5--;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow5 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow5--;
                } else if (board.at(tempRow5 - 1).at(col)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow5 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow5 - 1).at(col) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow5 - 1).at(col)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow5 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow5 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves down
        int tempRow6 = row;
        try {
            while (true) {
                if (board.at(tempRow6 + 1).at(col)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow6 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempRow6++;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow6 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow6++;
                } else if (board.at(tempRow6 + 1).at(col)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow6 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow6 + 1).at(col) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(tempRow6 + 1).at(col)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow6 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow6 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves left
        int tempCol5 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol5 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol5 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempCol5--;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol5 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol5--;
                } else if (board.at(row).at(tempCol5 - 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol5 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol5 - 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(row).at(tempCol5 - 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol5 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol5 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves right
        int tempCol6 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol6 + 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol6++) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            tempCol6++;     // go another row up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol6 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol6++;
                } else if (board.at(row).at(tempCol6 + 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol6++) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol6 + 1) = 2;      // make that spot a 2 to indicate it is checked
                    break;
                } else if (board.at(row).at(tempCol6 + 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol6++) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, true)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol6 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    } return currMoves;
}

int Queen::GetValue() {
    return value;
}
