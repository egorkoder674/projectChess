#pragma once
#include "Piece.h"

class Board;

class Rook : public Piece {
public:
    Rook(int row, int col, Color color);
    bool canMove(int new_row, int new_col, const Board& board) const override;
    ~Rook() override = default;
};
