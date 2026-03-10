#pragma once
#include "Piece.h"

class Board;

class Knight : public Piece {
public:
    Knight(int row, int col, Color color);
    bool canMove(int new_row, int new_col, const Board& board) const override;
    ~Knight() override = default;
};
