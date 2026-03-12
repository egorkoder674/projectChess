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


bool Board::isLegalMove(const Move &move) const {
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
    if (!isLegalMove(move))
        return;

    PieceVariant piece = getPiece(move.getFromRow(), move.getFromCol());

    if (std::holds_alternative<Empty>(piece))
        return;

    Color pieceColor = std::visit([](auto& el) { return el.getColor(); }, piece);


    if (pieceColor != currentPlayer)
        return;

    // создаём временную доску
    Board tempBoard = *this;

    // делаем ход на временной доске
    tempBoard.setPiece(move.getToRow(), move.getToCol(), piece);
    tempBoard.setPiece(move.getFromRow(), move.getFromCol(), Empty());

    // ищем короля
    int kingRow = -1;
    int kingCol = -1;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            auto& p = tempBoard.getPiece(i, j);

            if (std::holds_alternative<King>(p)) {
                Color c = std::get<King>(p).getColor();

                if (c == pieceColor) {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }
    }

    // если после хода король под шахом — запрещаем ход
    if (tempBoard.cellUnderAttack(kingRow, kingCol, pieceColor))
        return;

    // рокировка
    if (auto* king = std::get_if<King>(&piece)) {
        int difCol = move.getToCol() - move.getFromCol();
        if (std::abs(difCol) == 2) {
            int r = move.getFromRow();
            int oldRookCol = (difCol > 0) ? 7 : 0;
            int newRookCol = (difCol > 0) ? 5 : 3;

            PieceVariant rook = getPiece(r, oldRookCol);
            std::visit([&](auto& rk) {
                using T = std::decay_t<decltype(rk)>;
                if constexpr (!std::is_same_v<T, Empty>) {
                    rk.setRow(r);
                    rk.setCol(newRookCol);
                    rk.setMoved(true);
                }
            }, rook);
            setPiece(r, newRookCol, rook);
            setPiece(r, oldRookCol, Empty());
        }
    }

    // обновляем координаты фигуры
    std::visit([&](auto& p) {
        using T = std::decay_t<decltype(p)>;
        if constexpr (!std::is_same_v<T, Empty>) {
            p.setRow(move.getToRow());
            p.setCol(move.getToCol());
            p.setMoved(true);
        }
    }, piece);

    setPiece(move.getToRow(), move.getToCol(), piece);
    setPiece(move.getFromRow(), move.getFromCol(), Empty());
    currentPlayer = (currentPlayer == Color::White)
                    ? Color::Black
                    : Color::White;
}

void Board::setPiece(int row, int col, const PieceVariant& piece) {
    data[row][col] = piece;
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

bool Board::isCheckmate(Color color) {

    int kingRow = -1;
    int kingCol = -1;

    // ищем короля
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            const auto& piece = getPiece(i, j);

            if (std::holds_alternative<King>(piece)) {

                const King& king = std::get<King>(piece);

                if (king.getColor() == color) {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }
    }

    // если шаха нет — это не мат
    if (!cellUnderAttack(kingRow, kingCol, color))
        return false;

    // проверяем все возможные ходы
    for (int r1 = 0; r1 < 8; ++r1) {
        for (int c1 = 0; c1 < 8; ++c1) {
            const auto& piece = getPiece(r1, c1);
            if (std::holds_alternative<Empty>(piece))
                continue;
            Color pieceColor = std::visit([](auto& el){ return el.getColor(); }, piece);
            if (pieceColor != color)
                continue;
            for (int r2 = 0; r2 < 8; ++r2) {
                for (int c2 = 0; c2 < 8; ++c2) {
                    Move move(r1, c1, r2, c2);
                    if (!isLegalMove(move))
                        continue;
                    Board temp = *this;
                    temp.makeMove(move);
                    int kr = -1, kc = -1;
                    for (int i = 0; i < 8; ++i) {
                        for (int j = 0; j < 8; ++j) {
                            const auto& p = temp.getPiece(i, j);
                            if (std::holds_alternative<King>(p)) {
                                const King& k = std::get<King>(p);
                                if (k.getColor() == color) {
                                    kr = i;
                                    kc = j;
                                }
                            }
                        }
                    }
                    if (!temp.cellUnderAttack(kr, kc, color))
                        return false;
                }
            }
        }
    }
    return true;
}

bool Board::isStalemate(Color color) const {

    int kingRow = -1;
    int kingCol = -1;

    // ищем короля
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            const auto& piece = getPiece(i, j);

            if (std::holds_alternative<King>(piece)) {

                const King& king = std::get<King>(piece);

                if (king.getColor() == color) {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }
    }

    // если король под шахом — это не пат
    if (cellUnderAttack(kingRow, kingCol, color))
        return false;

    // проверяем есть ли хотя бы один ход
    for (int r1 = 0; r1 < 8; ++r1) {
        for (int c1 = 0; c1 < 8; ++c1) {

            const auto& piece = getPiece(r1, c1);

            if (std::holds_alternative<Empty>(piece))
                continue;

            Color pieceColor = std::visit([](auto& el){ return el.getColor(); }, piece);

            if (pieceColor != color)
                continue;

            for (int r2 = 0; r2 < 8; ++r2) {
                for (int c2 = 0; c2 < 8; ++c2) {

                    Move move(r1, c1, r2, c2);

                    if (isLegalMove(move))
                        return false;
                }
            }
        }
    }

    return true;
}