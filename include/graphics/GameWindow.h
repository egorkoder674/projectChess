#ifndef PROJECT_GAMEWINDOW_H
#define PROJECT_GAMEWINDOW_H

#include "TextureStorage.h"
#include "BoardRenderer.h"
#include <vector>
class GameWindow {
private:
    sf::RenderWindow window;
    TextureStorage textures;
    BoardRenderer renderer;
    std::optional<int> selectedRow;
    std::optional<int> selectedCol;
    std::optional<SimpleMove> lastMove;
    std::vector<std::vector<std::string>> boardState;

    std::string colToLetter(int col) const {
        return std::string(1, 'a' + col);
    }
public:
    GameWindow();
    bool setup();
    void handleClick(int x, int y);
    void handleEvents();
    void draw();
    bool processFrame();
};





#endif //PROJECT_GAMEWINDOW_H