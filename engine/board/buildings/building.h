#ifndef ENGINE_BUILDING_H
#define ENGINE_BUILDING_H

#include <cstdint>

class building {
public:
    
    constexpr static unsigned int ROT1 = 90;
    constexpr static unsigned int ROT2 = 180;
    constexpr static unsigned int ROT3 = 270;

    uint8_t shape[4][3] = {};

    void rotate(int rotation_index);
    void print();
};

#endif
