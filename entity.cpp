//
// Created by Filip Peterek on 2019-03-09.
//

#include "entity.hpp"

chtype Entity::getChar() const {
    return L'-';
}

Entity::Entity() = default;

Entity::Entity(const uint16_t newX, const uint16_t newY) :
        _x(newX), _y(newY) { }

void Entity::draw() const {
    attron(A_BOLD);
    mvaddch(_y, _x, getChar() | A_BOLD);
    attroff(A_BOLD);
}

bool Entity::collidesWith(const Entity & e) const {
    return _x == e._x and _y == e._y;
}

void Entity::move(const direction dir) {

    const int16_t idir = (int16_t)dir;

    _y += ((idir & 1) * (-1)) + ((idir >> 1) & 1);
    _x += (((idir >> 2) & 1) * (-1)) + ((idir >> 3) & 1);

}