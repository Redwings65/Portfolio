/*
Assignment #4 Color selector
Produced By: Brandon Seager
*/
/******
 *
 *    INCLUDES
 *
 ******/
#include "dtc.h"                      //needed to include the header file
#include <msp430.h>                   //always needed to work with msp
#include <libemb/serial/serial.h>     //may not be needed
#include <libemb/conio/conio.h>       //may not be needed
#include <libemb/shell/shell.h>       //may not be needed
#include <stdlib.h>                   //may not be needed
/******
 *
 *    CONSTANTS
 *
 ******/
#define BTN BIT3
#define middle BIT6
#define left BIT5
#define right BIT7
//0 = top,2 = bottom right, 3 = bottom, 5 = top left, 6 = middle, 7 = bottom left
//p1.1 = top right in case you need to shut off bit1
/******
 *
 *    GLOBALS
 *
 ******/
int color = 1;              //Used to Switch colors later on
char eachSegment[18] = {(BIT6),(BIT0 | BIT3 | BIT6 | BIT7 | BIT5),(BIT5 | BIT2),(BIT5 | BIT7),(BIT0 | BIT3 | BIT7),(BIT7),(BIT1),(BIT5+BIT6+BIT7+BIT3),(-1 + BIT0),(BIT3 | BIT7),(BIT3),(BIT0),(BIT6 | BIT2),(BIT0 | BIT5),(BIT2),(BIT2 | BIT3),(BIT6 | BIT2 | BIT3),(BIT7)};
char segs[18] = {(BTN),(BTN),(BTN),(BTN),(BTN),(BTN | BIT1),(BTN | BIT1),(BTN),(BTN),(BTN),(BTN),(BTN | BIT1),(BTN),(BTN),(BTN | BIT1),(BTN | BIT1),(BTN),(BTN)}; //second array is needed because of p2.1
int number = 0;                                                                                    //10
int secondNumber = 0;
int colors = 0;
int temp = 0;
/******
 *
 *    INITIALIZATION
 *
 ******/
