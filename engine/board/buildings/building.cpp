#include "building.h"

#include <iomanip>
#include <iostream>

void building::rotate(int rotation_index) {

}

void building::print() {
    for (const auto & i : this->shape) {
        for (const auto & j : i) {
            std::cout << std::setw(2) << std::setfill(' ') << static_cast<int>(j) << " ";
        }
        std::cout << std::endl;
    }
}