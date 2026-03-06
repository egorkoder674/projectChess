#include "Knight.h"

Knight::Knight(int row, int col, Color color): Piece(row, col, color) {}

constexpr bool Knight::canMove(int new_row, int new_col, const Board& board) const {
    if (new_row == _row && new_col == _col)
        return false;
    int difRow = std::abs(new_row - _row);
    int difCol = std::abs(new_col - _col);
    if (!((difRow == 1 && difCol == 2) || (difRow == 2 && difCol == 1)))
        return false;
    auto& enemy = board.getPiece(new_row, new_col);
    if (std::holds_alternative<Empty>(enemy))
        return true;
    Color enemyColor = std::visit([](auto& el){ return el.getColor(); }, enemy);
    return enemyColor != getColor();
}
