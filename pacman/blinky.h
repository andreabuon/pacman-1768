#ifndef BLINKY_H
#define BLINKY_H

#include "pacman.h"

#define BLINKY_RESPAWN_TIMEOUT 3 //s

void spawn_blinky(Game* game);
void kill_blinky(Game* game);

void move_blinky(Game* game, int dx, int dy);
void move_blinky_up(Game* game);
void move_blinky_down(Game* game);
void move_blinky_left(Game* game);
void move_blinky_right(Game* game);
void move_blinky_direction(Game* game, enum Direction direction);

void compute_blinky_path(Game* game);

#endif // BLINKY_H