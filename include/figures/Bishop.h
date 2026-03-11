#pragma once
#include "Piece.h"

class Board;

class Bishop : public Piece{
public:
    Bishop(int row, int col, Color color = Color::White);
    bool canMove(int new_row, int new_col, const Board& board) const override;
    ~Bishop() override = default;
};

