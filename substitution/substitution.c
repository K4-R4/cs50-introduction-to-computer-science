#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char convert_chars(char letter, string key);

int main(int argc, string argv[])
{
    //check arg counts
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //check whether key contains 26 chars
    else if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //check whether each char is alpha
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        //check dupe char
        for (int j = 0; j < len; j++)
        {
            //skip comparing same char
            if (i == j)
            {
                continue;
            }
            //compare each char with the others
            else if (argv[1][i] == argv[1][j])
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }
    }

    string key = argv[1];
    //get plaintext
    string plaintext = get_string("plaintext: ");
    //print ciphertext
    printf("ciphertext: ");
    //encipher plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", convert_chars(plaintext[i], key));
    }
    printf("\n");
}

char convert_chars(char letter, string key)
{
    if (isupper(letter))
    {
        return toupper(key[letter - 'A']);
    }
    else if (islower(letter))
    {
        return tolower(key[letter - 'a']);
    }
    else
    {
        return letter;
    }
}