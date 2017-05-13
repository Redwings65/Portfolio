/*
Program By: Brandon Seager
DivAlg A1
*/


#include <stdio.h>
#include <stdlib.h>

char Buffer[90];//random buffer value holder
int i = 0;
int digit;
  void divAlg(unsigned int V, unsigned int B){//this is where everhting goes
    Buffer[64] = 00;
    char Table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};//csvadsffdasfd};
    while(V != 0){
      digit = V % B;
      V = V / B;
      Buffer[i] = digit; //this is what calls store
      if((V == 0) && (B != 16)){
        printf("%d%d%d%d%d%d\n",Buffer[5],Buffer[4],Buffer[3],Buffer[2],Buffer[1],Buffer[0]);
      }
      if((B == 16) && (V == 0)){
        printf("%d%c\n",Buffer[1],Table[Buffer[0]]);
      }
    i++;
    }
}
  
