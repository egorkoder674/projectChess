#pragma once
#include "Piece.h"

class Board;

class King : public Piece {
public:
    King(int row, int col, Color color = Color::White);
    bool canMove(int new_row, int new_col, const Board& board) const override;
    ~King() override = default;
};
