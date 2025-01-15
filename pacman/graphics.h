#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "pacman.h"

#define MARGIN_LEFT 8
#define MARGIN_TOP 8

void draw_labels();
void draw_game_time(uint8_t time);
void draw_game_lives(uint8_t lifes);
void draw_game_score(uint16_t score);
void draw_game_state(enum GameState state);

void draw_win_screen();
void draw_game_over_screen();

void draw_tile(Tile map[MAP_HEIGHT][MAP_LENGTH], uint8_t row, uint8_t col);
void draw_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);

void draw_pacman(uint8_t row, uint8_t col, enum Direction direction);

void draw_blinky(uint8_t row, uint8_t col, enum BlinkyMode mode);

#endif // GRAPHICS_H *