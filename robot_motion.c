#include <msp430.h>
#include "robot_motion.h"
/*
 * robot_motion.c
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Brandon.Belcher
 */

void InitPinsOut() {
	P1DIR |= BIT1;
	P1SEL |= BIT1;

	P1DIR |= BIT2;
	P1SEL |= BIT2;

	P2DIR |= BIT0;
	P2SEL |= BIT0;

	P2DIR |= BIT1;
	P2SEL |= BIT1;
}

void InitTimer() {
	TA0CTL &= ~MC1 | MC0;
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;

	TA0CCR0 = 100;   // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR0 = 100;	//
	TA0CCR1 = 0;	//
	TA1CCR1 = 0;	//

	TA0CCTL1 |= OUTMOD_7;
	TA0CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL0 |= OUTMOD_5;


	TA0CTL |= MC0;	//count up
	TA1CTL |= MC0;

}

void moveLeftForward(){
	TA0CCR1 = 50;
	TA0CCTL0 = OUTMOD_5;
}

void moveRightBackward(){
	TA1CCR1 = 50;
	TA1CCTL0 = OUTMOD_5;
}

void moveLeftBackward(){
	TA0CCR1 = 0;
	TA0CCTL0 = OUTMOD_4;
}

void moveRightForward(){
	TA1CCR1 = 0;
	TA1CCTL0 = OUTMOD_4;
}

void moveForward(){
	moveLeftForward();
	moveRightForward();
}

void moveBackward(){
	moveLeftBackward();
	moveRightBackward();
}

void rightTurn(){
	moveLeftForward();
	moveRightBackward();
}

void leftTurn(){
	moveLeftBackward();
	moveRightForward();
}
