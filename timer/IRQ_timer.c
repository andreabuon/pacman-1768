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
		powerpills_timer_tick(&game);
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

