#include "Queen.h"
#include "Empty.h"
#include "Bishop.h"
#include "Castle.h"
#include <stdexcept>
#include <SFML/Graphics.hpp>

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

void Queen::MovePiece(vector<vector<Piece*>>& board, int toRow, int toCol) {
    board.at(toRow).at(toCol) = board.at(row).at(col);          // make the to-spot the queen
    board.at(row).at(col) = new Empty(row, col);                        // make queen's curr spot empty
    row = toRow;    // update row
    col = toCol;    // update col
}

vector<vector<int>> Queen::GetMoves(vector<vector<Piece*>>& board, int lastMove) {
    vector<vector<int>> currMoves;
    currMoves.resize(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currMoves.at(j).push_back(0);
        }
    }

    vector<vector<int>> bishopMoves;        // valid moves by a bishop in the queen's current position
    vector<vector<int>> castleMoves;        // valid moves by a castle in the queen's current position
    vector<vector<Piece*>> newBoard = board;        // copy of current board

    if (value == -5) {
        newBoard.at(row).at(col) = new Bishop(false, row, col);     // make our queen a bishop
        bishopMoves = newBoard.at(row).at(col)->GetMoves(newBoard, -1);    // get that bishop's moves
        newBoard.at(row).at(col) = new Castle(false, row, col);    // make our bishop a castle
        castleMoves = newBoard.at(row).at(col)->GetMoves(newBoard, -1);    // get that castle's moves
    } if (value == 5) {
        newBoard.at(row).at(col) = new Bishop(true, row, col);     // make our queen a bishop
        bishopMoves = newBoard.at(row).at(col)->GetMoves(newBoard, -1);    // get that bishop's moves
        newBoard.at(row).at(col) = new Castle(true, row, col);    // make our bishop a castle
        castleMoves = newBoard.at(row).at(col)->GetMoves(newBoard, -1);    // get that castle's moves
    }

    for (int i = 0; i < 8; i++) {           // add the two move sets together. since castle's and bishops never overlap the value can't be greater than 1
        for (int j = 0; j < 8; j++) {
            currMoves.at(i).at(j) = bishopMoves.at(i).at(j) + castleMoves.at(i).at(j);
        }
    }
    return currMoves;
}

int Queen::GetValue() {
    return value;
}

sf::Sprite Queen::DrawPiece(sf::RenderWindow& window, Images& textures) {
    sf::Sprite sprite;
    if (value == -5) {
        sprite.setTexture(textures.bQueen);
    } else if (value == 5) {
        sprite.setTexture(textures.wQueen);
    }
    sf::Vector2f newSize(66.0f, 66.0f);
    sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(200.0f + (col * 88.0f) + 44, 75.0f + (static_cast<float>(row) * 88.0f) + 44);
    return sprite;
    //window.draw(sprite);
}
