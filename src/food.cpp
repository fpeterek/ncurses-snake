//
// Created by Filip Peterek on 2019-03-09.
//

#include "../include/food.hpp"

#include <cstdlib>

chtype Food::getChar() const {
    return L'x';
}


Food::Food() {
    _x = (uint16_t)(1 + rand() % (COLS - 2));
    _y = (uint16_t)(1 + rand() % (LINES - 2));
}

Food & Food::operator=(const Food & orig) {
    _x = orig._x;
    _y = orig._y;
    return *this;
}