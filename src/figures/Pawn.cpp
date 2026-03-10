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

    if (difRow ==  0 && difCol == 0)
        return false;
    if (difCol == 0) {
        if (!std::holds_alternative<Empty>(board.getPiece(new_row, new_col)))
            return false;
        if (!_isMoved) {
            if (getColor() == Color::White) {
                if (difRow == -2)
                    return (!board.isOccupied(_row-1, _col));
                if (difRow == -1)
                    return true;
            } else {
                if (difRow == 2)
                    return (!board.isOccupied(_row+1, _col));
                if (difRow == 1)
                    return true;
            }
        } else {
            if (getColor() == Color::White && difRow == -1)
                return true;
            else if (getColor() == Color::Black && difRow == 1)
                return true;
        }
        return false;
    }
    else if (difCol == 1 || difCol == -1) {
        if (!_isMoved) {
            if (getColor() == Color::White) {
                if (difRow == -1) {
                    auto& enemy = board.getPiece(new_row, new_col);
                    if (!std::holds_alternative<Empty>(enemy)) {
                        Color enemyColor = std::visit([](auto& el){ return el.getColor();}, enemy);
                        return( enemyColor != _color);
                    }
                }

            } else {
                if (difRow == 1) {
                    auto& enemy = board.getPiece(new_row, new_col);
                    if (!std::holds_alternative<Empty>(enemy)) {
                        Color enemyColor = std::visit([](auto& el){ return el.getColor();}, enemy);
                        return( enemyColor != _color);
                    }
                }
            }
        }
    }
}