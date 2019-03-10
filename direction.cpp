//
// Created by Filip Peterek on 2019-03-09.
//

#include "direction.hpp"

bool isHorizontal(const direction dir) {
    return dir == direction::left or dir == direction::right;
}

bool isVertical(const direction dir) {
    return dir == direction::up or dir == direction::down;
}
