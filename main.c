#include <msp430.h> 
#include "robot_motion.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    InitPinsOut();
    InitTimer();


	while (1) {
		rightTurn();
		_delay_cycles(1000000);
		leftTurn();
		_delay_cycles(1000000);
	}

	return 0;
}
