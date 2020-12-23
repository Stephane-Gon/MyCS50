// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

//Word Counter
int wordCounter;

//File Loaded?
bool isLoaded = false;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //Create and initialize variables
    int hashValue = hash(word);
    node *cursor = table[hashValue];
    
    //Loop trough the linked list
    while (cursor != NULL)
    {
    
        //If words are equal return true
        if (strcasecmp(cursor->word ,word) == 0)
        {
            //Word is in the dictionary
            return true;
        }
        //If words are diferent go to next node
        else
        {
            cursor = cursor->next;
        }
        
    }
    //Word not in dictionary
    return false;
}

// Hashes word to a number
//I got this hash function from https://medium.com/@dentured/cs50-2020-pset-5-speller-c9d05afc490
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fpointer;

    // Opens file
    fpointer = fopen(dictionary, "r");

    //Checks if file was properly opened
    if (fpointer == NULL)
    {
        return false;
    }

    char newWord[LENGTH + 1];

    //Loop trough the file and scans line
    while (fscanf(fpointer, "%s", newWord) != EOF)
    {

        //Creates space in memory for a node
        node *newNode = malloc(sizeof(node));

        //Checks if we have space
        if (newNode == NULL)
        {
            return false;
        }
            
        //Copies word to newNode
        strcpy(newNode->word, newWord);

        //Hash word to get hash value
        int hashValue = hash(newWord);
        
        //Checks if there is already a node or note in the hashValue at the array
        if (table[hashValue] == NULL)
        {
            table[hashValue] = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = table[hashValue];
            table[hashValue] = newNode;
        }
        wordCounter++;
    }
    fclose(fpointer);
    isLoaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (isLoaded == true)
    {
        return wordCounter;   
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //Loop trough the table
    for (int i = 0; i < N; i++)
    {
        //set a node to the first node in Ith linked list
        node *cursor = table[i];
        
        //Loop trough each linked list in table
        while (cursor)
        {
            //Set a temporary node equal cursor then set cursor to next node and free the temporary node.
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        //If reached the end of linked list return true
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
