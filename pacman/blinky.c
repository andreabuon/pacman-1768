#include "blinky.h"

#define BLINKY_INITIAL_X 16
#define BLINKY_INITIAL_Y 14

void spawn_blinky(Game* game){
	game->blinky_y = BLINKY_INITIAL_Y;
	game->blinky_x = BLINKY_INITIAL_X;
}

void move_blinky(Game* game, int dx, int dy) {
	int new_x = game->pacman_x + dx;
	int new_y = game->pacman_y + dy;
	
	// Prevent out-of-bounds access
	if ( new_x < 0 || new_x >= MAP_LENGTH ) {
		// Teleport mechanism
		if (game->map[game->pacman_y][game->pacman_x].type == TELEPORT) {
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