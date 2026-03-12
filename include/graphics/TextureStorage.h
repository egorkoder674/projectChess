#ifndef PROJECT_TEXTURESTORAGE_H
#define PROJECT_TEXTURESTORAGE_H

#include <memory>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>
#include <optional>
#include <iostream>

class TextureStorage {
private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
public:
    bool load(const std::string& name, const std::string& filename);
    std::optional<sf::Sprite> getSprite(const std::string& name) const;
};
#endif //PROJECT_TEXTURESTORAGE_H