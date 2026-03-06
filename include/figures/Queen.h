//
// Created by admin on 27.02.2026.
//

#ifndef PROJECT_QUEEN_H
#define PROJECT_QUEEN_H
#include "Piece.h"
#include "Board.h"

class Queen : public Piece{
public:
    Queen(int row, int col, Color color);
    constexpr bool canMove(int new_row, int new_col, const Board& board) const override;
    ~Queen() override = default;
};
#endif //PROJECT_QUEEN_H