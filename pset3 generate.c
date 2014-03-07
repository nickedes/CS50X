/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
        
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define LIMIT 65536
 
int main(int argc, string argv[])
{
    //no. of command line arguments are neither 2 nor 3
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }
 
    // converts string to integer
    int n = atoi(argv[1]);
 
    //no. of command line arguments is 3
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }
 
    //print psedorandom no.s
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }
 
    // that's all folks
    return 0;
}
