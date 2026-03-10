#pragma once

#include <array>
#include <memory>
#include <vector>

#include "Move.h"

class Piece;

enum class Color {
    White,
    Black
};

class Board {
    static constexpr int boardSize_ = 8;
    std::array<std::array<std::unique_ptr<Piece>, boardSize_>, boardSize_> board_;
    Color currentTurn_;
    bool isInside(const Position& pos) const noexcept;
public:
    Board();
    bool tryMove(const Move& move);
    std::vector<Move> getLegalMoves(Color color) const;
    const Piece* getPiece(const Position& pos) const;
    void movePiece(const Position& from, const Position& to);
};