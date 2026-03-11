#include "Piece.h"

Piece::Piece(int row, int col, Color color): _row(row), _col(col), _color(color){}

int Piece::getRow() const {
    return _row;
}

int Piece::getCol() const {
    return _col;
}

Color Piece::getColor() const {
    return _color;
}

bool Piece::isMoved() const {
    return _isMoved;
}