#include <msp430.h>
#define  BTN  BIT3
int flip = 0;

int main(void)
{

    WDTCTL  = WDTPW | WDTHOLD; // wizard words
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL  = CALDCO_1MHZ;

    P1DIR = 7;//0x07,0b00000111, BIT2 | BIT1 | BIT0 // P1.0, P1.1 and P1.2 outputs
    P1OUT = 0; // P1.0, P1.1 on (yellow) this use to be counter

    P1REN   = 8;  // enable pull-up/down resistor for P1.3
    P1OUT  |= 8;  // select pull-up resistor (not pull-down)
    P1IE   |= 8;  // enable interrupt for P1.3
    P1IES  |= 8;  // select high-to-low transition
    P1IFG  &= ~8; // clear interrupt flag


    TA0CTL   = TASSEL_2 | MC_1 | ID_3;
    TA0CCTL0 = CCIE;
    TA0CCR0  = 41667;
    TA0CCTL1 = OUTMOD_4;


    P2DIR = BIT1;
    P2OUT = 0;
    //P2SEL |= BIT1;

    TA1CTL   = TASSEL_2 | MC_1 | ID_3;
    TA1CCR0  = 62500 - 1;
    TA1CCTL1 = OUTMOD_4;




    __eint();
    for(;;){

      if(flip == 0){//Mode 1 works great
        while((P1IN & BTN) == BTN){
          P1OUT ^= BIT0;
          __delay_cycles(500000);
          if(flip == 1){
            break;
          }
        }
        P1OUT &= ~BIT0;
      }

      else if(flip == 1){//Mode 2 works great
        while((P1IN & BTN) == BTN){
          //P1OUT ^= (BIT1);//this one needs to be timer and interrupt
          //__delay_cycles(333333);//this works
          P1OUT ^= BIT0;
          __delay_cycles(500000);
          if(flip == 2){
            break;
          }
        }
        P1OUT &= ~BIT1;
        P1OUT &= ~BIT0;
      }
      else if(flip == 2){
        while((P1IN & BTN) == BTN){
          //P1OUT ^= (BIT1); //this one is timer and interrupt as well
          //__delay_cycles(333333);
          //P1OUT ^= (BIT2);
          //__delay_cycles(250000);//this needs to be timer and signal as well
          P2SEL |= BIT1;
          if(flip == 3){
            break;
          }
        }
        P2SEL = 0;
        //P1OUT &= ~BIT2;
        P1OUT &= ~BIT1;
      }
      else if(flip == 3){
        while((P1IN & BTN) == BTN){
          P2SEL |= BIT1;
          //P1OUT ^= (BIT2);
          //__delay_cycles(500000);//needs to be timer and signal
          if(flip == 0){
            break;
          }
        }
        P2SEL = 0;
        //P1OUT &= ~BIT2;
        flip = 0;
      }

    }
    //_BIS_SR(LPM4_bits | GIE); // go to sleep

    return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void button(void)
{
while (!(BIT3 & P1IN)) {} // is finger off of button yet?
  if(flip == 3){
    flip = 0;
  }
  else{
    flip = flip + 1;
  }
  P1IFG &= ~BTN; // clear interrupt flag happens everytime
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void blink (void)
{
  if (flip == 1 || flip == 2){
    P1OUT ^= (BIT1);
  }
  else{
    //do nothing
  }

}

//&__P1OUT to get value of P1OUT

//CROSS COMPILATION
