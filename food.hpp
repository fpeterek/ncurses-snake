//
// Created by Filip Peterek on 2019-03-09.
//

#ifndef TERMINAL_SNAKE_FOOD_HPP
#define TERMINAL_SNAKE_FOOD_HPP

#include "entity.hpp"

class Food: public Entity {

    virtual chtype getChar() const;

public:

    Food();
    Food & operator=(const Food & orig);

};


#endif //TERMINAL_SNAKE_FOOD_HPP
