#ifndef ENGINE_ROTATION_LUT_H
#define ENGINE_ROTATION_LUT_H

#include <array>
#include <cstdint>

constexpr std::array<std::array<uint8_t, 16>, 4> make_rotation_lut() {
    std::array<std::array<uint8_t, 16>, 4> lut = {};
    
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            uint8_t original_index = r * 4 + c;
            
            lut[0][original_index] = original_index;
            lut[1][r*4+c] = (3 - c) * 4 + r; // 90 degrees
            lut[2][r*4+c] = (3 - r) * 4 + (3 - c); // 180 degrees
            lut[3][r*4+c] = c * 4 + (3 - r); // 270 degrees
        }
    }
    return lut;
}

constexpr auto ROTATION_LUT = make_rotation_lut();

#endif