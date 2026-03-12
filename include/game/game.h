#pragma once
#include "Board.h"
#include <vector>
#include <string>
#include <optional>

class Game {
    Board board;
    bool gameOver = false;

    std::optional<int> selectedRow;
    std::optional<int> selectedCol;
    std::vector<std::vector<std::string>> boardView;
    void rebuildBoardView();
    std::string pieceToTexture(const PieceVariant& piece) const;
public:
    bool isGameOver() const { return gameOver; }
    Game();
    void click(int row, int col);
    const std::vector<std::vector<std::string>>& getBoardView() const;
    std::optional<std::pair<int,int>> getSelected() const;
};