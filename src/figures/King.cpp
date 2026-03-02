#include "King.h"

King::King(int row, int col, Color color): Piece(row, col, color) {}

constexpr bool King::canMove(int new_row, int new_col) const {
    int difRow = new_row - _row;
    int difCol = new_col - _col;
    return (std::abs(difRow) <= 1 && std::abs(difCol) <= 1);
}

