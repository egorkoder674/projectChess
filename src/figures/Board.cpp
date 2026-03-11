#include "Board.h"

Board::Board(): data(8, std::vector<PieceVariant>(8, Empty())) {
}

bool Board::isOccupied(int row, int col) const {
    return !std::holds_alternative<Empty>(data[row][col]);
}

const PieceVariant& Board::getPiece(int row, int col) const {
    return data[row][col];
}
bool Board::cellUnderAttack(int row, int col, Color ColorOfMoved) const {
    Board tempBoard = *this;
    tempBoard.setPiece(row, col, Empty());
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            auto& enemy = tempBoard.getPiece(i, j);
            if (std::holds_alternative<Empty>(enemy))
                continue;
            Color enemyColor = std::visit([](auto& el) { return el.getColor();}, enemy);
            if (enemyColor == ColorOfMoved)
                continue;
            bool attacks = std::visit([&](auto& el) {
                if (std::is_same_v<std::decay_t<decltype(el)>, Pawn>) {
                    int difRow = (row - i);
                    int difCol = std::abs(col - j);
                    int stepRow = (el.getColor() == Color::White) ? 1 : -1;
                    return difRow == stepRow && difCol == 1;
                }
                else if (std::is_same_v<std::decay_t<decltype(el)>, King>) {
                    return std::abs(row - i) <= 1 && std::abs(col - j) <= 1;
                }
                else {
                    return el.canMove(row, col, tempBoard);
                }
            }, enemy);
            if (attacks) return true;
        }
    }

    return false;
}


bool Board::isLegalMove(const Move &move) {
    auto& pieceMoved = getPiece(move.getFromRow(), move.getFromCol());
    if (auto* bishop = std::get_if<Bishop>(&pieceMoved)) {
        return bishop->canMove(move.getToRow(), move.getToCol(), *this);
    }
    else if (auto* queen = std::get_if<Queen>(&pieceMoved)) {
        return queen->canMove(move.getToRow(), move.getToCol(), *this);
    }
    else if (auto* king = std::get_if<King>(&pieceMoved)) {
        return king->canMove(move.getToRow(), move.getToCol(), *this);
    }
    else if (auto* knight = std::get_if<Knight>(&pieceMoved)) {
        return knight->canMove(move.getToRow(), move.getToCol(), *this);
    }
    else if (auto* rook = std::get_if<Rook>(&pieceMoved)) {
        return rook->canMove(move.getToRow(), move.getToCol(), *this);
    }
    else if (auto* pawn = std::get_if<Pawn>(&pieceMoved)) {
        return pawn->canMove(move.getToRow(), move.getToCol(), *this);
    }
    return false;
}


void Board::makeMove(const Move &move) {
    if (isLegalMove(move)) {
        auto& pieceMoved = getPiece(move.getFromRow(), move.getFromCol());
        if (std::holds_alternative<Empty>(pieceMoved))
            return;
        if (std::holds_alternative<King>(pieceMoved)) {
            if (std::abs(move.getFromRow() - move.getToRow()) == 2) {

            }
        }
    }
}

void Board::setPiece(int row, int col, const PieceVariant& piece) {
    data[row][col] = piece;
}
