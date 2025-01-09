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
		game_clock_tick(&game);
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
		pacman_blinky_movement_tick(&game);
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
			disable_timer(TIMER_2);
			
			struct Coordinates power_pill_position = place_random_power_pill(&game);
			draw_tile(game.map, power_pill_position.row, power_pill_position.col);
			
			LPC_TIM2->MR0 = TIM_MS_TO_TICKS_SIMPLE(game.power_pills_spawn_times[game.power_pills_placed_count]);
			enable_timer(TIMER_2, TIMER2_PRIORITY);
		}else{
			disable_power_pills_generation();
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
		disable_pacman_power_mode(&game);
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

