#include <msp430.h>
#include <stdlib.h>
#include <string.h>
#include <libemb/serial/serial.h>
#include <libemb/conio/conio.h>
#include <libemb/shell/shell.h>
#include <stdio.h>
#include "shell.h"//for the header file


struct _box_t* item[5];//created temp items for the button swap
//int k = 0;//created this
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

  cio_print("args given:\n\r");

  for(k = 0; k < args->count; k++) {
    cio_printf(" - %s\n\r", args->args[k].val);
  }

  return 0;
}

int shell_cmd_push(shell_cmd_args *args)
{
  int x = 0;//temp value holders
  int u = 0;//temp value holders

  stack[stack_top] = (box_t*)malloc(sizeof(box_t));//malloc the size of the box_t.
  char *arguments = args->args[0].val;
  x = atoi(args->args[1].val);
  u = atoi(args->args[2].val);
  int l = strlen(args->args[0].val);
  (*stack[stack_top]).name = malloc(l+1);//malloc the size of args
  strncpy((*stack[stack_top]).name, arguments, l+1);
  (*stack[stack_top]).quantity = x;
  (*stack[stack_top]).price = u;

  //cio_printf("there is %s",stack[stack_top]->name);

  if (stack_top <= 4){
  stack_top++;
  cio_printf("Successfully pushed 1 item to the top of the Stack.\n\r");
  }
  if(stack_top >= 5){
    P1OUT = BIT0 | BIT3;
    cio_printf("Did not push because the Stack is full.\n\r");
  }
  else if (stack_top == 0){
    P1OUT = 0 | BIT3;
  }
  else{
    P1OUT = BIT6 | BIT3;
  }
  return 0;
  }

int shell_cmd_pop(shell_cmd_args *args)//takes the item off the stack and shows it.
{
  if(stack_top == 0){
    cio_printf("The Stack is empty and there is nothing to pop. Breaking out of the POP function.");
  }else{
    stack_top = stack_top - 1;
    cio_printf( "The most recent item in the stack is named : %s\n\r",stack[stack_top]->name);
    stack[stack_top] = NULL; //pulls most recent item from the stack.
    free(stack[stack_top]->name);
    free(stack[stack_top]);
    cio_printf("The item was just popped off the stack, the top space is now NULL");
  if(stack_top >= 5){
    P1OUT = BIT0 | BIT3;
    cio_printf("Stack is full.\n\r");
  }
  else if (stack_top == 0){
    P1OUT = 0 | BIT3;
    cio_printf("The Stack is now empty.\n\r");
  }
  else{
    P1OUT = BIT6 | BIT3;
  }
  //cio_printf("%u",stack_top);
  }//this goes to the else statement
  return 0;
}

int shell_cmd_sell(shell_cmd_args *args)//sells the item for the given price
{
  if(stack_top == 0){
    cio_printf("The Stack is empty and there is nothing to Sell. Breaking out of the Sell function.\n\r");
  }
  else{
    stack_top = stack_top - 1;
    cost(stack[stack_top]);
    stack[stack_top] = NULL; //pulls most recent item from the stack.
    free(stack[stack_top]->name);
    free(stack[stack_top]);
    cio_printf("The item was just Sold off the top of the stack, the top space is now NULL.\n\r");
  if(stack_top >= 5){
    P1OUT = BIT0 | BIT3;
    cio_printf("Stack is full.\n\r");
  }
  else if (stack_top == 0){
    P1OUT = 0 | BIT3;
    cio_printf("The Stack is now empty.\n\r");
  }
  else{
    P1OUT = BIT6 | BIT3;
  }
  //cio_printf("%u",stack_top);
  }//this goes to the else statement
  return 0;
}

int shell_cmd_show(shell_cmd_args *args)//This one is done.
{
  for(int i = 0;i < sizeof(stack)-1;i++){
    if(i == 0){
      cio_printf("The bottom item in the stack is %s\n\r",stack[i]->name);
    }else{
    cio_printf( "The %u item in the stack is named : %s\n\r",i,stack[i]->name);
    }
    if(stack[i+1] == NULL){ //might need to be i +1
      break;
    }
  }
  return 0;
}

int shell_process(char *cmd_line)
{
  return shell_process_cmds(&my_shell_cmds, cmd_line);
}

/******
 *
 *    FUNCTIONS
 *
 ******/

int cost(box_t* box) {//this funciton is done
    cio_printf( "The most recent item in the stack is named : %s\n\r",stack[stack_top]->name);
    int temp = ((box)->price * (box)->quantity);
    cio_printf("The item on the top of the stack was just sold for %u \n\r",temp);
    return 0;
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
  P1DIR = ~BIT3 | BIT0 | BIT6;
  P1OUT = BIT3;

  P1REN = BIT3;
  P1IE  = BIT3;
  P1IES = BIT3;
  P1IFG = 0;

  P2DIR = -1;
  P2OUT = 0;

  serial_init(9600);                        // Initialize Serial Comms
  __eint();                                 // Enable Global Interrupts

/******
 *
 *    PROGRAM LOOP
 *
 ******/
  for (;;) {

    int j = 0;                              // Char array counter
    memset(cmd_line, 0, 90);                // Init empty array

    cio_print("$ ");               // Display prompt
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

    cio_print("\n\n\r");           // Delimit command result

    switch(shell_process(cmd_line))         // Execute specified shell command
    {                                       // and handle any errors
      case SHELL_PROCESS_ERR_CMD_UNKN:
        cio_print("ERROR, unknown command given\n\r");
        break;
      case SHELL_PROCESS_ERR_ARGS_LEN:
        cio_print("ERROR, an arguement is too lengthy\n\r");
        break;
      case SHELL_PROCESS_ERR_ARGS_MAX:
        cio_print("ERROR, too many arguements given\n\r");
        break;
      default:
        break;
    }
    cio_print("\n");               // Delimit Result
  }
  return 0;
}

/******
 *
 *    INTERRUPTS
 *
 ******/
#pragma vector=PORT1_VECTOR
__interrupt void Port1_ISR (void)
{
  // swap the top two boxes on the stack when the button is pressed

  while (!(BIT3 & P1IN)) {} // is finger off of button yet?
  __delay_cycles(32000); // wait 32ms
  P1IFG &= ~BIT3; // clear interrupt flag

  //swappy mcswap swap

  stack_top = stack_top-1;

  cio_printf("%u",stack_top);
  item[0] = stack[stack_top-1];//below item
  item[1] = stack[stack_top];//top item
  stack[stack_top-1] = item[1];
  stack[stack_top] = item[0];

  cio_printf("Just swapped the top item which was %s with the one below it which was %s\n\r",stack[stack_top-1]->name,stack[stack_top]->name);
  stack_top = stack_top + 1;
}
