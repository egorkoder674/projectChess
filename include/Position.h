#pragma once

#include <compare>

class Position {
    int row_;
    int col_;
public:
    constexpr Position(int row, int col) noexcept : row_(row), col_(col) {}
    constexpr int row() const noexcept { return row_; }
    constexpr int col() const noexcept { return col_; }
    auto operator<=>(const Position&) const = default;
};
