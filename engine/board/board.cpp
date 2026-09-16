#include "board.h"
#include "../utils/utils.h"

#include <iomanip>
#include <iostream>
#include <sstream>

void board::init() {
    for (int i = 0; i < FIELD_SIZE; i++) {
        int row = i / FIELD_SIZE_COL;
        int col = i % FIELD_SIZE_COL;

        this->ref_ids[i] = 0;
        if (row == 0 || row == FIELD_SIZE_ROW - 1 || col == 0 || col == FIELD_SIZE_COL - 1) {
            this->states[i] = tile_states::BOARDER;
        } else {
            this->states[i] = tile_states::FREE;
        }
    }
}

std::string board::to_pstring() {
    std::ostringstream result;
    result << "\n";
    for (int row = 0; row < FIELD_SIZE_ROW; ++row) {
        for (int col = 0; col < FIELD_SIZE_COL; ++col) {
            uint8_t tile_state = this->get_tile_state(row, col);
            result << std::setw(3) << static_cast<int>(tile_state) << ' ';
        }
        result << '\n';
    }
    return result.str();
}