#ifndef PROJECT_BOARDRENDERER_H
#define PROJECT_BOARDRENDERER_H

#include <vector>
#include "TextureStorage.h"
class BoardRenderer {
private:
    const TextureStorage& textures;
    const int cellSize = 100;
    std::optional<sf::Sprite> boardSprite;
    std::vector<std::vector<std::string>> boardState;
public:
    BoardRenderer(const TextureStorage& texStor);
    void setBoardSprite(const sf::Sprite& sprite);
};



#endif //PROJECT_BOARDRENDERER_H