int main(void)
{
  /* CLOCKS *********************************/
  WDTCTL  = WDTPW | WDTHOLD;              // wizard words
  BCSCTL1 = CALBC1_1MHZ;                  //not important
  DCOCTL  = CALDCO_1MHZ;                  //blah blah

  /* GPIO ***********************************/
  P1DIR = 7 | ~(BIT3);                //enable all pins as outputs and something with the button
  P2DIR = -1;                         // enable all p2 pins as outputs

  P2SEL = BIT1; //| BIT4;            //selct p2.1 to be used for the dial interrupt
  P1SEL = BIT2;                     //select p1.2 to be used for the dial interrupt

  P1REN |= BIT3;                      //Needed for the Button
  P1OUT |= BIT3;                      //Needed for the Button
  P1IE  |= BIT3;                      //Needed for the Button
  P1IES |= BIT3;                      //Needed for the Button
  P1IFG &= (~BIT3);                   //Needed for the Button

  /* TIMER A0 *******************************/
  TA0CTL   = TASSEL_2 | MC_1 | ID_3;      // use TA0.1 for PWM on P1.6
  TA0CCR0  = 500;//0x3FF; //original            // 10-bit maximum value
  TA0CCR1  = 0;                           // start off
  TA0CCTL0 = CCIE;
  TA0CCTL1 = OUTMOD_7;                    // reset/set output mode

  /* TIMER A1 *******************************/
  TA1CTL   = TASSEL_2 | MC_1 | ID_3;      // use TA1.1 for PWM on P2.1
  TA1CCR0  = 0x3FF;                       // 10-bit maximum value
  TA1CCR1  = 0;                           // start off
  TA1CCTL0 = CCIE;
  TA1CCTL1 = OUTMOD_7;                    // reset/set output mode

  TA1CTL   = TASSEL_2 | MC_1 | ID_3;      // use TA1.2 for PWM on P2.5
  TA1CCR2  = 0x3FF;                       // 10-bit maximum value
  TA1CCR1  = 0;                           // start off
  TA1CCTL2 = OUTMOD_7;                    // reset/set output mode

  ADC10CTL1 = INCH_4 | ADC10DIV_3;        // ADC10 channel 4, clock divider 3
  ADC10CTL0 = SREF_0 | ADC10SHT_3 |       // VCC/VSS ref, 64 x ADC10CLKs
             ADC10ON | ADC10IE;           // ADC10 enable, ADC10 interrupt enable
  ADC10AE0  = BIT4;                       // analog enable channel 4

   __enable_interrupt();                // interrupts enabled
   /******
    *
    *    PROGRAM LOOP
    *
    ******/
  for(;;)                              //endless for loop
  {
      __delay_cycles(10000);              // wait for ADC ref to settle
      ADC10CTL0 |= ENC + ADC10SC;         // sampling and conversion start
      if(color == 1){
          TA0CCR1 = ADC10MEM & 0x3F8;         // assigns the value held in ADC10MEM to the TA0CCR1 register
          number = ((ADC10MEM / 4) % 16);    //convert value to needed range and assign to first number to be displayed
          secondNumber = (((ADC10MEM / 4) / 16));      //converts value to needed range and assign to second number to be displayed
          colors = 16;                      //16 is R on the array
      }else if(color == 2){
          TA1CCR1 = ADC10MEM & 0x3F8;       // assigns the value held in ADC10MEM to the TA1CCR1 register
          number = ((ADC10MEM / 4) % 16);   //finding the first number to be displayed
          secondNumber = (((ADC10MEM / 4) / 16));     //finding the second number to be displayed
          colors = 17;                   //17 is G on the array
      }else if(color == 3){
          P2SEL =  BIT1 | BIT4;             //select the Blue Light when needed
          TA1CCR2 = ADC10MEM & 0x3F8;       // assigns the value held in ADC10MEM to the TA1CCR2 register
          number = ((ADC10MEM / 4) % 16);     //finding the first number to be displayed
          secondNumber = (((ADC10MEM / 4) / 16)); //finding the second number to be displayed
          colors = 11;                       //11 is B on the array
      }
  }
  return 0;
}
/******
 *
 *    INTERRUPTS
 *
 ******/
#pragma vector=PORT1_VECTOR
__interrupt void port1interrupt (void){ //interrupt for the button
   while (!(BIT3 & P1IN)) {} // is finger off of button yet?
     if(color == 3){
       color = 1;
     }
     else{
       color = color + 1;
     }
     P1IFG &= ~BTN; // clear interrupt flag happens everytime
}
#pragma vector=TIMER0_A0_VECTOR //this is the timer for the display
__interrupt void Timer0 (void) //_A0_ISR
{
    if (temp == 0){
      P2OUT = eachSegment[colors]; //turn off additional segments if needed
      P1OUT = segs[colors] | left;// | BIT0; //turn on first digit and turn off segments
      temp = temp + 1;
    }
    else if(temp == 1){
      P1OUT &= ~left | ~segs[colors];
      P2OUT &= ~eachSegment[colors];
      P2OUT = eachSegment[secondNumber]; //shut off the segments that are not needed
      P1OUT = segs[secondNumber] | middle; //turn on second digit and turn off segments
      temp = temp + 1;
    }
    else{
      P1OUT &= ~middle | ~segs[secondNumber];
      P2OUT &= ~eachSegment[secondNumber];
      P2OUT = eachSegment[number];//shut off segments that are not needed
      P1OUT = segs[number] | right; //turn on third digit and turn off segments
      temp = 0;
    }
}
#pragma vector=TIMER1_A0_VECTOR //cant get this timer to fire (its not needed)
__interrupt void Timer1 (void) //this is for extra credit to get the buzzer working
{
    //__delay_cycles(1500);
    //P1OUT = BIT0;
    //P1OUT = BIT0;
}
// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
  __bic_SR_register_on_exit(CPUOFF);      // wake up at button press
}
