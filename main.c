#include <msp430.h> 

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer



	while (1) {
		__delay_cycles(1000000);
		TACCR1 = 50;            // set duty cycle to 50/100 (50%)
		__delay_cycles(1000000);
		TACCR1 = 75;            // set duty cycle to 75/100 (75%)
		__delay_cycles(1000000);
		TACCR1 = 100;            // set duty cycle to 100/100 (100%)
		__delay_cycles(1000000);
		TACCR1 = 25;            // set duty cycle to 25/100 (25%)
	}

	return 0;
}
