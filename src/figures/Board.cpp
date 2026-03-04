#include "Board.h"

Board::Board(): data(8, std::vector<PieceVariant>(8, Empty())) {
}

constexpr bool Board::isOccupied(int row, int col) const {
    return !std::holds_alternative<Empty>(data[row][col]);
}

const PieceVariant& Board::getPiece(int row, int col) const {
    return data[row][col];
}

// bool Board::cellUnderAttack(int row, int col, Color ColorOfMoved) const {
//     for (int i = 0; i < 8; ++i) {
//         for (int j = 0; j < 8; ++j) {
//             auto& enemy = getPiece(i, j);
//             if (std::holds_alternative<Empty>(enemy))
//                 continue;
//             Color enemyColor = std::visit([](auto& el){ return el.getColor();}, enemy);
//             if (enemyColor != ColorOfMoved) {
//                 bool canAtack = std::visit([](auto& el){ return el.canMove(row, col, *this);}, enemy);
//                 if (canAtack)
//                     return true;
//             }
//         }
//     }
//     return false;
// }
constexpr bool Board::cellUnderAttack(int row, int col, Color ColorOfMoved) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            auto& enemy = getPiece(i, j);
            if (auto* bishop = std::get_if<Bishop>(&enemy)) {
                if (bishop->getColor() != ColorOfMoved && bishop->canMove(row, col, *this))
                    return true;
            } else if (auto* queen = std::get_if<Queen>(&enemy)) {
                if (queen->getColor() != ColorOfMoved && queen->canMove(row, col, *this))
                    return true;
            } else if (auto* rook = std::get_if<Rook>(&enemy)) {
                if (rook->getColor() != ColorOfMoved && rook->canMove(row, col, *this))
                    return true;
            } else if (auto* knight = std::get_if<Knight>(&enemy)) {
                if (knight->getColor() != ColorOfMoved && knight->canMove(row, col, *this))
                    return true;
            } else if (auto* pawn = std::get_if<Pawn>(&enemy)) {
                if (pawn->getColor() != ColorOfMoved && pawn->canMove(row, col, *this))
                    return true;
            } else if (auto* king = std::get_if<King>(&enemy)) {
                if (king->getColor() != ColorOfMoved && king->canMove(row, col, *this))
                    return true;
            }
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
        data[move.getToRow()][move.getToCol()] = pieceMoved;
        data[move.getFromRow()][move.getFromCol()] = Empty();
    }
}