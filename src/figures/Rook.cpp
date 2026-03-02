#include "Rook.h"

Rook::Rook(int row, int col, Color color): Piece(row, col, color) {}


constexpr bool Rook::canMove(int new_row, int new_col) const {
    int difRow = new_row - _row;
    int difCol = new_col - _col;
    return (difRow == 0 || difCol == 0);
}

