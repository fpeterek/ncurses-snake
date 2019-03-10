//
// Created by Filip Peterek on 2019-03-09.
//

#ifndef TERMINAL_SNAKE_ENTITY_HPP
#define TERMINAL_SNAKE_ENTITY_HPP

#include <cstdint>

#include <ncurses.h>

#include "direction.hpp"


class Entity {

protected:

    uint16_t _x = 0;
    uint16_t _y = 0;

    virtual chtype getChar() const;

public:

    const uint16_t & x = _x;
    const uint16_t & y = _y;

    Entity();
    Entity(const uint16_t x, const uint16_t y);

    virtual void draw() const;
    bool collidesWith(const Entity & e) const;
    void move(const direction dir);

};


#endif //TERMINAL_SNAKE_ENTITY_HPP
