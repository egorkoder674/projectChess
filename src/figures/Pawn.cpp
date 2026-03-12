#include "Bishop.h"
#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "Empty.h"
#include "cmath"

Pawn::Pawn(int row, int col, Color color): Piece(row, col, color) {}


bool Pawn::canMove(int new_row, int new_col, const Board &board) const {
    int difRow = new_row - _row;
    int difCol = new_col - _col;
    if (difRow == 0 && difCol == 0) return false;
    if (difCol == 0) {
        if (board.isOccupied(new_row, new_col))
            return false;
        if (getColor() == Color::White) {
            if (!_isMoved && difRow == 2)
                return !board.isOccupied(_row + 1, _col);
            return (difRow == 1);
        } else {
            if (!_isMoved && difRow == -2)
                return !board.isOccupied(_row - 1, _col);
            return (difRow == -1);
        }
    }
    else if (std::abs(difCol) == 1) {
        auto& enemy = board.getPiece(new_row, new_col);
        if (std::holds_alternative<Empty>(enemy))
            return false;

        Color enemyColor = std::visit([](auto& el){ return el.getColor(); }, enemy);
        if (enemyColor == _color)
            return false;

        if (getColor() == Color::White)
            return (difRow == 1);
        return (difRow == -1);
    }
    return false;
}