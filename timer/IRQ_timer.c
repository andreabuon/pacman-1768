#include "timer.h"
#include "../common.h"

#include "../pacman/pacman.h"
#include "../pacman/graphics.h"

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
		
		move_pacman_direction(&game);
		
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

