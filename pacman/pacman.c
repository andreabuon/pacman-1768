#include <stdint.h>
#include <stdlib.h>

#include "pacman.h"
#include "../pacman/graphics.h"
#include "blinky.h"
//
#include "../timer/timer.h"
#include "../common.h"
#include "../RIT/RIT.h"

// Game Time Countdown
void enable_game_countdown(){
	enable_timer(TIMER_0, TIMER0_PRIORITY);
}

void disable_game_countdown(){
	disable_timer(TIMER_0);
}
// Pacman Movement
void enable_pacman_movement(){
	enable_timer(TIMER_1, TIMER1_PRIORITY);
}

void disable_pacman_movement(){
	disable_timer(TIMER_1);
}
// Power Pills Generation
void enable_power_pills_generation(){
	enable_timer(TIMER_2, TIMER2_PRIORITY);
}

void disable_power_pills_generation(){
	disable_timer(TIMER_2);
}
//
void resume_pacman_power_mode_timer(){
	enable_timer(TIMER_3, TIMER3_PRIORITY);
}

void disable_pacman_power_mode_timer(){
	disable_timer(TIMER_3);
}

int compare_uint32_ascending(const void* a, const void* b) {
	uint32_t x = *(uint32_t*) a;
	uint32_t y = *(uint32_t*) b;
	if (x < y) return -1;
	if (x > y) return 1;
	return 0;
}

//Fills the array with the values to set the timer MR0 to generate the random power pills
void generate_random_power_pills_spawn_times(uint32_t power_pills_spawn_times[POWER_PILLS_TO_PLACE]){
	for(int i = 0; i < POWER_PILLS_TO_PLACE; i++){
		int time_seconds = rand() % INITIAL_GAME_TIME;
		int time_ms = time_seconds * 1000;
		//power_pills_spawn_times[i] = TIM_MS_TO_TICKS_SIMPLE(ms);
		power_pills_spawn_times[i] = time_ms;
	}
	qsort(power_pills_spawn_times, POWER_PILLS_TO_PLACE, sizeof(power_pills_spawn_times[0]), compare_uint32_ascending );
}

void init_game(Game* game){
	game->state = PAUSED;
	parse_map(game->map);	
	game->score = 0;
	game->lives = 1;
	game->time = INITIAL_GAME_TIME;
	
	game->standard_pills_count = INITIAL_STANDARD_PILLS_COUNT;
	game->power_pills_count = INITIAL_POWER_PILLS_COUNT;
	
	spawn_blinky(game);
	
	generate_random_power_pills_spawn_times(game->power_pills_spawn_times);
	
	game->pacman_x = PACMAN_INITIAL_POSITION_X;
	game->pacman_y = PACMAN_INITIAL_POSITION_Y;
	game->pacman_direction = RIGHT;
	game->pacman_mode = RUN;
	
	game->threshold_new_life = THRESHOLD_NEW_LIFE;
}

void toggle_game_state(Game* game){
	if(game->state == PLAYING){
		pause_game(game);
	}	else if (game->state == PAUSED || game->state == READY){
		start_game(game);
	} else {
		// Do nothing
	}
}

void set_game_state(Game* game, enum GameState state) {
    game->state = state;
}

void start_game(Game* game){
  set_game_state(game, PLAYING);
	
	enable_game_countdown();
	enable_pacman_movement();
	if(game->power_pills_placed_count < POWER_PILLS_TO_PLACE){
		enable_power_pills_generation();
	}
	
	//resume pacman power mode timer when game un-paused
	if(game->pacman_mode == POWER){
		resume_pacman_power_mode_timer();
	}
	
	enable_RIT(); //Joystick polling
	
	draw_game_state(game);
}

void pause_game(Game* game){
	set_game_state(game, PAUSED);
	
	disable_game_countdown();
	disable_pacman_movement();
	disable_power_pills_generation();
	
	if(game->pacman_mode == POWER){
		disable_pacman_power_mode_timer();
	}
	
	draw_game_state(game);
}

