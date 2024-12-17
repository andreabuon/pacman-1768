#ifndef MAP_H
#define MAP_H

#define MAP_HEIGHT 31
#define MAP_LENGTH 28

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

void generate_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);

#endif // MAP_H *