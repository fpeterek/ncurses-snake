//
// Created by Filip Peterek on 2019-03-09.
//

#include "../include/game.hpp"

const std::unordered_map<int, direction> Game::keyDirMap = {
        { KEY_LEFT,  direction::left  },
        { KEY_RIGHT, direction::right },
        { KEY_UP,    direction::up    },
        { KEY_DOWN,  direction::down  }
};

void Game::generateFood(const int maxDepth) {

    // Make 10 attempts to generate food outside snake body
    // If unsuccessul after 10 attempts, give up and place it wherever
    // There are better ways to do this, this is simple and acceptable
    if (not maxDepth) {
        return;
    }

    food = Food();

    if (player.fullbodyCollision(food)) {
        generateFood(maxDepth - 1);
    }

}

void Game::draw() {

    clear();
    box(stdscr, 0, 0);

    food.draw();
    player.draw();

    refresh();

}

void Game::handleInput() {

    int input = getch();

    if (input == '\e' or input == 'q') {
        exit = true;
        return;
    }

    if (keyDirMap.count(input)) {
        player.changeDirection(keyDirMap.at(input));
    }

}

void Game::update() {

    player.move();

    checkCollision();
    foodCollision();


}

void Game::foodCollision() {

    if (player.headCollision(food)) {
        player.grow();
        generateFood();
    }

}

void Game::checkCollision() {

    if (player.detectCollision()) {
        gameOver();
        reset();
    }

}

WINDOW * create_newwin(int height, int width, int starty, int startx) {

    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);
    wrefresh(local_win);

    return local_win;

}

void destroy_win(WINDOW * local_win) {

    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(local_win);
    delwin(local_win);

}

void Game::gameOver() {

    const int height = std::max(LINES / 3, 3);
    const int width = std::max(COLS / 3, 11);
    const int startY = std::max(LINES / 2 - height / 2, 1);
    const int startX = std::max(COLS / 2 - width / 2, 1);
    const int textY = std::max(height / 2 - 1, 1);
    const int textX = std::max(width / 2 - 4, 1);

    WINDOW * win = create_newwin(height, width, startY, startX);

    mvwaddstr(win, textY, textX, "Game Over");
    wrefresh(win);
    refresh();

    while (true) {
        const int input = getch();

        if (input == '\e' or input == 'q') {
            exit = true;
            break;
        }

        if (input == ' ') {
            break;
        }
    }

    destroy_win(win);
    reset();

}

void Game::reset() {
    player = Player((uint16_t)(COLS / 4), (uint16_t)(LINES / 4));
    generateFood();
}

void Game::run() {

    reset();

    while (not exit) {

        handleInput();
        update();
        draw();

    }

}
