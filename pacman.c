#include "pacman.h"
#include <stdlib.h>

enum TileType board[MAP_HEIGHT][MAP_LENGTH] = {
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}, 
    {WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, EMPTY_TILE, WALL, WALL, EMPTY_TILE, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, EMPTY_TILE, WALL, WALL, EMPTY_TILE, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, WALL, WALL, WALL, EMPTY_TILE, EMPTY_TILE, WALL, WALL, WALL, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, WALL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, WALL, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {TELEPORT, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, STANDARD_PILL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, WALL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, WALL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, STANDARD_PILL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, TELEPORT},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, WALL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, WALL, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL}, 
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, EMPTY_TILE, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY_TILE, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL},
    {WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL},
    {WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL},
    {WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL, WALL, STANDARD_PILL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, STANDARD_PILL, WALL},
    {WALL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, STANDARD_PILL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
};

uint8_t is_a_pill(Tile* tile){
	if(tile->type == STANDARD_PILL || tile->type == POWER_PILL){
		return 1;
	} else {
		return 0;
	}
}

uint8_t get_tile_score(Tile* tile){
	switch(tile->type){
		case STANDARD_PILL:
			return STANDARD_PILL_SCORE;
		case POWER_PILL:
			return POWER_PILL_SCORE;
		default:
			return 0;
	}
}

void new_game(Game* game){
	game->state = READY; //FIXME
	generate_map(game->map);	
	game->score = 0;
	game->lives = 1;
	game->time = 60;
	
	game->standard_pills_count = STANDARD_PILLS_COUNT;
	game->power_pills_count = POWER_PILLS_COUNT;
	//TODO place pacman on the map
	
	game->pacman_x = PACMAN_INITIAL_POSITION_X;
	game->pacman_y = PACMAN_INITIAL_POSITION_Y;
}

void start_game(Game* game){
  game->state = PLAYING;
}

void parse_map(Tile map[MAP_HEIGHT][MAP_LENGTH]){
	int row = 0;
	int col = 0;
	for (; row < MAP_HEIGHT; row++) {
		for (; col < MAP_LENGTH; col++) {
			map[row][col].type = board[row][col];
    }
  }
}

void generate_map(Tile map[MAP_HEIGHT][MAP_LENGTH]){
	parse_map(map);
	//TODO place pills
	//TODO place power pills randomly
}

void add_life(Game* game){
	game->lives++;
}