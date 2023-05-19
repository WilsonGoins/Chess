#include <iostream>
#include <vector>
#include "Board.h"
#include "Piece.h"
using namespace std;

int main() {
    Board myBoard = Board();

    for (auto col : myBoard.board) {
        cout << "[";
        for (auto row : col) {
            int res = row->GetValue();
            if (res >= 0) {
                cout << " " << res << ", ";
            } else {
                cout << row->GetValue() << ", ";
            }
        }
        cout << "]" << endl;
    }

    cout << endl << endl;

    vector<vector<int>> data = myBoard.board.at(5).at(5)->GetMoves(myBoard.board);
    for (auto col : data) {
        cout << "[";
        for (auto row : col) {
            cout << " " << row << ", ";
        }
        cout << "]" << endl;
    }
    cout << "done!!" << endl;
    return 0;
}

// need to figure out why inner vectors are not populating with 0s