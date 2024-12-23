#include "timer.h"
#include "../common.h"

#include "../pacman/pacman.h"
#include "../pacman/graphics.h"

/*
	in IR si deve settare il bit associato al MR di cui si vuole cancellare l'interruzione.
*/

extern Game game; //FIXME
extern enum Direction movement_direction; //FIXME

void TIMER0_IRQHandler (void){
	uint8_t irq_source = LPC_TIM0->IR;
	
	if(irq_source & IR_MR0) { // mr0
		game.time--;
		if(game.time == 0){
			lose_game(&game);
		}
		draw_game_time(&game);
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
		int old_tile_x = game.pacman_x;
		int old_tile_y = game.pacman_y;
		
		move_pacman_direction(&game, movement_direction);
		
		draw_tile(game.map, old_tile_y, old_tile_x);
		draw_pacman(game.pacman_x, game.pacman_y); //FIXME 
		
		draw_game_score(&game);
		draw_game_lifes(&game);
		draw_game_state(&game); //FIXME move somewhere else? draw only on change?
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
		//place_power_pill(&game);
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

