#include <iostream>
#include "src/figures/Bishop.h"

int main() {
    Bishop B(3,4);
    std::cout << B.Coor().first << " " << B.Coor().second << '\n';
}