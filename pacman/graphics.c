#include "graphics.h"
#include "../GLCD/GLCD.h"
#include <stdint.h>

void display_tile(uint16_t row, uint16_t col, Tile* tile){
	int color = 0;
	switch(tile->type){
		case EMPTY_TILE:
			color = Black;
			break;
		case WALL:
			color = Blue;
			break;
		case STANDARD_PILL:
			color = White;
			break;
		case POWER_PILL:
			color = Red;
			break;
		case TELEPORT:
			color = Blue;
			break;
		case PACMAN:
			color = Yellow;
			break;
		
		default:
			break;
	}
	
	int i = 0;
	for(; i < 8; i++){
		int j = 0;
		for(; j < 8; j++){
			LCD_SetPoint(MARGIN_LEFT +8*col + j, MARGIN_TOP + 8*row + i , color);
		}
	}
}

void display_map(Tile map[MAP_HEIGHT][MAP_LENGTH]){
	uint16_t row = 0;
	for(; row < MAP_HEIGHT; row++){
		uint16_t col = 0;
		for(; col < MAP_LENGTH; col++){
			display_tile(row, col, &map[row][col]);
		}
	}
}


void display_game_info(Game* game){
	GUI_Text(0, 304, (uint8_t *) "Time: -- ", White, Black);
	
	GUI_Text(90, 304, (uint8_t *) "Lifes: - ", White, Black);
	
	GUI_Text(150, 304, (uint8_t *) "Score: ----", White, Black);
}

void draw_pacman(uint16_t row, uint16_t col){
	int i = 0;
	for(; i < 8; i++){
		int j = 0;
		for(; j < 8; j++){
			LCD_SetPoint(MARGIN_LEFT +8*row + j, MARGIN_TOP + 8*col + i , Yellow);
		}
	}
}