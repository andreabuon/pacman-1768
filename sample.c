#include <stdlib.h>
#include "include.h"
#include "common.h"

#include "pacman/pacman.h"
#include "pacman/graphics.h"

#ifdef SIMULATOR
#define RIT_PERIOD_MS 150U
#define PACMAN_MOVEMENT_MS 200U
#else
#define RIT_PERIOD_MS 50U
#define PACMAN_MOVEMENT_MS 75U
#endif

Game game; //FIXME Global

int main (void) {
	SystemInit();
	
	LED_init();
	joystick_init();
	LCD_Initialization();
	
	// RIT WORKS WITH CLOCK = 100MHZ
	init_RIT(RIT_MS_TO_TICKS(RIT_PERIOD_MS));
	// RIT used for joystick polling, button debouncing and as a seed for the random number generator
	enable_RIT(); 
	
	/* TIMER INSTRUCTIONS
	//	init_timer_simplified:
	//		1: which timer
	// 		2: prescaler
	//		3: mr0
	// 		4: mr1
	//		5: configuration of MR0 (interrupt, reset and stop) ( | of TIMER_INTERRUPT_MR, TIMER_RESET_MR, TIMER_STOP_MR)
	//		6: configuration of MR1 (interrupt, reset and stop) ( | of TIMER_INTERRUPT_MR, TIMER_RESET_MR, TIMER_STOP_MR)
	*/
	
	// Game Time countdown update
	init_timer_simplified(TIMER_0, 0, TIM_MS_TO_TICKS_SIMPLE(1000), 0, TIMER_INTERRUPT_MR | TIMER_RESET_MR, 0);
	
	// Pacman movement
	init_timer_simplified(TIMER_1, 0, TIM_MS_TO_TICKS_SIMPLE(PACMAN_MOVEMENT_MS), 0, TIMER_INTERRUPT_MR | TIMER_RESET_MR, 0);
		
	// power control register
	LPC_SC->PCON |= 0x1;			// PM0=1
	LPC_SC->PCON &= 0xFFFFFFFFD;	// PM1=0
	
	LCD_Clear(Black);
	GUI_Text(8, 280, (uint8_t *) "LOADING", White, Black);

	// Seed the random number generator
	//srand(game.standard_pills_count);
	srand(LPC_RIT->RICOUNTER);

	init_game(&game);
	
	// Random power pills generation
	init_timer_simplified(TIMER_2, 0, TIM_MS_TO_TICKS_SIMPLE(game.power_pills_spawn_times[0]), 0, TIMER_INTERRUPT_MR, 0);
	
	draw_map(game.map);
	
	draw_pacman(game.pacman_y, game.pacman_x, game.pacman_direction);
	draw_blinky(game.blinky_y, game.blinky_x, game.blinky_mode);
	
	draw_labels();
	draw_game_time(&game);
	draw_game_lives(&game);
	draw_game_score(&game);
	draw_game_state(&game);
	
	NVIC_SetPriority(RIT_IRQn, RIT_PRIORITY );
	NVIC_SetPriority(TIMER0_IRQn, TIMER0_PRIORITY );
	NVIC_SetPriority(TIMER1_IRQn, TIMER1_PRIORITY );
	NVIC_SetPriority(TIMER2_IRQn, TIMER2_PRIORITY );
	
	//Enable button only after game has loaded
	BUTTON_init(BUTTON_0, BUTTON0_PRIORITY);

	while(1){
			__ASM("wfi");
	}
}