#include "BoardRenderer.h"
BoardRenderer::BoardRenderer(const TextureStorage &texStor): textures(texStor),
boardState(8, std::vector<std::string>(8, "")) {}

void BoardRenderer::setBoardSprite(const sf::Sprite &sprite) {
    boardSprite = sprite;
}



