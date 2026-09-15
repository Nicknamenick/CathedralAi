#include <iostream>
#include "board/board.h"

static board b;

int main() {
    std::cout << "starting engine" << std::endl;

    b.init();
    b.print();

    return 0;
}