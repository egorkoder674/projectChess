#include "TextureStorage.h"
bool TextureStorage::load(const std::string &name, const std::string &filename) {
    auto tex = std::make_unique<sf::Texture>();
    if (!tex->loadFromFile(filename)) {
        std::cout << "Loading error " << filename << std::endl;
        return false;
    }
    textures[name] = std::move(tex);
    return true;
}

std::optional<sf::Sprite> TextureStorage::getSprite(const std::string &name) const {
    auto it = textures.find(name);
    if (it != textures.end()) {
        return sf::Sprite(*it->second);
    }
    return std::nullopt;
}

