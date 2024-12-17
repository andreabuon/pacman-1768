#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "pacman.h"

#define MARGIN_LEFT 8
#define MARGIN_TOP 8

void display_game_info(Game* game);
void display_tile(uint16_t row, uint16_t col, Tile* tile);
void display_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);
void draw_pacman(uint16_t row, uint16_t col);

#endif // GRAPHICS_H *