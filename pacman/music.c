#include "music.h"

#include "../timer/timer.h"
#include "pacman.h"
#include <stdbool.h>

void playNote(NOTE note)
{
	if(note.freq != REST)
	{
		reset_timer(TIMER_2);
		init_timer_simplified(TIMER_2, 0, note.freq*AMPLIFIER*VOLUME, 0, TIMER_INTERRUPT_MR | TIMER_RESET_MR, 0);
		enable_timer(TIMER_2, TIMER2_PRIORITY);
	}
	reset_timer(TIMER_3);
	init_timer_simplified(TIMER_3, 0, note.duration, 0, TIMER_RESET_MR | TIMER_STOP_MR | TIMER_INTERRUPT_MR, 0);
	enable_timer(TIMER_3, TIMER3_PRIORITY);
}

BOOL isNotePlaying(void)
{
	return ((LPC_TIM2->TCR != 0) || (LPC_TIM3->TCR != 0));
}

void playSongOnce(const NOTE* song, size_t songLength) {
	static unsigned int currentNote = 0;
	static bool playSong = true;
    if (playSong) {
        if (!isNotePlaying()) {
            if (currentNote < songLength) {
                playNote(song[currentNote++]);
            } else {
                // Stop the song after all notes are played
                playSong = false;
                currentNote = 0;
            }
        }
    }
}