#include "Piece.h"

Piece::Piece(int row, int col, Color color): _row(row), _col(col), _color(color){}

int Piece::getRow() const {
    return _row;
}

void Piece::setRow(int r) {
    _row = r;
}

int Piece::getCol() const {
    return _col;
}

void Piece::setCol(int c) {
    _col = c;
}

Color Piece::getColor() const {
    return _color;
}

bool Piece::isMoved() const {
    return _isMoved;
}

void Piece::setMoved(bool m) {
    _isMoved = m;
}