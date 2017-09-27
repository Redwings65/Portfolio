#include <msp430.h>

int counter = 1; //Global var to use in interupt function and main func

int main(void)
{

    WDTCTL  = WDTPW | WDTHOLD; // wizard words
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL  = CALDCO_1MHZ;

    P1DIR = 7;//0x07,0b00000111, BIT2 | BIT1 | BIT0 // P1.0, P1.1 and P1.2 outputs
    P1OUT = counter; // P1.0, P1.1 on (yellow)

    P2DIR = -1; // all P2 pins outputs
    P2OUT = 0;  // all P2 pins off

    P1REN   = 8;  // enable pull-up/down resistor for P1.3
    P1OUT  |= 8;  // select pull-up resistor (not pull-down)
    P1IE   |= 8;  // enable interrupt for P1.3
    P1IES  |= 8;  // select high-to-low transition
    P1IFG  &= ~8; // clear interrupt flag

    _BIS_SR(LPM4_bits | GIE); // go to sleep

    return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void whatever(void)
{
    P1OUT = BIT3 | (counter++ % 7); //cant go to 8 because register already have a value there, be extra careful setting bits in this register, you might overwrite something you don't want to overwrite
while (!(BIT3 & P1IN)) {} // is finger off of button yet?
  __delay_cycles(32000); // wait 32ms
  P1IFG &= ~BIT3; // clear interrupt flag
}

//&__P1OUT to get value of P1OUT

//CROSS COMPILATION
