#pragma once
#include "Piece.h"

class Board;

class Pawn : public Piece {
public:
    Pawn(int row, int col, Color color);
    bool canMove(int new_row, int new_col, const Board& board) const override;
    ~Pawn() override = default;
};
