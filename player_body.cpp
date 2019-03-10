//
// Created by Filip Peterek on 2019-03-09.
//

#include "player_body.hpp"

chtype PlayerBody::getChar() const {
    return L'O';
}

void PlayerBody::setPosition(const uint16_t newX, const uint16_t newY) {
    _x = newX;
    _y = newY;
}

PlayerBody::PlayerBody() = default;

PlayerBody::PlayerBody(const uint16_t x, const uint16_t y) : Entity(x, y) { }

PlayerBody::PlayerBody(const PlayerBody & pb) : Entity(pb.x, pb.y) { }