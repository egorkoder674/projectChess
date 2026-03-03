//
// Created by admin on 27.02.2026.
//

#ifndef PROJECT_BISHOP_H
#define PROJECT_BISHOP_H
#include "Piece.h"
#include "Board.h"

class Bishop : public Piece{
public:
    Bishop(int row, int col, Color color = Color::White);
    constexpr bool canMove(int new_row, int new_col, const Board& board) const override;
    ~Bishop() override = default;
};

#endif //PROJECT_BISHOP_H

