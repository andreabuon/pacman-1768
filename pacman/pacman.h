#include <stdint.h>

#define MAP_HEIGHT 31
#define MAP_LENGTH 28

#define STANDARD_PILLS_COUNT 240
#define POWER_PILLS_COUNT 6

#define STANDARD_PILL_SCORE 10
#define POWER_PILL_SCORE 50

#define PACMAN_INITIAL_POSITION_X 3
#define PACMAN_INITIAL_POSITION_Y 14

enum TileType {
  EMPTY_TILE,
	WALL,
  STANDARD_PILL,
  POWER_PILL,
	TELEPORT,
	PACMAN
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

enum GameState {
	READY,
	PLAYING,
	PAUSED,
	WON,
	GAME_OVER
};

typedef struct Game {
	enum GameState state;
	
	Tile map[MAP_HEIGHT][MAP_LENGTH];
	
	uint8_t lives;
	uint8_t score;
	uint8_t time;
	
	uint8_t standard_pills_count;
	uint8_t power_pills_count;
	
	uint8_t pacman_x;
	uint8_t pacman_y;
	
} Game;

void new_game(Game* game);
void start_game(Game* game);
void update_game_state(Game* game);

void display_game_info(Game* game);
void display_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);
void draw_pacman(uint16_t row, uint16_t col);

void generate_map(Tile map[MAP_HEIGHT][MAP_LENGTH]);

void add_life(Game* game);

void move_pacman(Game* game, int dx, int dy);

void move_pacman_up(Game* game);
void move_pacman_down(Game* game);
void move_pacman_left(Game* game);
void move_pacman_right(Game* game);
