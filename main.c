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
		moveLeftForward();
	}

	return 0;
}
