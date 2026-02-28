include(FetchContent)

# Объявление зависимости
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        3.0.2 # Можно указать конкретный тег или хэш коммита
)

# Загрузка и подключение
FetchContent_MakeAvailable(SFML)

add_executable(projectChess main.cpp)

target_link_libraries(projectChess PRIVATE figures sfml-graphics sfml-window sfml-system)