#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H

#include <cstdint>

constexpr uint8_t FIELD_SIZE_ROW = 11;
constexpr uint8_t FIELD_SIZE_COL = 11;

class tile {
public:
    uint8_t state = 0;

    class states {
    public:
        static constexpr uint8_t FREE = 0;
        static constexpr uint8_t PLAYER_1 = 1;
        static constexpr uint8_t PLAYER_2 = 2;
        static constexpr uint8_t CAPTURED1 = 3;
        static constexpr uint8_t CAPTURED2 = 4;

        static constexpr uint8_t BOARDER = 10;
        static constexpr uint8_t CATHEDRAL = 11;
    };
};

class board {
public:
    board() = default;
    tile field[FIELD_SIZE_ROW][FIELD_SIZE_COL] = {};

    void init();
    void print();
};


#endif