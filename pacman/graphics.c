#include "graphics.h"
#include "../GLCD/GLCD.h"
#include <stdint.h>
#include <stdio.h>

//#include "sprites.c"

uint16_t pacman_sprite[8][8] = {
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Black, Black, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Black, Black, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Black, Black }
};

uint16_t power_pill[8][8] = {
		{ Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, Red, Red, Black, Black, Black },
    { Black, Black, Red, Red, Red, Red, Black, Black },
    { Black, Red, Red, Red, Red, Red, Red, Black },
    { Black, Red, Red, Red, Red, Red, Red, Black },
    { Black, Black, Red, Red, Red, Red, Black, Black },
    { Black, Black, Black, Red, Red, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black }
};

uint16_t standard_pill[8][8] = {
		{ Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, White, White, Black, Black, Black },
    { Black, Black, White, White, White, White, Black, Black },
    { Black, Black, White, White, White, White, Black, Black },
    { Black, Black, Black, White, White, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black }
};

void draw_power_pill(uint16_t col, uint16_t row){
	int i = 0;
	for(; i < 8; i++){
		int j = 0;
		for(; j < 8; j++){
			LCD_SetPoint(col + j, row + i, power_pill[i][j]);
		}
	}
}

void draw_standard_pill(uint16_t col, uint16_t row){
	int i = 0;
	for(; i < 8; i++){
		int j = 0;
		for(; j < 8; j++){
			LCD_SetPoint(col + j, row + i, standard_pill[i][j]);
		}
	}
}

void draw_tile(Tile map[MAP_HEIGHT][MAP_LENGTH], uint8_t row, uint8_t col){
	Tile tile = map[row][col];
	
	uint16_t initial_x = MARGIN_LEFT + ( TILE_SIZE_PIXELS * col );
	uint16_t initial_y = MARGIN_TOP + ( TILE_SIZE_PIXELS * row ) ;
	
	int color = 0;
	switch(tile.type){
		case EMPTY_TILE:
			color = Black;
			break;
		case WALL:
			color = Blue;
			break;
		case STANDARD_PILL:
			draw_standard_pill(initial_x, initial_y);
			return;
		case POWER_PILL:
			draw_power_pill(initial_x, initial_y);
			return;
		case TELEPORT:
			color = Black;
			break;
		
		default:
			break;
	}
	
	int i = 0;
	for(; i < 8; i++){
		int j = 0;
		for(; j < 8; j++){
			LCD_SetPoint(initial_x + j, initial_y + i , color);
		}
	}
}

void draw_map(Tile map[MAP_HEIGHT][MAP_LENGTH]){
	uint16_t row = 0;
	for(; row < MAP_HEIGHT; row++){
		uint16_t col = 0;
		for(; col < MAP_LENGTH; col++){
			draw_tile(map, row, col);
		}
	}
}

void draw_labels(){
	GUI_Text(0, 304, (uint8_t *) "Time: ", White, Black);
	GUI_Text(75, 304, (uint8_t *) "Lifes: ", White, Black);
	GUI_Text(150, 304, (uint8_t *) "Score: ", White, Black);
}

void draw_game_time(Game* game){
	char buf[5];
	sprintf(buf, "%02u", game->time);
	GUI_Text(45, 304, (uint8_t *) buf , White, Black);
}
	
void draw_game_lifes(Game* game){
	char buf[5];
	sprintf(buf, "%02u", game->lives);
	GUI_Text(125, 304, (uint8_t *) buf , White, Black);
}

void draw_game_score(Game* game){
	char buf[5];
	sprintf(buf, "%04u", game->score);
	GUI_Text(200, 304, (uint8_t *) buf, White, Black);
}

void draw_game_state(Game* game){
	char buf[11];
	switch(game->state){
		case READY:
			sprintf(buf, "%s", "READY     ");
			break;
		case PLAYING:
			sprintf(buf, "%s", "PLAYING   ");
			break;
		case PAUSED:
			sprintf(buf, "%s", "PAUSED    ");
			break;
		case WON:
			sprintf(buf, "%s", "WON       ");
			break;
		case GAME_OVER:
			sprintf(buf, "%s", "GAME OVER ");
			break;
		default:
			sprintf(buf, "%s", "ERR_STATE ");
			break;
	}
	GUI_Text(8, 280, (uint8_t *) buf, White, Black);
}

void draw_win_screen(){
	LCD_Clear(Blue);
	GUI_Text(85, 146, (uint8_t *) "YOU WON", White, Blue);
}

void draw_game_over_screen(){
	LCD_Clear(Red);
	GUI_Text(85, 146, (uint8_t *) "GAME OVER", Black, Red);
}

void draw_pacman(uint8_t row, uint8_t col){
	uint16_t initial_x = MARGIN_LEFT + ( TILE_SIZE_PIXELS * col );
	uint16_t initial_y = MARGIN_TOP + ( TILE_SIZE_PIXELS * row ) ;
	
	int i = 0;
	for(; i < 8; i++){
		int j = 0;
		for(; j < 8; j++){
			LCD_SetPoint(initial_y + j, initial_x + i, pacman_sprite[i][j]);
		}
	}
}