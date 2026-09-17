#ifndef ENGINE_BUILDING_H
#define ENGINE_BUILDING_H

#include <cstdint>
#include <string>
#include <array>

class building {
private:
    static uint16_t next_ref_id;

public:
    std::array<std::array<uint8_t, 16>, 4> shapes = {};
    uint16_t ref_id = 0;

    building(const std::array<uint8_t, 16>& initial_shape);

    inline uint8_t get_tile(int row, int col, int rotation_index = 0) const {
        return this->shapes[rotation_index][row * 4 + col];
    }

    [[nodiscard]] std::string to_pstring(int rotation_index) const;
    static std::array<uint8_t, 16> rotate(int rotation_index, const std::array<uint8_t, 16>& shape);
};

#endif
