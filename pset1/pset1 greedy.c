#include<cs50.h>
#include<stdio.h>
#include<math.h>
int main()
{
  float change;
  int chng,coin=0;
  //get valid input
  do
  {
     printf("change:");
     change=GetFloat();
  }
  while(change <= 0);
    
  //rounding off the no. of cents using round from math library
  chng = round(change*100);
   
  //to calculate no. of coins
  if(chng >= 25)
  {
    coin=chng/25;
    chng=chng%25;
  }
     
  if(chng >= 10)
  {
    coin+=chng/10;
    chng=chng%10;
  }
   
  if(chng >= 5)
  {
    coin+=chng/5;
    chng=chng%5;
  }
  if(chng<5)
  {
    coin += chng;
  }
  //display output
  //printf("input of %g yields output of %d",change,coin);
  printf("%d\n",coin);
  return 0;
}
