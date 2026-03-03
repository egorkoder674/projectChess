#ifndef PROJECT_PAWN_H
#define PROJECT_PAWN_H
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece {
public:
    Pawn(int row, int col, Color color);
    constexpr bool canMove(int new_row, int new_col, const Board& board) const;
    constexpr bool isMoved() const;
    ~Pawn() override = default;
};
#define PROJECT_PAWN_H

#endif //PROJECT_PAWN_H