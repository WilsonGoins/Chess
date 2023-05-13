#include <iostream>
#include <vector>
#include "Board.h"
#include "Piece.h"
using namespace std;

int main() {
    Board myBoard = Board();
    cout << "here" << endl;
    for (auto col : myBoard.board) {
        cout << "[";
        for (auto row : col) {
            cout << row->GetValue() << ", ";
        }
        cout << "]" << endl;
    }
}