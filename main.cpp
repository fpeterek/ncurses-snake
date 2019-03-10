//
//  main.cpp
//  terminal_snake
//
//  Created by Filip Peterek on 15/02/2019.
//  Copyright © 2019 Filip Peterek. All rights reserved.
//


#include <ncurses.h>

#include "game.hpp"

constexpr bool enable_half_delay = true;

void exitCurses() {
    endwin();
}

void initCurses() {
    
    initscr();
    cbreak();
    keypad(stdscr, true);
    if (enable_half_delay) {
        halfdelay(1);
    }
    noecho();
    curs_set(0);
    clear();
    atexit(exitCurses);
    
}

void init() {

    srand((unsigned)time(nullptr));
    initCurses();

}


int main(int argc, const char * argv[]) {

    init();
    Game().run();
    
}

