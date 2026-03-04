#include "Move.h"

Move::Move(int fromRow, int fromCol, int toRow, int toCol) :
_fromRow(fromRow),
_fromCol(fromCol),
_toRow(toRow),
_toCol(toCol){}

constexpr int Move::getFromRow() const {
    return _fromRow;
}

constexpr int Move::getFromCol() const {
    return _fromCol;
}

constexpr int Move::getToRow() const {
    return _toRow;
}

constexpr int Move::getToCol() const {
    return _toCol;
}

