#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "pacman.h"

#define MARGIN_LEFT 8
#define MARGIN_TOP 8

void draw_labels();
void draw_game_time(Game* game);
void draw_game_lifes(Game* game);
void draw_game_score(Game* game);

void draw_tile(uint8_t row, uint8_t col, Tile* tile);
void draw_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);

void draw_pacman(uint8_t row, uint8_t col);

#endif // GRAPHICS_H *