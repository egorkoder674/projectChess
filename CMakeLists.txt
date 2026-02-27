cmake_minimum_required(VERSION 4.0)
project(project)

set(CMAKE_CXX_STANDARD 20)

add_executable(project main.cpp
        src/figures/Piece.h
        src/figures/Pawn.h
        src/figures/King.h
        src/figures/Queen.h
        src/figures/Rook.h
        src/figures/Knight.h
        src/figures/Bishop.h
        include/figures/Bishop.cpp
        include/figures/King.cpp
        include/figures/Knight.cpp
        include/figures/Pawn.cpp
        include/figures/Queen.cpp
        include/figures/Rook.cpp
        include/figures/Piece.cpp
)
