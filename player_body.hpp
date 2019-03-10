//
// Created by Filip Peterek on 2019-03-09.
//

#ifndef TERMINAL_SNAKE_PLAYER_BODY_HPP
#define TERMINAL_SNAKE_PLAYER_BODY_HPP

#include <cstdlib>

#include "entity.hpp"

class PlayerBody: public Entity {

    friend class Player;

    virtual chtype getChar() const;
    void setPosition(const uint16_t newX, const uint16_t newY);

public:

    PlayerBody();
    PlayerBody(const uint16_t x, const uint16_t y);
    PlayerBody(const PlayerBody & pb);
};


#endif //TERMINAL_SNAKE_PLAYER_BODY_HPP
