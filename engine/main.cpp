#include <iostream>
#include "board/board.h"
#include "board/buildings/building.h"
#include "utils/utils.h"

using namespace utils;

static constexpr std::array<uint8_t, 16> test_shape = {
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

static building test_building = building(test_shape);
static board test_board;

void test_logger(void);
void test_board_init(void);
void test_building_rotate(void);

int main() {
    utils::log.info("Starting engine...");

    test_logger();
    test_board_init();
    test_building_rotate();

    return 0;
}

void test_logger() {
    utils::log.info("This is an info message.");
    utils::log.warn("This is a warning message.");
    utils::log.error("This is an error message.");
}

void test_board_init() {
    test_board.init();
    utils::log.info("Initialized board:");
    utils::log.info(test_board.to_pstring());
}

void test_building_rotate() {
    utils::log.info("Testing building rotation:");
    utils::log.info(test_building.to_pstring(0));
    utils::log.info(test_building.to_pstring(1));
    utils::log.info(test_building.to_pstring(2));
    utils::log.info(test_building.to_pstring(3));
}