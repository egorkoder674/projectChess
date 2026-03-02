//
// Created by admin on 27.02.2026.
//

#ifndef PROJECT_KNIGHT_H
#define PROJECT_KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(int row, int col, Color color);
    constexpr bool canMove(int new_row, int new_col) const override;
    ~Knight() override = default;

};
#endif //PROJECT_KNIGHT_H