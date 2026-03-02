#ifndef PROJECT_FIGURES_H
#include <cmath>

enum class Color {
    White,
    Black
};
class Piece {
protected:
    int _row;
    int _col;
    Color _color;
    bool _isMoved = false;
public:
    Piece(int row, int col, Color color = Color::White);
    constexpr int getRow() const;
    constexpr int getCol() const;
    constexpr Color getColor() const;
    constexpr virtual bool canMove(int new_row, int new_col) const = 0;
    virtual ~Piece() = default;
};
#define PROJECT_FIGURES_H

#endif //PROJECT_FIGURES_H