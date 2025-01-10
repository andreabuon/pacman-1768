#ifndef PACMAN_H
#define PACMAN_H

#include <stdint.h>
#include "map.h"

#define INITIAL_GAME_TIME 60

#define INITIAL_STANDARD_PILLS_COUNT 240
#define INITIAL_POWER_PILLS_COUNT 0

#define POWER_PILLS_TO_PLACE 6

#define STANDARD_PILL_SCORE 10
#define POWER_PILL_SCORE 50

#define PACMAN_INITIAL_POSITION_X 3
#define PACMAN_INITIAL_POSITION_Y 14

#define PACMAN_POWER_MODE_DURATION 10000 //ms

#define INITIAL_BLINKY_SPEED_FACTOR 4

#define THRESHOLD_NEW_LIFE 1000

//Game timers priorities
#define RIT_PRIORITY PRIO_1
#define TIMER0_PRIORITY	PRIO_2
#define TIMER1_PRIORITY PRIO_3
#define TIMER2_PRIORITY PRIO_2
#define TIMER3_PRIORITY PRIO_3
#define BUTTON0_PRIORITY PRIO_0

enum GameState {
	READY,
	PLAYING,
	PAUSED,
	WON,
	GAME_OVER
};

enum Direction{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum PacmanMode{
	RUN,
	POWER
};

enum BlinkyMode{
	CHASE,
	FRIGHTENED,
	RESPAWNING
};

typedef struct Game {
	enum GameState state;
	
	Tile map[MAP_HEIGHT][MAP_LENGTH];
	
	uint8_t lives;
	uint16_t score;
	uint8_t time;
	
	uint8_t standard_pills_count;
	
	uint8_t power_pills_count; // Counts the number of power pills currently present in the map.
	uint8_t power_pills_placed_count; // Counts the number of power pills placed sine the beginning of the game
	uint32_t power_pills_spawn_times[POWER_PILLS_TO_PLACE]; // Contains the times (in ms) at which each power pill will be generated during the game.
	
	uint8_t pacman_x;
	uint8_t pacman_y;
	enum Direction pacman_direction;
	enum PacmanMode pacman_mode;
	
	enum BlinkyMode blinky_mode;
	uint8_t blinky_x;
	uint8_t blinky_y;
	uint8_t blinky_respawn_timeout;
	uint8_t blinky_speed_factor;
	
	
	uint16_t threshold_new_life;
	
} Game;

struct Coordinates {
	uint8_t row;
	uint8_t col;
};

extern Game game;

void init_game(Game* game);

void toggle_game_state(Game* game);

void start_game(Game* game);
void pause_game(Game* game);
void win_game(Game* game);
void lose_game(Game* game);

void set_game_state(Game* game, enum GameState state);

void add_life(Game* game);
void update_score(Game* game, uint16_t amount);

void enable_pacman_power_mode(Game* game);
void disable_pacman_power_mode(Game* game);

void disable_power_pills_generation();
struct Coordinates place_random_power_pill(Game* game);

void move_pacman(Game* game, int dx, int dy);
void move_pacman_up(Game* game);
void move_pacman_down(Game* game);
void move_pacman_left(Game* game);
void move_pacman_right(Game* game);
void move_pacman_direction(Game* game);

void game_clock_tick(Game* game);
void pacman_blinky_movement_tick(Game* game);
void powerpills_timer_tick(Game* game);

#endif // PACMAN_H *