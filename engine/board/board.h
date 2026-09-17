#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H

#include <cstdint>
#include <array>
#include <string>
#include "buildings/building.h"

constexpr uint8_t FIELD_SIZE_ROW = 12;
constexpr uint8_t FIELD_SIZE_COL = 12;
constexpr uint8_t FIELD_SIZE = FIELD_SIZE_ROW * FIELD_SIZE_COL;

namespace tile_states {
    constexpr uint8_t FREE = 0;
    constexpr uint8_t PLAYER_1 = 1;
    constexpr uint8_t PLAYER_2 = 2;
    constexpr uint8_t CAPTURED1 = 3;
    constexpr uint8_t CAPTURED2 = 4;

    constexpr uint8_t BOARDER = 10;
    constexpr uint8_t CATHEDRAL = 11;
}

class board {
public:   
    board() = default;

    std::array<uint8_t, FIELD_SIZE> states = {};
    std::array<uint16_t, FIELD_SIZE> ref_ids = {};

    inline uint8_t& get_tile_state(int row, int col) {
        return this->states[row * FIELD_SIZE_COL + col];
    }

    inline uint16_t& get_tile_ref_id(int row, int col) {
        return this->ref_ids[row * FIELD_SIZE_COL + col];
    }

    void init();

    [[nodiscard]] bool is_valid_move(const building& b, int row, int col, int rotation_index, uint8_t player_id) const;

    [[nodiscard]] uint16_t place_building(const building& b, int row, int col, int rotation_index, uint8_t player_id) const;
    void capture_building(uint16_t ref_id, uint8_t player_id);

    [[nodiscard]] std::string to_pstring();
};


#endif