#ifndef BUILDINGS_H
#define BUILDINGS_H

#include "building.h"
#include <array>
#include <cstdint>


namespace buildings {
    namespace shapes {
        std::array<uint8_t, 16> test_building_shape1 = {  
            1, 1, 0, 0,
            1, 1, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
        std::array<uint8_t, 16> test_building_shape2 = {  
            1, 1, 1, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
        std::array<uint8_t, 16> test_building_shape3 = {  
            1, 1, 1, 1,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
    }

    building test_building(shapes::test_building_shape1);
    building test_building2(shapes::test_building_shape2);
    building test_building3(shapes::test_building_shape3);
};

#endif