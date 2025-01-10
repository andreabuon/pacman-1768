#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <stdint.h>
#include "pacman.h"

#define DEFAULT_BLINKY_DIRECTION UP

int get_euclidean_distance(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2);

enum Direction get_closest_next_direction(Game* game);
enum Direction get_furthest_next_direction(Game* game);


#endif 
