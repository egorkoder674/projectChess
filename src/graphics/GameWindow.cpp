#include <GameWindow.h>

GameWindow::GameWindow()
        : window(sf::VideoMode({800, 800}), "Chess"),
          renderer(textures),
          boardState(8, std::vector<std::string>(8, "")),
          checkmateText(font)
{}

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
    if (!boardSpriteOpt)
        return false;

    renderer.setBoardSprite(*boardSpriteOpt);

    if (!font.openFromFile("arialmt.ttf")) {
        std::cout << "Failed to load font\n";
    }

    checkmateText.setFont(font);
    checkmateText.setString("CHECKMATE!");
    checkmateText.setCharacterSize(80);
    checkmateText.setFillColor(sf::Color::Black);
    checkmateText.setPosition(sf::Vector2f(180,350));

    boardState = game.getBoardView();
    renderer.updateBoard(boardState);

    return true;
}


void GameWindow::handleClick(int x, int y)
{
    int screenRow = y / renderer.getCellSize();
    int screenCol = x / renderer.getCellSize();

    if (screenRow < 0 || screenRow >= 8 ||
        screenCol < 0 || screenCol >= 8)
        return;

    int internalRow = 7 - screenRow;
    int internalCol = screenCol;

    game.click(internalRow, internalCol);

    boardState = game.getBoardView();
    renderer.updateBoard(boardState);
}

void GameWindow::handleEvents() {
    while (auto optEvent = window.pollEvent()) {
        const sf::Event& event = *optEvent;

        if (event.is<sf::Event::Closed>()) {
            window.close();
        }
        else if (auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                handleClick(mousePressed->position.x, mousePressed->position.y);
            }
        }
    }
}

void GameWindow::draw() {
    window.clear();
    renderer.draw(window);
    if (game.isGameOver()) {
        window.draw(checkmateText);
    }
    auto selected = game.getSelected();

    if (selected) {
        renderer.drawHighlight(
            window,
            selected->first,
            selected->second,
            sf::Color(255,255,0,128)
        );
    }
    window.display();
}

bool GameWindow::processFrame() {
    handleEvents();
    draw();
    return window.isOpen();
}


