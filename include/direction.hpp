//
// Created by Filip Peterek on 2019-03-09.
//

#ifndef TERMINAL_SNAKE_DIRECTION_HPP
#define TERMINAL_SNAKE_DIRECTION_HPP

enum class direction {
    none = 0,
    up = 1,
    down = 2,
    left = 4,
    right = 8
};

bool isHorizontal(const direction dir);
bool isVertical(const direction dir);

#endif //TERMINAL_SNAKE_DIRECTION_HPP
