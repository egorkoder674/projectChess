//
// Created by admin on 02.03.2026.
//

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H
#include <vector>
#include "allfigures.h"
#include "Move.h"

class Board {
    std::vector<std::vector<PieceVariant>> data;
public:
    Board();
    constexpr bool isOccupied(int row, int col) const;
    const PieceVariant& getPiece(int row, int col) const;
    constexpr bool cellUnderAttack(int row, int col, Color ColorOfMoved) const;
    void makeMove(const Move& move);
    bool isLegalMove(const Move& move);
};

#endif //PROJECT_BOARD_H