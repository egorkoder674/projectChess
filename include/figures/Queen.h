#pragma once
#include "Piece.h"

class Board;

class Queen : public Piece{
public:
    Queen(int row, int col, Color color);
    bool canMove(int new_row, int new_col, const Board& board) const override;
    ~Queen() override = default;
};
