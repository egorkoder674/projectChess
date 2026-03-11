#pragma once
#include "Color.h"
class Board;
class Piece {
protected:
    int _row;
    int _col;
    Color _color;
    bool _isMoved = false;
public:
    Piece(int row, int col, Color color = Color::White);
    int getRow() const;
    int getCol() const;
    Color getColor() const;
    bool isMoved() const;
    virtual bool canMove(int new_row, int new_col, const Board& board) const = 0;
    virtual ~Piece() = default;
};