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

bool board::is_valid_move(const building& b, int row, int col, int rotation_index, uint8_t player_id) const {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            uint8_t tile_value = b.get_tile(r, c, rotation_index);
            if (tile_value != 0) {
                int board_row = row + r;
                int board_col = col + c;

                if (board_row < 0 || board_row >= FIELD_SIZE_ROW || board_col < 0 || board_col >= FIELD_SIZE_COL) {
                    return false;
                }

                uint8_t board_tile_state = this->states[board_row * FIELD_SIZE_COL + board_col];
                if (board_tile_state != tile_states::FREE || board_tile_state != player_id + 2) { // TODO check if the tile is free or belongs to the player
                    return false;
                }
            }
        }
    }
    return true;
}

uint16_t board::place_building(const building& b, int row, int col, int rotation_index, uint8_t player_id) const {
    // TODO: Implementation for placing a building
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