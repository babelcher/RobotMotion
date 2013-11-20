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
		moveRightBackward();
		_delay_cycles(1000000);
		moveRightForward();
		_delay_cycles(1000000);
	}

	return 0;
}
