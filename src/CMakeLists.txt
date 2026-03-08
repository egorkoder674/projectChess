add_library(figures)
target_sources(figures PRIVATE ${CMAKE_SOURCE_DIR}/src/figures/Bishop.cpp)

target_include_directories(figures PUBLIC ${CMAKE_SOURCE_DIR}/include/figures)

add_library(graphics)
target_sources(graphics PRIVATE ${CMAKE_SOURCE_DIR}/src/graphics/BoardRenderer.cpp
        ${CMAKE_SOURCE_DIR}/src/graphics/GameWindow.cpp
        ${CMAKE_SOURCE_DIR}/src/graphics/TextureStorage.cpp)

target_include_directories(graphics PUBLIC ${CMAKE_SOURCE_DIR}/include/graphics)