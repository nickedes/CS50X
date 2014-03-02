#include<cs50.h>
#include<stdio.h>
 
int main()
{
 int ht,z,i,k,j,m;
 //get valid input
 do
 {
 printf("Height:");
 ht=GetInt();
 }
 while(!(ht>=0 && ht<=23));
 m=ht;
 z=2;
 //print half pyramid
 for(i=0;i<m;i++)
 {
  ht=ht-1;
  for(k=ht;k>0;k--)
      printf(" ");
  for(j=0;j<z;j++)
      printf("#");   
  printf("\n");   
  z++;
 }
 return 0;
}
