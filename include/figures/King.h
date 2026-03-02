//
// Created by admin on 27.02.2026.
//

#ifndef PROJECT_KING_H
#define PROJECT_KING_H
#include "Piece.h"

class King : public Piece {
public:
    King(int row, int col, Color color = Color::White);
    constexpr bool canMove(int new_row, int new_col) const override;
};
#endif //PROJECT_KING_H