#include "button.h"
#include "../RIT/RIT.h"

#include "../pacman/pacman.h"

extern int pressed_button_0;

void EINT0_IRQHandler(void){
	
	// Variable set to 1	
    pressed_button_0 = 1;
	// Disable interrupt
    NVIC_DisableIRQ(EINT0_IRQn);
	// Remove interrput bit
    LPC_SC->EXTINT |= (1 << 0);
	// Change pin selection so that the button 
	// does not work any longer. 
    LPC_PINCON->PINSEL4 &= ~(1 << 20);
}

void EINT1_IRQHandler(void){

}

void EINT2_IRQHandler(void){

}

/******************************************************************************
**                            End Of File
******************************************************************************/
