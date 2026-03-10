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

