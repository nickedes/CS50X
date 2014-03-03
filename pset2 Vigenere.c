//code for Vigenere
#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc,string argv[])
{
 int i,j=0,val;
 string key,text;
 char encrpt[100];
 if(argc==1)
 { 
    printf("only one argument");
    return 1;
 }
  
  
 if(argc==2)
 {
  key=argv[1];
  text=GetString();
  for(i=0;i<strlen(text);i++)
  {
   key[j]=toupper(key[j]);
   if(isalpha(text[i]))
   {
    val=key[j]-65;
    if(islower(text[i]))
    {
     if(text[i]+val>'z')
     {
      encrpt[i]=text[i]-26+val;
     }
     else
     {
      encrpt[i]=text[i]+val;
     }
    }
    else
    {
     if(text[i]+val>'Z')
     {
      encrpt[i]=text[i]-26+val;
     }
     else
     {
      encrpt[i]=text[i]+val;
     }
    }
    if(j<strlen(key)-1)
       j++;
    else
       j=0;  
   }
   else
     encrpt[i]=text[i];
  }
 }
 else
 {
   printf("more than 2 arguments.");
   return 1;
 }    
 for(i=0;i<strlen(text);i++)
  printf("%c",encrpt[i]);
 printf("\n");
 return 0;
}
