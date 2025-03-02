#include "blinky.h"
#include "pathfinding.h"

#include <stdio.h>
#include <stdlib.h>

#define BLINKY_INITIAL_X 13
#define BLINKY_INITIAL_Y 15

void spawn_blinky(Game* game){
	game->blinky_y = BLINKY_INITIAL_Y;
	game->blinky_x = BLINKY_INITIAL_X;
	game->blinky_mode = CHASE;
	game->blinky_respawn_timeout = BLINKY_RESPAWN_TIMEOUT;
}

void kill_blinky(Game* game){
	game->blinky_y = 0; //FIXME
	game->blinky_x = 0; //FIXME
	game->blinky_mode = RESPAWNING;
	game->blinky_respawn_timeout = BLINKY_RESPAWN_TIMEOUT;
}

void move_blinky(Game* game, int dx, int dy) {
	int new_x = game->blinky_x + dx;
	int new_y = game->blinky_y + dy;
	
	// Prevent out-of-bounds access
	if ( new_x < 0 || new_x >= MAP_LENGTH ) {
		// Teleport mechanism
		if (game->map[game->blinky_y][game->blinky_x].type == TELEPORT) {
			new_x = (new_x + MAP_LENGTH) % MAP_LENGTH;  // Wrap around horizontally
			//new_y = (new_y + MAP_HEIGHT) % MAP_HEIGHT;  // Wrap around vertically
		}else{
			return;
		}
	}
	
	if ( new_y < 0 || new_y >= MAP_HEIGHT ) {
		return;
	}
	
	//Blinky does not move if it encounters a wall
	if (game->map[new_y][new_x].type == WALL) {
		return;
	}
	
  game->blinky_x = new_x;
  game->blinky_y = new_y;
	
	//TODO Pacman eating mechanism
}

void move_blinky_up(Game* game){
	move_blinky(game, 0, -1);
}

void move_blinky_down(Game* game){
	move_blinky(game, 0, 1);
}

void move_blinky_left(Game* game){
	move_blinky(game, -1, 0);
}

void move_blinky_right(Game* game){
	move_blinky(game, 1, 0);
}

void move_blinky_direction(Game* game, enum Direction direction){
	switch(direction){
		case UP:
			move_blinky_up(game);
			break;
		case DOWN:
			move_blinky_down(game);
			break;
		case LEFT:
			move_blinky_left(game);
			break;
		case RIGHT:
			move_blinky_right(game);
			break;
		default:
			break;
	}
}

enum Direction get_next_blinky_direction(Game* game){
	switch(game->blinky_mode){
		case CHASE:
			return get_closest_next_direction(game);
		case FRIGHTENED:
			return get_furthest_next_direction(game);
		default:
			return DEFAULT_BLINKY_DIRECTION;
	}
}