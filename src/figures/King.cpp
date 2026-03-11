#include "Bishop.h"
#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "Empty.h"
#include "cmath"

King::King(int row, int col, Color color): Piece(row, col, color) {}

bool King::canMove(int new_row, int new_col, const Board& board) const {
    int difRow = new_row - _row;
    int difCol = new_col - _col;
    if (difRow == 0 && 0 == difCol)
        return false;
    //просто ход
    if (std::abs(difRow) <= 1 && std::abs(difCol) <= 1) {
        if (board.cellUnderAttack(new_row, new_col, getColor()))
            return false;
        auto& enemy = board.getPiece(new_row, new_col);
        if (std::holds_alternative<Empty>(enemy))
            return true;
        Color enemyColor = std::visit([](auto& el){ return el.getColor();}, enemy);
        return (_color != enemyColor);
    }
    //ракировка
    if (std::abs(difCol) == 2 && !_isMoved && !board.cellUnderAttack(_row, _col, _color)) {
        if (difCol > 0 && !board.isOccupied(_row, _col+1) && !board.isOccupied(_row, _col+2)) {
            auto& isRook = board.getPiece(_row, _col+3);
            if (auto* rook = std::get_if<Rook>(&isRook)) {
                if (!rook->isMoved() &&
                    !board.cellUnderAttack(_row, _col + 1, _color) &&
                    !board.cellUnderAttack(_row, _col + 2, _color))
                    return true;
            }
        }
        if (difCol < 0 && !board.isOccupied(_row, _col-1) && !board.isOccupied(_row, _col-2)
            && !board.isOccupied(_row, _col-3)) {
            auto& isRook = board.getPiece(_row, _col-4);
            if (auto* rook = std::get_if<Rook>(&isRook)) {
                if (!rook->isMoved() &&
                !board.cellUnderAttack(_row, _col - 1, _color) &&
                !board.cellUnderAttack(_row, _col - 2, _color) &&
                !board.cellUnderAttack(_row, _col - 3, _color))
                    return true;
            }
        }
    }
    return false;
}

