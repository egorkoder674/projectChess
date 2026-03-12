#include "GameWindow.h"
#include <iostream>

int main()
{
    GameWindow window;

    if (!window.setup()) {
        std::cout << "Failed to setup game\n";
        return 1;
    }

    while (window.processFrame()) {}

    return 0;
}