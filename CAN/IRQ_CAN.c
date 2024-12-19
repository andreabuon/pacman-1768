/*----------------------------------------------------------------------------
 * Name:    Can.c
 * Purpose: CAN interface for for LPC17xx with MCB1700
 * Note(s): see also http://www.port.de/engl/canprod/sv_req_form.html
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC17xx.h>                  /* LPC17xx definitions */
#include "CAN.h"                      /* LPC17xx CAN adaption layer */
#include "../GLCD/GLCD.h"

#include "../pacman/pacman.h"
#include "../pacman/graphics.h"

extern uint8_t icr ; 										//icr and result must be global in order to work with both real and simulated landtiger.
extern uint32_t result;
extern CAN_msg       CAN_TxMsg;    /* CAN message for sending */
extern CAN_msg       CAN_RxMsg;    /* CAN message for receiving */                                

extern Game game;

/*----------------------------------------------------------------------------
  CAN interrupt handler
 *----------------------------------------------------------------------------*/
void CAN_IRQHandler (void)  {
  icr = (LPC_CAN1->ICR | icr) & 0xFF;   
	icr = (LPC_CAN2->ICR | icr) & 0xFF;             /* clear interrupts */
	
	if (icr & (1 << 0)) {						/* CAN Controller #2 meassage is received */
		CAN_rdMsg (2, &CAN_RxMsg);		/* Read the message */
		LPC_CAN2->CMR = (1 << 2);			/* Release receive buffer */

		uint8_t time = (uint8_t) CAN_RxMsg.data[0] ;
		uint8_t lifes = (uint8_t) CAN_RxMsg.data[1] ;
		uint16_t score = (uint16_t) ( (uint8_t) CAN_RxMsg.data[2] << 8 ) | (uint8_t) CAN_RxMsg.data[3] ;
		
		draw_game_time(time);
		draw_game_lifes(lifes);
		draw_game_score(score);
		
		icr = (LPC_CAN2->ICR | icr) & 0xFF;             /* clear interrupts */
	}
}
