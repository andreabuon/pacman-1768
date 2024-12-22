#ifndef PACMAN_H
#define PACMAN_H

#include <stdint.h>
#include "map.h"

#define STANDARD_PILLS_COUNT 240
#define POWER_PILLS_COUNT 6

#define STANDARD_PILL_SCORE 10
#define POWER_PILL_SCORE 50

#define PACMAN_INITIAL_POSITION_X 3
#define PACMAN_INITIAL_POSITION_Y 14

#define THRESHOLD_NEW_LIFE 1000

uint8_t is_a_pill(Tile* tile);
uint8_t get_tile_score(Tile* tile);

enum GameState {
	READY,
	PLAYING,
	PAUSED,
	WON,
	GAME_OVER
};

enum Direction{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct Game {
	enum GameState state;
	
	Tile map[MAP_HEIGHT][MAP_LENGTH];
	
	uint8_t lives;
	uint16_t score;
	uint8_t time;
	
	uint8_t standard_pills_count;
	uint8_t power_pills_count;
	
	uint8_t pacman_x;
	uint8_t pacman_y;
	
	uint16_t threshold_new_life;
	
} Game;

void new_game(Game* game);

void start_game(Game* game);
void pause_game(Game* game);
void win_game(Game* game);
void lose_game(Game* game);

void set_game_state(Game* game, enum GameState state);

void add_life(Game* game);
void update_score(Game* game, Tile* new_tile);


void move_pacman(Game* game, int dx, int dy);
void move_pacman_up(Game* game);
void move_pacman_down(Game* game);
void move_pacman_left(Game* game);
void move_pacman_right(Game* game);
void move_pacman_direction(Game* game, enum Direction direction);

#endif // PACMAN_H *