#include "music.h"

#include "../timer/timer.h"
#include "pacman.h"

void playNote(NOTE note)
{
	if(note.freq != REST)
	{
		reset_timer(TIMER_2);
		init_timer_simplified(TIMER_2, 0, note.freq*AMPLIFIER*VOLUME, 0, TIMER_INTERRUPT_MR, 0);
		enable_timer(TIMER_2, 0);
	}
	reset_timer(TIMER_3);
	init_timer_simplified(TIMER_3, 0, note.duration, 0, TIMER_RESET_MR | TIMER_STOP_MR | TIMER_INTERRUPT_MR, 0);
	enable_timer(TIMER_3, 0);
}

BOOL isNotePlaying(void)
{
	return ((LPC_TIM2->TCR != 0) || (LPC_TIM3->TCR != 0));
}
