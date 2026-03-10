#include "../include/Board.h"
#include "../include/Move.h"
#include "../include/Position.h"

Board::Board() : currentTurn_(Color::White)
{
    for (auto& row : board_) {
        for (auto& cell : row) {
            cell = nullptr;
        }
    }
}

const Piece* Board::getPiece(const Position& pos) const {
    if (!isInside(pos))
        return nullptr;
    return board_[pos.row()][pos.col()].get();
}

void Board::movePiece(const Position& from, const Position& to)
{
    board_[to.row()][to.col()] = std::move(board_[from.row()][from.col()]);
}

bool Board::tryMove(const Move& move)
{
    Position from = move.from();
    Position to   = move.to();
    if (!isInside(from) || !isInside(to))
        return false;
    if (!board_[from.row()][from.col()])
        return false;
    movePiece(from, to);
    currentTurn_ = (currentTurn_ == Color::White)
                   ? Color::Black
                   : Color::White;
    return true;
}