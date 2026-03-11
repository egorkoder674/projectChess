#include "Move.h"

Move::Move(int fromRow, int fromCol, int toRow, int toCol) :
_fromRow(fromRow),
_fromCol(fromCol),
_toRow(toRow),
_toCol(toCol){}

int Move::getFromRow() const {
    return _fromRow;
}

int Move::getFromCol() const {
    return _fromCol;
}

int Move::getToRow() const {
    return _toRow;
}

int Move::getToCol() const {
    return _toCol;
}

