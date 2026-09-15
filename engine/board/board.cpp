#include "board.h"

#include <iomanip>
#include <iostream>

void board::init() {
    for (int i = 0; i < FIELD_SIZE_ROW; i++) {
        for (int j = 0; j < FIELD_SIZE_COL; j++) {
            if (i == 0 || i == FIELD_SIZE_ROW - 1 || j == 0 || j == FIELD_SIZE_COL - 1) {
                this->field[i][j] = tile(tile::states::BOARDER);
            } else {
                this->field[i][j] = tile(tile::states::FREE);
            }
        }
    }
}

void board::print() {
    for (const auto & i : this->field) {
        for (const tile & j : i) {
            std::cout << std::setw(3) << static_cast<int>(j.state) << " ";
        }
        std::cout << std::endl;
    }
}