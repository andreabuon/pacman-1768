#include <stdint.h>
#include "pacman.h"

void new_game(Game* game){
	game->state = READY;
	generate_map(game->map);	
	game->score = 0;
	game->lives = 1;
	game->time = 60;
	
	game->standard_pills_count = STANDARD_PILLS_COUNT;
	game->power_pills_count = POWER_PILLS_COUNT;
	//TODO place pacman on the map
	
	game->pacman_x = PACMAN_INITIAL_POSITION_X;
	game->pacman_y = PACMAN_INITIAL_POSITION_Y;
	//game->map[game->pacman_y][game->pacman_x].type = PACMAN;
}

void set_game_state(Game* game, enum GameState state) {
    game->state = state;
}

void start_game(Game* game){
  game->state = PLAYING;
}

void pause_game(Game* game){
	set_game_state(game, PAUSED);
}

void win_game(Game* game){
	set_game_state(game, WON);
}

void lose_game(Game* game){
	set_game_state(game, GAME_OVER);
	//disable timers (time, movement, score, etc)
	//draw game over message
}

void add_life(Game* game){
	game->lives++;
}

void move_pacman(Game* game, int dx, int dy) {
	int new_x = game->pacman_x + dx;
	int new_y = game->pacman_y + dy;
	if (game->map[new_y][new_x].type == WALL) {
		return;
	}
	
	if (game->map[new_y][new_x].type == TELEPORT) {
		//return;
	}
 
	// Replace the old tile with a new one
	game->map[game->pacman_y][game->pacman_x].type = EMPTY_TILE;
		
  game->pacman_x = new_x;
  game->pacman_y = new_y;
	// If the old tile was a pill update the game score
  if (is_a_pill(&game->map[new_y][new_x])) {
		game->score += get_tile_score(&game->map[new_y][new_x]);
		if (game->map[new_y][new_x].type == STANDARD_PILL) game->standard_pills_count--;
			else game->power_pills_count--;
		}
}

void move_pacman_up(Game* game){
	move_pacman(game, 0, -1);
}

void move_pacman_down(Game* game){
	move_pacman(game, 0, 1);
}

void move_pacman_left(Game* game){
	move_pacman(game, -1, 0);
}

void move_pacman_right(Game* game){
	move_pacman(game, 1, 0);
}

void move_pacman_direction(Game* game, enum Direction direction){
	switch(direction){
		case UP:
			move_pacman_up(game);
			break;
		case DOWN:
			move_pacman_down(game);
			break;
		case LEFT:
			move_pacman_left(game);
			break;
		case RIGHT:
			move_pacman_right(game);
			break;
		default:
			break;
	}
}