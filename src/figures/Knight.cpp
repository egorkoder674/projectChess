#include "Knight.h"

Knight::Knight(int row, int col, Color color): Piece(row, col, color) {}

constexpr bool Knight::canMove(int new_row, int new_col) const {
    int difRow = std::abs(new_row - _row);
    int difCol = std::abs(new_col - _col);
    return ((difRow == 1 && difCol == 2) || (difRow == 2 && difCol == 1));
}
