add_library(figures)
target_sources(figures PRIVATE ${CMAKE_SOURCE_DIR}/src/figures/Bishop.cpp)

target_include_directories(figures PUBLIC ${CMAKE_SOURCE_DIR}/include/figures)