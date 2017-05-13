#include <msp430.h>
#include <libemb/serial/serial.h>
#include <libemb/conio/conio.h>
#include <libemb/shell/shell.h>
#include <stdlib.h>

/******
 *
 *    CONSTANTS
 *
 ******/

// any constants or data structures go here

/******
 *
 *    GLOBALS
 *
 ******/
int x = 0;
int j = 64;//this is my first number
int i = 64;//this is my second number
int q = 64; //second number
int w = 64; //first number
// any variables needed by interrupts go here

/******
 *
 *    PROTOTYPES
 *
 ******/
int shell_cmd_help(shell_cmd_args *args);
int shell_cmd_argt(shell_cmd_args *args);
int shell_cmd_hexd(shell_cmd_args *args);

/******
 *
 *    SHELL COMMANDS STRUCT
 *
 ******/
shell_cmds my_shell_cmds = {
  .count = 3,
  .cmds  = {
    {
      .cmd  = "help",
      .desc = "list available commands",
      .func = shell_cmd_help
    },
    {
      .cmd  = "args",
      .desc = "print back given arguments",
      .func = shell_cmd_argt
    },
    {
      .cmd  = "hexd",
      .desc = "display two characters as hex bytes on the display",
      .func = shell_cmd_hexd
    },
  }
};

/******
 *
 *    CALLBACK HANDLERS
 *
 ******/
int shell_cmd_help(shell_cmd_args *args)
{
  int k;

  for(k = 0; k < my_shell_cmds.count; k++) {
    cio_printf("%s: %s\n\r", my_shell_cmds.cmds[k].cmd, my_shell_cmds.cmds[k].desc);
  }

  return 0;
}

int shell_cmd_argt(shell_cmd_args *args)
{
  int k;

  cio_print((char *)"args given:\n\r");

  for(k = 0; k < args->count; k++) {
    cio_printf(" - %s\n\r", args->args[k].val);
  }

  return 0;
}

int shell_cmd_hexd(shell_cmd_args *args)
{
  int x = 0;
  int u = 0;
   for(int k = 0; k < args->count; k++) {
       x = args->args[k].val[0];
       cio_printf("Your Number is %x\n", x);
       u = args->args[k].val[1];
       cio_printf("Your Number is %x\n", u);
   }
   int temp2;
   q = u % 16; //second number
   temp2 = u / 16;
   w = temp2 % 16; //first number

   int temp;
   i = x % 16;   //second number
   temp = x / 16;
   j = temp % 16; //first number

cio_printf("Number %u %i\n", j,i);

  return 0;
}

int shell_process(char *cmd_line)
{
  return shell_process_cmds(&my_shell_cmds, cmd_line);
}

/******
 *
 *    INITIALIZATION
 *
 ******/
int main(void)
{
  /* CLOCKS *********************************/
  WDTCTL   = WDTPW | WDTHOLD;               // Disable Watchdog
  BCSCTL1  = CALBC1_1MHZ;                   // Run @ 1MHz
  DCOCTL   = CALDCO_1MHZ;



  /* GPIO ***********************************/

  P1DIR = -1; //enable power to all the pins
  P1OUT = 0;// 4,5,6,7 this controls what numbers i want on
  P2DIR = -1; //enable power to all the pins
  P1OUT = BIT7+BIT6; //this turns them on to 00 so keep this
  P2SEL &=~ (BIT6 | BIT7);
  P2OUT = -1;

  /* TIMER A0 *******************************/
  TA0CTL   = TASSEL_2 | MC_1 | ID_3;
  TA0CCTL0 = CCIE;
  TA0CCR0  = 2000; //use to be 1000

  serial_init(9600);                        // Initialize Serial Comms
  __eint();                                 // Enable Global Interrupts

/******
 *
 *    PROGRAM LOOP
 *
 ******/
  for (;;) {

    int j = 0;                              // Char array counter
    char cmd_line[90] = {0};                // Init empty array

    cio_print((char *) "$ ");               // Display prompt
    char c = cio_getc();                    // Wait for a character
    while(c != '\r') {                      // until return sent then ...
      if(c == 0x08) {                       //  was it the delete key?
        if(j != 0) {                        //  cursor NOT at start?
          cmd_line[--j] = 0;                //  delete key logic
          cio_printc(0x08); cio_printc(' '); cio_printc(0x08);
        }
      } else {                              // otherwise ...
        cmd_line[j++] = c; cio_printc(c);   //  echo received char
      }
      c = cio_getc();                       // Wait for another
    }

    cio_print((char *) "\n\n\r");           // Delimit command result

    switch(shell_process(cmd_line))         // Execute specified shell command
    {                                       // and handle any errors
      case SHELL_PROCESS_ERR_CMD_UNKN:
        cio_print((char *) "ERROR, unknown command given\n\r");
        break;
      case SHELL_PROCESS_ERR_ARGS_LEN:
        cio_print((char *) "ERROR, an arguement is too lengthy\n\r");
        break;
      case SHELL_PROCESS_ERR_ARGS_MAX:
        cio_print((char *) "ERROR, too many arguements given\n\r");
        break;
      default:
        break;
    }

    cio_print((char *) "\n");               // Delimit Result
  }

  return 0;
}

