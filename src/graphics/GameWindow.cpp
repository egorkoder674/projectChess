#include <GameWindow.h>
GameWindow::GameWindow():window(sf::VideoMode({800, 800}), "Chess"), renderer(textures),
boardState(8, std::vector<std::string>(8, "")) {};


