# Ncurses Snake
Snake created using ncurses

## How to play

Press directional arrows to control snake's direction.

Press `q` or `esc` to exit game.

If you die and a Game Over screen appears, press `space` to reset the game.

At the beginning of the game, press any arrow to give the snake a direction and start the game. 
A snake of length 1 can move in any direction. A snake longer than 1 square cannot switch direction to a direction 
opposite of it's current direction.

All calculations are relative to current terminal dimensions and the game scales according to the size of your terminal. 
To make sure the game runs comfortably though, try to use terminal at least 15 columns wide and 10 rows long and avoid
playing the game on your IOT Samsung Smart Fridge.

## Compilation

You should be able to compile and run the game on any POSIX compliant system using a C++11 compliant compiler.

`g++ *.cpp -std=c++11 -lncurses -Os -o snake`

## Dependencies

This game has no dependencies and only uses some parts of the C++ standard library and ncurses, library, which should 
be present on all POSIX compliant systems.
