#ifndef MAP_H
#define MAP_H

#define MAP_HEIGHT 31
#define MAP_LENGTH 28

#include <stdint.h>

enum TileType {
  EMPTY_TILE,
	WALL,
  STANDARD_PILL,
  POWER_PILL,
	TELEPORT
	/*
	ENEMY,
	ENEMY_PILL,
	ENEMY_SPECIAL_PILL
	*/
};

typedef struct {
	enum TileType type;
} Tile;

uint8_t is_a_pill(Tile* tile);
uint8_t get_tile_score(Tile* tile);

void parse_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);

#endif // MAP_H *