#ifndef PROJECT_GAMEWINDOW_H
#define PROJECT_GAMEWINDOW_H

#include "Board.h"
#include "TextureStorage.h"
#include "BoardRenderer.h"
#include <vector>
#include "game.h"
#include <SFML/Graphics.hpp>

class GameWindow {
private:
    sf::RenderWindow window;
    TextureStorage textures;
    BoardRenderer renderer;
    Game game;
    std::optional<SimpleMove> lastMove;
    std::vector<std::vector<std::string>> boardState;
    std::string colToLetter(int col) const {
        return std::string(1, 'a' + col);
    }
public:
    sf::Font font;
    sf::Text checkmateText;
    sf::Text stalemateText;
    GameWindow();
    bool setup();
    void handleClick(int x, int y);
    void handleEvents();
    void draw();
    bool processFrame();
};
#endif //PROJECT_GAMEWINDOW_H