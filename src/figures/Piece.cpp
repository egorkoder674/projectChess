#include "Piece.h"

Piece::Piece(int row, int col, Color color): _row(row), _col(col), _color(color){}

constexpr int Piece::getRow() const {
    return _row;
}

constexpr int Piece::getCol() const {
    return _col;
}

constexpr Color Piece::getColor() const {
    return _color;
}

