#include "BoardRenderer.h"
BoardRenderer::BoardRenderer(const TextureStorage &texStor): textures(texStor),
boardState(8, std::vector<std::string>(8, "")) {}

void BoardRenderer::setBoardSprite(const sf::Sprite &sprite) {
    boardSprite = sprite;
}
void BoardRenderer::updateBoard(const std::vector<std::vector<std::string>>& newState) {
    if (newState.size() != 8) {
        std::cout << "BoardRenderer: incorrect number oof rows\n";
    }
    for (const auto& row: newState) {
        if (row.size() != 8) {
            std::cout << "BoardRenderer: row with incorrect length\n";
            return;
        }
    }
    boardState = newState;
}
