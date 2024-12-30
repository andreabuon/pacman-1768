#include "timer.h"
#include "../common.h"

#include "../pacman/pacman.h"
#include "../pacman/graphics.h"
#include "../pacman/blinky.h"

/*
	in IR si deve settare il bit associato al MR di cui si vuole cancellare l'interruzione.
*/

void TIMER0_IRQHandler (void){
	uint8_t irq_source = LPC_TIM0->IR;
	
	if(irq_source & IR_MR0) { // mr0
		game.time--;
		if(game.time == 0){
			lose_game(&game);
		}else{
			draw_game_time(&game);
		}
		
		if(game.blinky_mode == RESPAWNING){
			game.blinky_respawn_timeout--;
			if(game.blinky_respawn_timeout <= 0){
				spawn_blinky(&game);
				draw_blinky(game.blinky_y, game.blinky_x, game.blinky_mode);
			}
		}
	} else if(irq_source & IR_MR1) { // mr1
		
	} else if(irq_source & IR_MR2) { // mr2
		
	} else if(irq_source & IR_MR3) { // mr3
		
	}
	
	LPC_TIM0->IR = irq_source;
	return;
}

void TIMER1_IRQHandler (void){
	uint8_t irq_source = LPC_TIM1->IR;
	
	if(irq_source & IR_MR0) { // mr0
		uint8_t previous_pacman_x = game.pacman_x;
		uint8_t previous_pacman_y = game.pacman_y;
		
		uint8_t previous_blinky_x = game.blinky_x;
		uint8_t previous_blinky_y = game.blinky_y;
		
		move_pacman_direction(&game);
		move_blinky_direction(&game, game.pacman_direction);
		
		// if pacman moved, render the previous tile it was in and render its sprite on the next one
		if(game.pacman_x != previous_pacman_x || game.pacman_y != previous_pacman_y){
			draw_tile(game.map, previous_pacman_y, previous_pacman_x);
			draw_pacman(game.pacman_y, game.pacman_x, game.pacman_direction);
		}
		
		// if Blinky moved, render the previous tile it was in and render its sprite on the next one
		if(game.blinky_x != previous_blinky_x || game.blinky_y != previous_blinky_y){
			draw_tile(game.map, previous_blinky_y, previous_blinky_x);
			draw_blinky(game.blinky_y, game.blinky_x, game.blinky_mode);
		}
		
		//Pacman and Blinky meet
		if(game.pacman_x == game.blinky_x && game.pacman_y == game.blinky_y){
			if(game.blinky_mode == CHASE){
				game.lives--;
				if(game.lives <= 0){
					lose_game(&game);		
					LPC_TIM1->IR = irq_source;
					return;
				}
				draw_game_lives(&game);
				//draw_tile(game.map, game.pacman_x, game.pacman_y); //Commented becasue in that tile there is Blinky
				
				game.pacman_x = PACMAN_INITIAL_POSITION_X;
				game.pacman_y = PACMAN_INITIAL_POSITION_Y;
				game.pacman_direction = RIGHT;
				
				draw_pacman(game.pacman_y, game.pacman_x, game.pacman_direction);
			}
			else if (game.blinky_mode == FRIGHTENED){
				//draw_tile(game.map, game.blinky_y, game.blinky_x); //Commented becasue in that tile Pacman is already there
				kill_blinky(&game);
				update_score(&game, 100);
				
				draw_pacman(game.pacman_y, game.pacman_x, game.pacman_direction);
			}
		}
		
	} else if(irq_source & IR_MR1) { // mr1
		
	} else if(irq_source & IR_MR2) { // mr2
		
	} else if(irq_source & IR_MR3) { // mr3
		
	}
	
	LPC_TIM1->IR = irq_source;
	return;
}


void TIMER2_IRQHandler(void){
	uint8_t irq_source = LPC_TIM2->IR;
	
	if(irq_source & IR_MR0) { // mr0
		if(game.power_pills_placed_count < POWER_PILLS_TO_PLACE){
			struct Coordinates power_pill_position = place_random_power_pill(&game);
			draw_tile(game.map, power_pill_position.row, power_pill_position.col);
			LPC_TIM2->MR0 = TIM_MS_TO_TICKS_SIMPLE(game.power_pills_spawn_times[game.power_pills_placed_count]);
		}
	} else if(irq_source & IR_MR1) { // mr1
		
	} else if(irq_source & IR_MR2) { // mr2
		
	} else if(irq_source & IR_MR3) { // mr3
		
	}
	
	LPC_TIM2->IR = irq_source;
	return;
}

void TIMER3_IRQHandler (void){
	uint8_t irq_source = LPC_TIM3->IR;
	
	if(irq_source & IR_MR0) { // mr0
		disable_pacman_eating_mode(&game);
	} else if(irq_source & IR_MR1) { // mr1
		
	} else if(irq_source & IR_MR2) { // mr2
		
	} else if(irq_source & IR_MR3) { // mr3
		
	}
	
	LPC_TIM3->IR = irq_source;
	return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/

