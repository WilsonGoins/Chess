#include <iostream>
#include "Castle.h"
#include "Empty.h"
#include <stdexcept>
using namespace std;

Castle::Castle(bool isWhite, int row, int col) {
    if (isWhite) {
        value = 4;
    } else {
        value = -4;
    }
    hasMoved = false;
    this->row = row;
    this->col = col;
}

void Castle::MovePiece() {
    cout << "moving castle..." << endl;
}

vector<vector<int>> Castle::GetMoves(vector<vector<Piece*>>& board, bool checkForKing) {
    vector<vector<int>> currMoves;      // vector of moves to return
    currMoves.resize(8);            // make it 2d
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);       // initialize each value to 0
        }
    }

    // black castle
    if (value == -4) {
        // get moves up
        int tempRow1 = row;
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(col)->GetValue() == 0) {      // if empty spot
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempRow1--;     // go another row up
                            continue;       // go back to start of while loop with these new positions
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() == 6) {        // white king
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() > 0) {        // white piece
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // black piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves down
        int tempRow2 = row;
        try {
            while (true) {
                if (board.at(tempRow2 + 1).at(col)->GetValue() == 0) {      // empty
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempRow2++;     // go another row up
                            continue;       // go back to start of while loop with these new positions
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2++;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() == 6) {        // white king
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 + 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() > 0) {        // any white piece
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {        // any black piece
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves left
        int tempCol1 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol1 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempCol1--;     // go another col up
                            continue;       // go back to start of while loop with these new positions
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1--;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol1 - 1) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves right
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol2 + 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempCol2++;     // go another col up
                            continue;       // go back to start of while loop with these new positions
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1++;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() == 6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol2 + 1) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() > 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    }

    // white pieces
    if (value == 4) {
        // get moves up
        int tempRow1 = row;
        try {
            while (true) {
                if (board.at(tempRow1 - 1).at(col)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempRow1--;     // go another row up
                            continue;       // go back to start of while loop with these new positions
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow1--;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow1 - 1).at(col)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow1 - 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow1 - 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves down
        int tempRow2 = row;
        try {
            while (true) {
                if (board.at(tempRow2 + 1).at(col)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempRow2++;     // go another row up
                            continue;       // go back to start of while loop with these new positions
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempRow2++;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 + 1).at(col) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(tempRow2 + 1).at(col)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(tempRow2 + 1).at(col) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(tempRow2 + 1).at(col) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves left
        int tempCol1 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol1 - 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempCol1--;     // go another col up
                            continue;       // go back to start of while loop with these new positions
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1--;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol1 - 1) = 2;      // make that spot a 2 to indicate it is check
                    break;
                } else if (board.at(row).at(tempCol1 - 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol1 - 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol1 - 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
        // get moves right
        int tempCol2 = col;
        try {
            while (true) {
                if (board.at(row).at(tempCol2 + 1)->GetValue() == 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            tempCol1++;     // go another col up
                            continue;       // restart loop
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    tempCol1++;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() == -6) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol2 + 1) = 2;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else if (board.at(row).at(tempCol2 + 1)->GetValue() < 0) {
                    if (checkForKing) {     // if we are told to check for king
                        vector<vector<Piece *>> newBoard = board;        // make a copy of the board
                        newBoard.at(row).at(tempCol2 + 1) = board.at(row).at(col);       // put the piece to be moved in new spot
                        newBoard.at(row).at(col) = new Empty(row, col);         // make the old spot empty
                        if (not CheckKingSafety(newBoard, row, col)) {  // if this move puts our king in check
                            break;
                        }
                    }   // if it doesn't put our king in check
                    currMoves.at(row).at(tempCol2 + 1) = 1;      // make that spot a 1 to indicate it is a valid move
                    break;
                } else {
                    break;
                }
            }
        } catch (const out_of_range &e) {}
    } return currMoves;
}

int Castle::GetValue() {
    return value;
}
