#include "building.h"

#include <iomanip>
#include <iostream>
#include "rotateBuilding.h"

std::array<uint8_t, 16> building::rotate(int rotation_index, const std::array<uint8_t, 16>& shape){
    if (rotation_index < 0 || rotation_index > 3) {
        std::cerr << "Invalid rotation index: " << rotation_index << std::endl;
        return {};
    }

    std::array<uint8_t, 16> new_shape = {};
    for (int i = 0; i < 16; ++i) {
        new_shape[i] = shape[ROTATION_LUT[rotation_index][i]];
    }
    return new_shape;
}

building::building(const std::array<uint8_t, 16>& initial_shape) {
    for (int i = 0; i < 16; ++i) {
        this->shapes[0][i] = initial_shape[i];
    }
    for (int rotation_index = 1; rotation_index < 4; ++rotation_index) {
        this->shapes[rotation_index] = rotate(rotation_index, this->shapes[0]);
    }
}

[[nodiscard]] std::string building::to_pstring(int rotation_index) const {
    std::ostringstream result;
    result << "\n";
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            result << static_cast<int>(this->get_tile(row, col, rotation_index)) << " ";
        }
        result << '\n';
    }
    return result.str();
}