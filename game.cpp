//
// Created by Filip Peterek on 2019-03-09.
//

#include "game.hpp"

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

    const int height = 11;
    const int width = 35;
    const int startY = LINES / 2 - 5;
    const int startX = COLS / 2 - 17;

    WINDOW * win = create_newwin(height, width, startY, startX);

    mvwaddstr(win, 5, 13, "Game Over");
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
    player = Player(10, 10);
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
