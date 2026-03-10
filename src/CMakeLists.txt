add_library(figures
        ../include/Board.h
        Board.cpp)
target_sources(figures PRIVATE ${CMAKE_SOURCE_DIR}/src/figures/Bishop.cpp)

target_include_directories(figures PUBLIC ${CMAKE_SOURCE_DIR}/include/figures)