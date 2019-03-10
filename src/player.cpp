//
// Created by Filip Peterek on 2019-03-09.
//

#include "../include/player.hpp"

Player::Player() {
    snake.emplace_back();
}

Player::Player(const uint16_t x, const uint16_t y) {
    snake.emplace_back(x, y);
}

void Player::move() {

    for (size_t i = snake.size() - 1; i; --i) {
        snake[i].setPosition(snake[i - 1]._x, snake[i - 1]._y);
    }

    snake.front().move(dir);

}

void Player::changeDirection(const direction newDir) {

    const bool vertical = isVertical(newDir) and isVertical(dir);
    const bool horizontal = isHorizontal(newDir) and isHorizontal(dir);

    if (snake.size() != 1 and (vertical or horizontal)) {
        return;
    }

    dir = newDir;

}

bool Player::fullbodyCollision(const Entity & entity) const {

    for (const Entity & e : snake) {
        if (e.collidesWith(entity)) {
            return true;
        }
    }

    return false;

}

bool Player::headCollision(const Entity & e) const {
    return snake.front().collidesWith(e);
}

bool Player::detectCollision() const {

    const PlayerBody & head = snake.front();

    for (size_t i = 1; i < snake.size(); ++i) {
        if (head.collidesWith(snake[i])) {
            return true;
        }
    }

    return not head.x or head.x == COLS - 1 or
            not head.y or head.y == LINES - 1;

}

void Player::grow() {
    snake.emplace_back(PlayerBody(snake.back()));
}

void Player::draw() {
    for (const auto & e : snake) {
        e.draw();
    }
}
