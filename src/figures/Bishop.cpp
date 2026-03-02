#include "Bishop.h"

Bishop::Bishop(int row, int col, Color color): Piece(row, col, color) {}

constexpr bool Bishop::canMove(int new_row, int new_col) const {
    int difRow = std::abs(new_row - _row);
    int difCol = std::abs(new_col - _col);
    return (difRow == difCol);
}


