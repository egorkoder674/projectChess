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