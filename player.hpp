//
// Created by Filip Peterek on 2019-03-09.
//

#ifndef TERMINAL_SNAKE_PLAYER_HPP
#define TERMINAL_SNAKE_PLAYER_HPP

#include <vector>

#include "player_body.hpp"


class Player {

    std::vector<PlayerBody> snake;
    direction dir = direction::none;

public:

    Player();
    Player(const uint16_t x, const uint16_t y);

    void move();
    void changeDirection(const direction newDir);

    bool fullbodyCollision(const Entity & entity) const;
    bool headCollision(const Entity & e) const;
    bool detectCollision() const;

    void grow();
    void draw();

};


#endif //TERMINAL_SNAKE_PLAYER_HPP
