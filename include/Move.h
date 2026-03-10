#pragma once

#include "Position.h"
#include <compare>

class Move {
    Position from_;
    Position to_;
public:
    constexpr Move(Position from, Position to) noexcept {};
    constexpr const Position& from() const noexcept {}
    constexpr const Position& to() const noexcept {}
    auto operator<=>(const Move&) const = default;
};
