// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1024;
int words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    for (node *cursor = table[hash(word)]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int n = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        n += toupper(word[i]) - 'A';
    }
    return n % 1024;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char tmpw[LENGTH + 1];

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    while (fscanf(file, "%s", tmpw) != EOF)
    {
        node *n = malloc(sizeof(node));
        n->next = NULL;
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, tmpw);
        n->next = table[hash(tmpw)];
        table[hash(tmpw)] = n;
        words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i ++)
    {
        for (node *cursor = table[i]; cursor != NULL;)
        {
            node *tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
    return true;
}