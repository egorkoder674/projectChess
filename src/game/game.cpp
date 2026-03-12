#include "Game.h"
#include "Board.h"

Game::Game() : board(), boardView(8, std::vector<std::string>(8, "")) {
    board.setupInitialPosition();
    rebuildBoardView();
}

void Game::click(int row, int col) {
    if (gameOver)
        return;
    if (!selectedRow.has_value()) {
        if (board.isOccupied(row, col)) {
            selectedRow = row;
            selectedCol = col;
        }
        return;
    }
    if (*selectedRow == row && *selectedCol == col) {
        selectedRow.reset();
        selectedCol.reset();
        return;
    }
    Move move(*selectedRow, *selectedCol, row, col);
    if (board.isLegalMove(move)) {
        board.makeMove(move);
        rebuildBoardView();
        // проверяем мат
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {

                const auto& piece = board.getPiece(r, c);

                if (std::holds_alternative<King>(piece)) {

                    Color kingColor = std::get<King>(piece).getColor();

                    if (board.cellUnderAttack(r, c, kingColor)) {
                        gameOver = true;
                    }
                }
            }
        }
    }
    selectedRow.reset();
    selectedCol.reset();
}

void Game::rebuildBoardView() {
    for (auto& row : boardView)
        for (auto& cell : row)
            cell.clear();

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {

            const auto& piece = board.getPiece(row, col);

            if (!std::holds_alternative<Empty>(piece)) {
                boardView[row][col] = pieceToTexture(piece);
            }
        }
    }
}

std::string Game::pieceToTexture(const PieceVariant& piece) const {
    return std::visit([](auto& p) -> std::string {
        using T = std::decay_t<decltype(p)>;
        if (std::is_same_v<T, Empty>)
            return "";
        std::string color = (p.getColor() == Color::White) ? "w_" : "b_";
        if (std::is_same_v<T, Pawn>)
            return color + "pawn";
        if (std::is_same_v<T, Rook>)
            return color + "rook";
        if (std::is_same_v<T, Knight>)
            return color + "knight";
        if (std::is_same_v<T, Bishop>)
            return color + "bishop";
        if (std::is_same_v<T, Queen>)
            return color + "queen";
        if (std::is_same_v<T, King>)
            return color + "king";
        return "";
    }, piece);
}

const std::vector<std::vector<std::string>>& Game::getBoardView() const {
    return boardView;
}

std::optional<std::pair<int,int>> Game::getSelected() const {
    if (!selectedRow) return std::nullopt;
    return std::make_pair(*selectedRow, *selectedCol);
}