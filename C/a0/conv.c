/*
Assignment #1 2230
Brandon Seager
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, const char **argv){
  int V =atoi(argv[1]);
  int B =atoi(argv[2]);
  int C =((log(B))/(log(2)));
  char *ascii = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
  int i = 0;
  int digit;
  char array[1000000];
  while(V != 0){
    digit = V % B;
    array[i] = digit;
    V = V/B;
    i++;
  }
  char Buffer[i];
  V = atoi(argv[1]);
  for(int k = 0;k < i;k++){
    Buffer[k]= (V >> C*k) & (B-1);
  }


  //where i print stuff off

    if(B==2||B==4||B==8||B==16||B==64){
    for(int l = i-1;l >= 0;l--){
      printf("%c",ascii[Buffer[l]]);
    }
  }
  else{
    //for(int r = i-1;r >= 0;r--){
      //printf("%c",array[r]);
    //}
    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",array[30],array[29],array[28],array[27],array[26],array[25],array[24],array[23],array[22],array[21],array[20],array[19],array[18],array[17],array[16],array[15],array[14],
    array[13],array[12],array[11],array[10],array[9],array[8],array[7],array[6],
    array[5],array[4], array[3],array[2],array[1],array[0]);
}

    printf("\n");
}
