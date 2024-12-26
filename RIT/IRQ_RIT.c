#include "RIT.h"
#include "../led/led.h"
#include "../common.h"
#include "../timer/timer.h"
#include "../joystick/joystick.h"
#include "../button_EXINT/button.h"
#include "../adc/adc.h"

#include "../pacman/pacman.h"

volatile uint32_t pressed_button_0 = 0;
volatile uint32_t pressed_button_1 = 0;
volatile uint32_t pressed_button_2 = 0;

uint32_t pressed_joystick_up     = 0;
uint32_t pressed_joystick_left   = 0;
uint32_t pressed_joystick_right  = 0;
uint32_t pressed_joystick_down   = 0;
uint32_t pressed_joystick_select = 0;

volatile uint8_t btn_flag = 0;

void RIT_IRQHandler(void){	
	
	// -------------------------------
	// JOYSTICK UP
	// -------------------------------
	
	if(joystick_check_dir(JOYSTICK_UP)){
		pressed_joystick_up++;
		if(pressed_joystick_up == 1) {
			game.pacman_direction = UP;
		}
	}
	else pressed_joystick_up = 0;
	
	// -------------------------------
	// JOYSTICK DOWN
	// -------------------------------
	
	if(joystick_check_dir(JOYSTICK_DOWN)){
		pressed_joystick_down++;
		if(pressed_joystick_down == 1) {
			game.pacman_direction = DOWN;
		}
	}
	else pressed_joystick_down = 0;
	
	// -------------------------------
	// JOYSTICK LEFT
	// -------------------------------
	
	if(joystick_check_dir(JOYSTICK_LEFT)){
		pressed_joystick_left++;
		if(pressed_joystick_left == 1) {
			game.pacman_direction = LEFT;
		}
	}
	else pressed_joystick_left = 0;
	
	// -------------------------------
	// JOYSTICK RIGHT
	// -------------------------------
	
	if(joystick_check_dir(JOYSTICK_RIGHT)){
		pressed_joystick_right++;
		if(pressed_joystick_right == 1) {
			game.pacman_direction = RIGHT;
		}
	}
	else pressed_joystick_right = 0;
	
	// -------------------------------
	// JOYSTICK SELECT
	// -------------------------------
	
	if(joystick_check_dir(JOYSTICK_PRESS)){
		pressed_joystick_select++;
		if(pressed_joystick_select == 1) {

		}
	}
	else pressed_joystick_select = 0;
	
	// -------------------------------
	// BUTTON 0
	// -------------------------------
	
	if(pressed_button_0 != 0){
		if(LPC_GPIO2->FIOPIN & (1 << 10)){
			pressed_button_0++;
			//btn_flag |= FLAG_BUTTON_0;
			if(pressed_button_0 == 2){
				toggle_game_state(&game);
			}
			
			// check here for a longer press
			
		}else{
			pressed_button_0 = 0;
			NVIC_EnableIRQ(EINT0_IRQn);
			LPC_PINCON->PINSEL4 |= (1 << 20);
		}
	}
	
	// -------------------------------
	// BUTTON 1
	// -------------------------------
	
	if(pressed_button_1 != 0){
			pressed_button_1++;
			if(LPC_GPIO2->FIOPIN & (1 << 11)){
				btn_flag |= FLAG_BUTTON_1;
				
				pressed_button_1 = 0;
				NVIC_EnableIRQ(EINT1_IRQn);
				LPC_PINCON->PINSEL4 |= (1 << 22);
			}
	}

	// -------------------------------
	// BUTTON 2
	// -------------------------------
	
	if(pressed_button_2 != 0){
			pressed_button_2++;
			if(LPC_GPIO2->FIOPIN & (1 << 12)){
				btn_flag |= FLAG_BUTTON_2;
				
				pressed_button_2 = 0;
				NVIC_EnableIRQ(EINT2_IRQn);
				LPC_PINCON->PINSEL4 |= (1 << 24);
			}
	}
	
	// -------------------------------
	// ADC Conversion
	// -------------------------------
	
	// ADC_start_conversion();
	
	LPC_RIT->RICTRL |= 0x1;
}
/******************************************************************************
**                            End Of File
******************************************************************************/
