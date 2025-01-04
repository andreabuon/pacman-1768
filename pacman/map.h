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
};

typedef struct {
	enum TileType type;
} Tile;

void parse_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);

#endif // MAP_H *