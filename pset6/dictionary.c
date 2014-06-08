/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "dictionary.h"

// use hashtable to store the dictionary
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// define a dictionary hashtable
#define HASHSIZE 17576 // 26 * 26 * 26 = 676 * 26 = 17576, using the first 3 characters

node* hash[HASHSIZE] = {NULL}; 
    
/**
 * Calculater for the hash index
 */
int index_helper(char* word)
{
    int first, second, third;
    
    first = (int)tolower(word[0]) - 97;
    
    if (word[1] == '\0')
    {
        second = 0;
        third = 0;    
    }
    else if (word[1] != '\0' && word[2] == '\0')
    {
        second = (int)tolower(word[1]) - 97;
        third = 0;    
    }
    else
    {
        second = (int)tolower(word[1]) - 97;
        third = (int)tolower(word[2]) - 97;
    }
    
    // int index = first; (HASHSIZE 26, use first character only)
    // int index = first * 26 + second; (HASHSIZE 26 * 26, use first two characters)
    int index = first * 26 * 26 + second * 26 + third; // (HASHSIZE 26 * 26 * 26, use first three characters)
    
    return index;
}

    
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // copy the uppercased argument for comparison
    char copy[LENGTH + 1];
    int n = strlen(word);
    
    for(int i = 0; i < n; i++)
        copy[i] = tolower(word[i]);
    
    copy[n] = '\0';
    
    // find the correct hash index for word loop
    int index = index_helper(copy);
    
    if (hash[index] == NULL)
        return false;
    else
    {
        node* tmp = hash[index];
    
        while (tmp->next != NULL)
        {
            if (strcmp(copy, tmp->word) == 0)
                return true;
            tmp = tmp->next;
        }
        
        if (strcmp(copy, tmp->word) == 0)
            return true;
        else
            return false;
    }
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{ 
    // open dictionary to the RAM
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    // load words from dictionary
    char buffer[LENGTH + 2];
    
    while (fgets(buffer, LENGTH + 2, file))
    {
        // overwrite the \n with \0
        buffer[strlen(buffer) - 1] = '\0';
        
        // lowercase for word
        for (int i = 0, n = strlen(buffer); i < n; i++)
            buffer[i] = tolower(buffer[i]);

        // copy word into temp node
        node* temp = malloc(sizeof(node));
        strncpy(temp->word, buffer, LENGTH + 1);
        temp->next = NULL;
        
        // update the node into the correct place
        int index = index_helper(buffer);
        
        if (hash[index] == NULL)
        {
            hash[index] = temp;
        }
        else
        {
            // loop through the linked list and insert it into the table
            node* tmp = hash[index];
            while(tmp->next != NULL)
                tmp = tmp->next;
            // assign the node to the last of the linked list
            tmp->next = temp;
        }
    }

    // close the file
    fclose(file);
    
    /* print out the dictionary (for small dictionary check)
    for (int i = 0; i < HASHSIZE; i++)
    {
        if (hash[i] != NULL)
        {
            node* tmp = hash[i];
            while (tmp->next != NULL)
            {
                printf("%s\n", tmp->word);
                tmp = tmp->next;
            }
            printf("%s\n", tmp->word);
        }
    }
    */
    
    // success!
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // initialize dictionary's size
    unsigned int size = 0;
    
    for (int i = 0; i < HASHSIZE; i++)
    {
        if (hash[i] != NULL)
        {
            size++;
            for(node* tmp = hash[i]; tmp->next != NULL; tmp = tmp->next)
                size++;
        }
    }
    return size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // loop through the hash and free each linked list
    for (int i = 0; i < HASHSIZE; i++)
    {
        node* first = hash[i];
        while (first != NULL)
        {
            node* next = first->next;
            free(first);
            first = next;
        }
    }
    
    return true;
}