void win_game(Game* game){
	set_game_state(game, WON);
	
	disable_game_countdown();
	disable_pacman_movement();
	disable_power_pills_generation();
	resume_pacman_power_mode_timer();
	
	disable_RIT(); // Disable RIT polling of the joystick and the buttons
	
	//draw_game_state(game);
	draw_win_screen();
}

void lose_game(Game* game){
	set_game_state(game, GAME_OVER);
	
	disable_game_countdown();
	disable_pacman_movement();
	disable_power_pills_generation();
	resume_pacman_power_mode_timer();
	
	disable_RIT(); // Disable RIT polling of the joystick and the buttons
	
	//draw_game_state(game);
	draw_game_over_screen();
}

void add_life(Game* game){
	game->lives++;
}

void update_score(Game* game, uint16_t amount){
	// If the old tile was a pill update the game score	
		game->score += amount;
		
		//Add life every 1000 points
		if (game->score >= game->threshold_new_life){
			add_life(game);
			game->threshold_new_life += THRESHOLD_NEW_LIFE;
			draw_game_lives(game);
		}
		
		draw_game_score(game);
}

void enable_pacman_power_mode(Game* game){
	game->pacman_mode = POWER;
	
	if(game->blinky_mode == CHASE){
		game->blinky_mode = FRIGHTENED;
		draw_blinky(game->blinky_y, game->blinky_x, game->blinky_mode);
	}
	init_timer_simplified(TIMER_3, 0, TIM_MS_TO_TICKS_SIMPLE(PACMAN_POWER_MODE_DURATION), 0, TIMER_INTERRUPT_MR, 0);
	enable_timer(TIMER_3, TIMER3_PRIORITY);
}

void disable_pacman_power_mode(Game* game){
	game->pacman_mode = RUN;
	if(game->blinky_mode == FRIGHTENED){
		game->blinky_mode = CHASE;
		draw_blinky(game->blinky_y, game->blinky_x, game->blinky_mode);
	}
};

struct Coordinates place_random_power_pill(Game* game){
	srand(game->standard_pills_count);
	
	struct Coordinates power_pill_position;
	
	do{
		power_pill_position.row = rand() % MAP_LENGTH ;
		power_pill_position.col = rand() % MAP_HEIGHT ;
	}
	while( game->map[power_pill_position.row][power_pill_position.col].type != STANDARD_PILL );
	
	game->map[power_pill_position.row][power_pill_position.col].type = POWER_PILL;
	game->standard_pills_count--;
	game->power_pills_count++;
	game->power_pills_placed_count++;
	
	return power_pill_position;
}

void move_pacman(Game* game, int dx, int dy) {
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
	
	//Pacman does not move if it encounters a wall
	if (game->map[new_y][new_x].type == WALL) {
		return;
	}
	
	if (game->map[game->pacman_y][game->pacman_x].type != TELEPORT) {
		game->map[game->pacman_y][game->pacman_x].type = EMPTY_TILE;
	}
	
  game->pacman_x = new_x;
  game->pacman_y = new_y;
	
	Tile* new_tile = &(game->map[new_y][new_x]);
	if (is_a_pill(new_tile)) {
		update_score(game, get_tile_score(new_tile));
		if (new_tile->type == STANDARD_PILL) game->standard_pills_count--;
		else if (new_tile->type == POWER_PILL){
			game->power_pills_count--;
			enable_pacman_power_mode(game);
		}
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

void move_pacman_direction(Game* game){
	switch(game->pacman_direction){
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

void game_clock_tick(Game* game){
	game->time--;
		if(game->time == 0){
			lose_game(game);
		}else{
			draw_game_time(game);
		}
		
		if(game->blinky_mode == RESPAWNING){
			game->blinky_respawn_timeout--;
			if(game->blinky_respawn_timeout <= 0){
				spawn_blinky(game);
				draw_blinky(game->blinky_y, game->blinky_x, game->blinky_mode);
			}
		}
}