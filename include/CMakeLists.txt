add_library(chess_engine
        Board.cpp
        Move.cpp
        Position.cpp
)

target_include_directories(chess_engine PUBLIC ../include)