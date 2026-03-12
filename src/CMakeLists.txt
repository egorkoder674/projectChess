include(FetchContent)

# Объявление зависимости
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        3.0.2 # Можно указать конкретный тег или хэш коммита
)

# Загрузка и подключение
FetchContent_MakeAvailable(SFML)

add_library(figures)
target_sources(figures PRIVATE
        ${CMAKE_SOURCE_DIR}/src/figures/Piece.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/Bishop.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/Pawn.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/King.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/Queen.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/Rook.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/Knight.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/Move.cpp
        ${CMAKE_SOURCE_DIR}/src/figures/Board.cpp)

target_include_directories(figures PUBLIC ${CMAKE_SOURCE_DIR}/include/figures)


add_library(game)

target_sources(game PRIVATE
        ${CMAKE_SOURCE_DIR}/src/game/game.cpp)

target_include_directories(game
        PUBLIC ${CMAKE_SOURCE_DIR}/include/game)

target_link_libraries(game PUBLIC figures)


add_library(graphics)
target_sources(graphics PRIVATE
        ${CMAKE_SOURCE_DIR}/src/graphics/BoardRenderer.cpp
        ${CMAKE_SOURCE_DIR}/src/graphics/GameWindow.cpp
        ${CMAKE_SOURCE_DIR}/src/graphics/TextureStorage.cpp)

target_include_directories(graphics PUBLIC ${CMAKE_SOURCE_DIR}/include/graphics)

target_link_libraries(graphics PUBLIC
        SFML::Graphics
        game)