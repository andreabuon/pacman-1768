#ifndef SPRITES_H
#define SPRITES_H

#include <stdint.h>

#define TILE_SIZE_PIXELS 8

extern uint16_t pacman_sprite_up[TILE_SIZE_PIXELS][TILE_SIZE_PIXELS];
extern uint16_t pacman_sprite_down[TILE_SIZE_PIXELS][TILE_SIZE_PIXELS];
extern uint16_t pacman_sprite_left[TILE_SIZE_PIXELS][TILE_SIZE_PIXELS];
extern uint16_t pacman_sprite_right[TILE_SIZE_PIXELS][TILE_SIZE_PIXELS];

extern uint16_t blinky_chase_sprite[8][8];
extern uint16_t blinky_frightened_sprite[8][8];

extern uint16_t power_pill_sprite[TILE_SIZE_PIXELS][TILE_SIZE_PIXELS];
extern uint16_t standard_pill_sprite[TILE_SIZE_PIXELS][TILE_SIZE_PIXELS];

#endif 
