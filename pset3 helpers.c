/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 * soon
 */
        
#include <cs50.h>
 
#include "helpers.h"
 
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
// linear search
    int beg=0,mid,end=n;
    if(n<0)
        return false;
    while(end>=beg)
    {
        mid=(beg+end)/2;
        if(values[mid]==value)
            return true;
        else if(values[mid]>value)
            end=mid-1;
        else
            beg=mid+1;   
             
    }
    return false;
}
 
 
/**
 
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // sorting using bubble sort
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {  
            if(values[j]>values[j+1])
            {
                temp=values[j];
                values[j]=values[j+1];
                values[j+1]=temp;
            }
        }
    }
return;

}   
