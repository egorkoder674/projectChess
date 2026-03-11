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

void BoardRenderer::draw(sf::RenderTarget &target) const {
    if (boardSprite.has_value()) {
        target.draw(boardSprite.value());
    }
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            const std::string& pieceName = boardState[row][col];
            if (!pieceName.empty()) {
                auto spriteOpt = textures.getSprite(pieceName);
                if (spriteOpt.has_value()) {
                    sf::Sprite sprite = spriteOpt.value();

                    sf::FloatRect bounds = sprite.getLocalBounds();
                    float offsetX = (cellSize - bounds.size.x) / 2.0f;
                    float offsetY = (cellSize - bounds.size.y) / 2.0f;
                    int invertedRow = 7 - row;

                    sprite.setPosition(sf::Vector2f(col * cellSize + offsetX, invertedRow * cellSize + offsetY));
                    target.draw(sprite);
                }
                else {
                    std::cout << "BoardRenderer: undefined figure name: " << pieceName << "'\n";
                }
            }
        }
    }
}

void BoardRenderer::drawHighlight(sf::RenderTarget &target, int row, int col, const sf::Color &color) const {
    int invertedRow = 7 - row;
    sf::RectangleShape highlight(sf::Vector2f(cellSize - 5, cellSize - 5));

    highlight.setPosition(sf::Vector2f(static_cast<float>(col * cellSize + 2.5f), static_cast<float>(invertedRow * cellSize + 2.5f)));

    highlight.setFillColor(color);
    target.draw(highlight);
}

int BoardRenderer::getCellSize() const {
    return cellSize;
}


