#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
int main(int argc, string argv[])
{
int k,i;
 char c[100];
 string a;
 //taking string to be encrypted
 a=GetString();
 //checking for possible cases
 if(argc==2)
 {
 if(atoi(argv[1])!=0)
  {
    k=atoi(argv[1]);
    for(i=0;i<strlen(a);i++)
    {
     //encrypting inside the if block
     if(isalpha(a[i]))
      {
       if(k<26)
        {
         if(a[i]+k<='z' ||a[i]+k<='Z')
            c[i]=a[i]+k;
         else
            c[i]=(a[i]-24)+(k-2);
        }
       else
       {
        k=k%26;   
        if(a[i]+k<='z'||a[i]+k<='Z')
           c[i]=a[i]+k;
        else
           c[i]=(a[i]-24)+k-2;
       }
      }
   else
      c[i]=a[i];
    }
   }
  else
   return 1;
  }
 //when only one argument
 if(argc==1)
   {
    printf("\nOnly one argument");
    return 1;
   }
 //when more than one argument 
 if(argc>2)
    return 1; 
 for(i=0;i<strlen(a);i++)
    printf("%c",c[i]);
 printf("\n");
 return 0;

}
