#ifndef BLINKY_H
#define BLINKY_H

#include "pacman.h"

void spawn_blinky(Game* game);

void move_blinky(Game* game, int dx, int dy);
void move_blinky_up(Game* game);
void move_blinky_down(Game* game);
void move_blinky_left(Game* game);
void move_blinky_right(Game* game);
void move_blinky_direction(Game* game, enum Direction direction);

#endif // BLINKY_H