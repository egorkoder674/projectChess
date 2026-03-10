#include <GameWindow.h>
GameWindow::GameWindow():window(sf::VideoMode({800, 800}), "Chess"), renderer(textures),
boardState(8, std::vector<std::string>(8, "")) {};

bool GameWindow::setup() {
    if (!textures.load("board", "Board.png"))
        return false;

    textures.load("w_pawn",   "W_Pawn.png");
    textures.load("w_rook",   "W_Rook.png");
    textures.load("w_knight", "W_Knight.png");
    textures.load("w_bishop", "W_Bishop.png");
    textures.load("w_queen",  "W_Queen.png");
    textures.load("w_king",   "W_King.png");

    textures.load("b_pawn",   "B_Pawn.png");
    textures.load("b_rook",   "B_Rook.png");
    textures.load("b_knight", "B_Knight.png");
    textures.load("b_bishop", "b_Bishop.png");
    textures.load("b_queen",  "B_Queen.png");
    textures.load("b_king",   "B_King.png");

    auto boardSpriteOpt = textures.getSprite("board");
    if (boardSpriteOpt.has_value()) {
        renderer.setBoardSprite(boardSpriteOpt.value());
    }
    else {
        std::cout << "Error with getting sprite\n";
        return false;
    }

    return true;

}


void GameWindow::handleClick(int x, int y) {
    int screenRow = y / renderer.getCellSize();
    int screenCol = x / renderer.getCellSize();
    if (screenRow < 0 || screenRow >= 8 || screenCol < 0 || screenCol >= 8) return;

    int internalRow = 7 - screenRow;
    int internalCol = screenCol;

    if (!selectedRow.has_value()) {
        if (!boardState[internalRow][internalCol].empty()) {
            selectedRow = internalRow;
            selectedCol = internalCol;
            std::cout << "The figure was chosen from " << colToLetter(internalCol)
                          << (internalRow + 1) << "\n";
        }
    }
    else {
        if (*selectedRow == internalRow && *selectedCol == internalCol) {
            selectedRow.reset();
            selectedCol.reset();
            return;
        }
        lastMove = SimpleMove{*selectedRow, *selectedCol, internalRow, internalCol};
        std::cout << "Move from " << colToLetter(*selectedCol) << (*selectedRow + 1) << " to "
        << colToLetter(internalCol) << (internalRow + 1) << "\n";

        boardState[internalRow][internalCol] = boardState[*selectedRow][*selectedCol];
        boardState[*selectedRow][*selectedCol] = "";
        renderer.updateBoard(boardState);

        selectedRow.reset();
        selectedCol.reset();
    }
}

void GameWindow::handleEvents() {
    while (auto optEvent = window.pollEvent()) {
        const sf::Event& event = *optEvent;

        if (event.is<sf::Event::Closed>()) {
            window.close();
        }
        else if (auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                handleClick(mousePressed->position.x, mousePressed->position.y);
            }
        }
    }
}

