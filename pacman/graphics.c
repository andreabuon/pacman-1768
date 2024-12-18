#include "graphics.h"
#include "../GLCD/GLCD.h"
#include <stdint.h>
#include <stdio.h>

void draw_tile(Tile map[MAP_HEIGHT][MAP_LENGTH], uint8_t row, uint8_t col){
	Tile tile = map[row][col];
	
	int color = 0;
	switch(tile.type){
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
			color = Green;
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
	GUI_Text(80, 304, (uint8_t *) "Lifes: ", White, Black);
	GUI_Text(150, 304, (uint8_t *) "Score: ", White, Black);
}

void draw_game_time(Game* game){
	char buf[5];
	sprintf(buf, "%u", game->time);
	GUI_Text(50, 304, (uint8_t *) buf , White, Black);
}
	
void draw_game_lifes(Game* game){
	char buf[5];
	sprintf(buf, "%u", game->lives);
	GUI_Text(135, 304, (uint8_t *) buf , White, Black);
}

void draw_game_score(Game* game){
	char buf[5];
	sprintf(buf, "%u", game->score);
	GUI_Text(200, 304, (uint8_t *) buf, White, Black);
}

void draw_game_state(Game* game){
	char buf[11];
	switch(game->state){
		case READY:
			sprintf(buf, "%s", "READY");
			break;
		case PLAYING:
			sprintf(buf, "%s", "PLAYING");
			break;
		case PAUSED:
			sprintf(buf, "%s", "PAUSED");
			break;
		case WON:
			sprintf(buf, "%s", "WON");
			break;
		case GAME_OVER:
			sprintf(buf, "%s", "GAME_OVER");
			break;
		default:
			sprintf(buf, "%s", "ERROR");
			break;
	}
	GUI_Text(8, 280, (uint8_t *) buf, White, Black);
}

void draw_pacman(uint8_t row, uint8_t col){
	int i = 0;
	for(; i < 8; i++){
		int j = 0;
		for(; j < 8; j++){
			LCD_SetPoint(MARGIN_LEFT +8*row + j, MARGIN_TOP + 8*col + i , Yellow);
		}
	}
}