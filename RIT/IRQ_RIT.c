#include "RIT.h"
#include "../led/led.h"
#include "../common.h"
#include "../timer/timer.h"
#include "../joystick/joystick.h"
#include "../button_EXINT/button.h"

#include "../pacman/pacman.h"
#include "../pacman/music.h"

volatile uint32_t pressed_button_0 = 0;

uint32_t pressed_joystick_up     = 0;
uint32_t pressed_joystick_left   = 0;
uint32_t pressed_joystick_right  = 0;
uint32_t pressed_joystick_down   = 0;
uint32_t pressed_joystick_select = 0;

#define UPTICKS 1
NOTE song[] = 
{
		// 1
	{NOTE_D3, time_16th},
	{NOTE_D3, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 2
	{NOTE_C3, time_16th},
	{NOTE_C3, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 3
	{NOTE_C3B, time_16th},
	{NOTE_C3B, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 4
	{NOTE_GS2, time_16th},
	{NOTE_GS2, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 5 (remaining part of the song)
};

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
		if(LPC_GPIO2->FIOPIN & (1 << 10)){ // Button released
				pressed_button_0 = 0;
				NVIC_EnableIRQ(EINT0_IRQn);
				LPC_PINCON->PINSEL4 |= (1 << 20);
		} else {
			pressed_button_0++;
			if(pressed_button_0 == 2){
				toggle_game_state(&game);
			}
		}
	}
	
	static int currentNote = 0;
	static int ticks = 0;
	if(!isNotePlaying())
	{
		++ticks;
		if(ticks == UPTICKS)
		{
			ticks = 0;
			playNote(song[currentNote++]);
		}
	}
	
	if(currentNote == (sizeof(song) / sizeof(song[0])))
	{
		disable_RIT();
	}
	
	LPC_RIT->RICTRL |= 0x1;
}
/******************************************************************************
**                            End Of File
******************************************************************************/