/******
 *
 *    INTERRUPTS
 *
 ******/
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR (void)
{
  P1OUT = 0;
  P1OUT = BIT4;
  if(j==0){
      P2OUT = BIT6+BIT7;
  }
  else if(j==1){
      P2OUT = BIT0+BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(j==2){
      P2OUT = BIT5+BIT2+BIT7;
  }
  else if(j==3){
      P2OUT = BIT4+BIT5+BIT7;
  }
  else if(j==4){
      P2OUT = BIT0+BIT3+BIT4+BIT7;
  }
  else if(j==5){
      P2OUT = BIT1+BIT4+BIT7;
  }
  else if(j==6){
      P2OUT = BIT1+BIT7;
  }
  else if(j==7){
      P2OUT = BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(j==8){
      P2OUT = BIT7;
  }
  else if(j==9){
      P2OUT = BIT3+BIT4+BIT7;
  }
  else if(j==10){
      P2OUT = BIT3+BIT7;
  }
  else if(j==11){
      P2OUT = BIT0+BIT1+BIT7;
  }
  else if(j==12){
      P2OUT = BIT6+BIT1+BIT2+BIT7;
  }
  else if(j==13){
      P2OUT = BIT0+BIT5+BIT7;
  }
  else if(j==14){
      P2OUT = BIT1+BIT2+BIT7;
  }
  else if(j==15){
      P2OUT = BIT1+BIT2+BIT3;
  }
  __delay_cycles(3000);
  P1OUT = 0;
  P1OUT = BIT5;
  if(i==0){
      P2OUT = BIT6+BIT7;
  }
  else if(i==1){
      P2OUT = BIT0+BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(i==2){
      P2OUT = BIT5+BIT2+BIT7;
  }
  else if(i==3){
      P2OUT = BIT4+BIT5+BIT7;
  }
  else if(i==4){
      P2OUT = BIT0+BIT3+BIT4+BIT7;
  }
  else if(i==5){
      P2OUT = BIT1+BIT4+BIT7;
  }
  else if(i==6){
      P2OUT = BIT1+BIT7;
  }
  else if(i==7){
      P2OUT = BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(i==8){
      P2OUT = BIT7;
  }
  else if(i==9){
      P2OUT = BIT3+BIT4+BIT7;
  }
  else if(i==10){
      P2OUT = BIT3+BIT7;
  }
  else if(i==11){
      P2OUT = BIT0+BIT1+BIT7;
  }
  else if(i==12){
      P2OUT = BIT6+BIT1+BIT2+BIT7;
  }
  else if(i==13){
      P2OUT = BIT0+BIT5+BIT7;
  }
  else if(i==14){
      P2OUT = BIT1+BIT2+BIT7;
  }
  else if(i==15){
      P2OUT = BIT1+BIT2+BIT3;
  }
  __delay_cycles(1500);
  P1OUT = 0;
  P1OUT = BIT6;
  if(w==0){
      P2OUT = BIT6+BIT7;
  }
  else if(w==1){
      P2OUT = BIT0+BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(w==2){
      P2OUT = BIT5+BIT2+BIT7;
  }
  else if(w==3){
      P2OUT = BIT4+BIT5+BIT7;
  }
  else if(w==4){
      P2OUT = BIT0+BIT3+BIT4+BIT7;
  }
  else if(w==5){
      P2OUT = BIT1+BIT4+BIT7;
  }
  else if(w==6){
      P2OUT = BIT1+BIT7;
  }
  else if(w==7){
      P2OUT = BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(w==8){
      P2OUT = BIT7;
  }
  else if(w==9){
      P2OUT = BIT3+BIT4+BIT7;
  }
  else if(w==10){
      P2OUT = BIT3+BIT7;
  }
  else if(w==11){
      P2OUT = BIT0+BIT1+BIT7;
  }
  else if(w==12){
      P2OUT = BIT6+BIT1+BIT2+BIT7;
  }
  else if(w==13){
      P2OUT = BIT0+BIT5+BIT7;
  }
  else if(w==14){
      P2OUT = BIT1+BIT2+BIT7;
  }
  else if(w==15){
      P2OUT = BIT1+BIT2+BIT3;
  }
  __delay_cycles(1500);//use to be 500
  P1OUT = 0;
  P1OUT = BIT7;
  if(q==0){
      P2OUT = BIT6+BIT7;
  }
  else if(q==1){
      P2OUT = BIT0+BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(q==2){
      P2OUT = BIT5+BIT2+BIT7;
  }
  else if(q==3){
      P2OUT = BIT4+BIT5+BIT7;
  }
  else if(q==4){
      P2OUT = BIT0+BIT3+BIT4+BIT7;
  }
  else if(q==5){
      P2OUT = BIT1+BIT4+BIT7;
  }
  else if(q==6){
      P2OUT = BIT1+BIT7;
  }
  else if(q==7){
      P2OUT = BIT6+BIT5+BIT4+BIT3+BIT7;
  }
  else if(q==8){
      P2OUT = BIT7;
  }
  else if(q==9){
      P2OUT = BIT3+BIT4+BIT7;
  }
  else if(q==10){
      P2OUT = BIT3+BIT7;
  }
  else if(q==11){
      P2OUT = BIT0+BIT1+BIT7;
  }
  else if(q==12){
      P2OUT = BIT6+BIT1+BIT2+BIT7;
  }
  else if(q==13){
      P2OUT = BIT0+BIT5+BIT7;
  }
  else if(q==14){
      P2OUT = BIT1+BIT2+BIT7;
  }
  else if(q==15){
      P2OUT = BIT1+BIT2+BIT3;
  }
  __delay_cycles(3000);
}
