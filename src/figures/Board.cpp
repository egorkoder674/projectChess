#include "Board.h"

Board::Board(): data(8, std::vector<PieceVariant>(8, Empty())) {
    setupInitialPosition();
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
    if (!isInside(move.getFromRow(), move.getFromCol()) ||
        !isInside(move.getToRow(), move.getToCol()))
        return false;

    auto& pieceMoved = getPiece(move.getFromRow(), move.getFromCol());

    Color movingColor = std::visit([](auto& el) { return el.getColor(); }, pieceMoved);
    if (movingColor != currentPlayer)
        return false;

    if (!std::holds_alternative<Empty>(data[move.getToRow()][move.getToCol()])) {

        Color movingColor = std::visit([](auto& el) { return el.getColor(); }, pieceMoved);
        Color targetColor = std::visit([](auto& el) { return el.getColor(); }, data[move.getToRow()][move.getToCol()]);

        if (movingColor == targetColor)
            return false;
    }

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

    Board tempBoard = *this;
    tempBoard.makeMove(move);
    int kingRow = -1;
    int kingCol = -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            auto& piece = tempBoard.getPiece(i, j);

            if (std::holds_alternative<King>(piece)) {

                Color kingColor = std::get<King>(piece).getColor();

                if (kingColor == movingColor) {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }
    }

    if (tempBoard.cellUnderAttack(kingRow, kingCol, movingColor))
        return false;

    return false;
}

void Board::makeMove(const Move &move) {
    if (!isLegalMove(move))
        return;
    int fromRow = move.getFromRow();
    int fromCol = move.getFromCol();
    int toRow = move.getToRow();
    int toCol = move.getToCol();

    PieceVariant piece = data[fromRow][fromCol];

    currentPlayer = (currentPlayer == Color::White) ? Color::Black : Color::White;

    data[fromRow][fromCol] = Empty();
    data[toRow][toCol] = piece;
    std::visit([&](auto& el) {
        using T = std::decay_t<decltype(el)>;
        if constexpr (!std::is_same_v<T, Empty>) {
            el = T(toRow, toCol, el.getColor());
        }
    }, data[toRow][toCol]);
}

void Board::setPiece(int row, int col, const PieceVariant& piece) {
    data[row][col] = piece;
}

bool Board::isInside(int row, int col) const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

void Board::setupInitialPosition() {
    for (int col = 0; col < 8; col++) {
        setPiece(1, col, Pawn(1, col, Color::White));
        setPiece(6, col, Pawn(6, col, Color::Black));
    }
    setPiece(0,0, Rook(0,0,Color::White));
    setPiece(0,7, Rook(0,7,Color::White));
    setPiece(7,0, Rook(7,0,Color::Black));
    setPiece(7,7, Rook(7,7,Color::Black));
    setPiece(0,1, Knight(0,1,Color::White));
    setPiece(0,6, Knight(0,6,Color::White));
    setPiece(7,1, Knight(7,1,Color::Black));
    setPiece(7,6, Knight(7,6,Color::Black));
    setPiece(0,2, Bishop(0,2,Color::White));
    setPiece(0,5, Bishop(0,5,Color::White));
    setPiece(7,2, Bishop(7,2,Color::Black));
    setPiece(7,5, Bishop(7,5,Color::Black));
    setPiece(0,3, Queen(0,3,Color::White));
    setPiece(7,3, Queen(7,3,Color::Black));
    setPiece(0,4, King(0,4,Color::White));
    setPiece(7,4, King(7,4,Color::Black));
}
