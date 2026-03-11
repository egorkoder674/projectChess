//
// Created by admin on 02.03.2026.
//

#ifndef PROJECT_EMPTY_H
#define PROJECT_EMPTY_H
#include "Color.h"

class Board;

class Empty {
public:
    Color getColor() const{
        return Color::Empty;
    }
    bool canMove(int x, int y, const Board& board) const {
        return false;
    }
    ~Empty() = default;
};

#endif //PROJECT_EMPTY_H