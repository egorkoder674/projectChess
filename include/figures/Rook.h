//
// Created by admin on 27.02.2026.
//

#ifndef PROJECT_ROOK_H
#define PROJECT_ROOK_H
#include "Piece.h"

class Rook : public Piece {
public:
    Rook(int row, int col, Color color);
    constexpr bool canMove(int new_row, int new_col) const override;
};
#endif //PROJECT_ROOK_H