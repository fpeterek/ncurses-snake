//
// Created by Filip Peterek on 2019-03-09.
//

#ifndef TERMINAL_SNAKE_GAME_HPP
#define TERMINAL_SNAKE_GAME_HPP

#include <unordered_map>

#include <ncurses.h>

#include "entity.hpp"
#include "player.hpp"
#include "food.hpp"

class Game {

    Player player;
    Food food;
    bool exit = false;

    static const std::unordered_map<int, direction> keyDirMap;

    void generateFood(const int maxDepth = 10);
    void foodCollision();
    void checkCollision();
    void gameOver();
    void draw();
    void handleInput();
    void update();

public:

    void reset();
    void run();

};


#endif //TERMINAL_SNAKE_GAME_HPP
