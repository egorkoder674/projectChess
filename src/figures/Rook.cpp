#include "Bishop.h"
#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "Empty.h"
#include "cmath"

Rook::Rook(int row, int col, Color color): Piece(row, col, color) {}


bool Rook::canMove(int new_row, int new_col, const Board& board) const {
    int difRow = new_row - _row;
    int difCol = new_col - _col;
    if ((difRow != 0 && difCol != 0) || (difRow == 0 && difCol == 0))
        return false;

    int stepRow = (difRow == 0) ? 0 : (difRow > 0) ? 1 : -1;
    int stepCol = (difCol == 0) ? 0 : (difCol > 0) ? 1 : -1;
    int curRow = _row + stepRow;
    int curCol = _col + stepCol;

    while (curRow != new_row || curCol != new_col) {
        if (board.isOccupied(curRow, curCol))
            return false;
        curRow += stepRow;
        curCol += stepCol;
    }
    auto& enemy = board.getPiece(new_row, new_col);
    if (std::holds_alternative<Empty>(enemy))
        return true;
    Color enemyColor = std::visit([](auto& el){return el.getColor();}, enemy);
    return getColor() != enemyColor;
}

