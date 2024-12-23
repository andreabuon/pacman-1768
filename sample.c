#include "include.h"
#include "common.h"

#include "pacman/pacman.h"
#include "pacman/graphics.h"

//#define N 8 see common.h
#define RIT_PERIOD_MS 50U

// Private Variables
static volatile uint32_t Sys_Tick = 0;

// Local Functions Prototypes
static void InitSysTick(void);
void SysTick_Handler(void);
void Delay_SysTick(uint32_t SysTicks);

// Imported Variables
extern uint8_t joystick_flag;
extern uint8_t btn_flag;

Game game; //FIXME
enum Direction movement_direction = RIGHT;

int main (void) {
	SystemInit();
	InitSysTick();
	
	LED_init();
	joystick_init();
	LCD_Initialization();
	
	BUTTON_init(BUTTON_0, PRIO_3);
	
	// RIT WORKS WITH CLOCK = 100MHZ
	// ONE INTERRUPT EVERY 50ms
	init_RIT(RIT_MS_TO_TICKS(RIT_PERIOD_MS));
	
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
	init_timer_simplified(TIMER_1, 1, TIM_MS_TO_TICKS_SIMPLE(70), 0, TIMER_INTERRUPT_MR | TIMER_RESET_MR, 0);
	
	// power control register
	LPC_SC->PCON |= 0x1;			// PM0=1
	LPC_SC->PCON &= 0xFFFFFFFFD;	// PM1=0
	
	LCD_Clear(Black);

	new_game(&game);
	
	draw_labels();
	draw_game_time(&game);
	draw_game_lifes(&game);
	draw_game_score(&game);
	draw_game_state(&game);
	
	draw_map(game.map);

	while(1){
			__ASM("wfi");
	}
}

/* Initialize SysTick using CMSIS Core_CM4 function */
static void InitSysTick(void){
	SysTick_Config(SystemFrequency/1000U); /* Configure the SysTick timer */
}
/* SysTick Interrupt Handler */
void SysTick_Handler(void){
	Sys_Tick++; /* increment timer */
}
/* Delay Function based on SysTick Counter */
void Delay_SysTick(uint32_t SysTicks){
	uint32_t DelayTimer_SysTick = Sys_GetTick() + SysTicks; /* Get End Tick */
	while(Sys_GetTick() < DelayTimer_SysTick); 				/* wait for timer */
}
/*Get Current Elapsed Ticks*/
uint32_t Sys_GetTick(void){
	return Sys_Tick;
}