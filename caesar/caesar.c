#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string input);
char rotate(char plain, int key);

const int ALPHABETS = 26;

int main(int argc, string argv[])
{
    //cause an error when too many arg or non-digit contained in CLA
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //define KEY
    const int KEY = atoi(argv[1]);
    //prompt users to type plain text
    string plain = get_string("plaintext: ");

    //print ciphertext
    printf("ciphertext: ");
    //process each char with rotate function
    for (int i = 0, len = strlen(plain); i < len; i++)
    {
        printf("%c", rotate(plain[i], KEY));
    }
    printf("\n");
    return 0;
}

//check whether all inputs are digits
bool only_digits(string input)
{
    bool onlyDigits;
    for (int i = 0, len = strlen(input); i < len; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            onlyDigits = true;
        }
        else
        {
            onlyDigits = false;
            break;
        }
    }
    return onlyDigits;
}

//rotate each char
char rotate(char plain, int key)
{
    char cipher;
    if (isupper(plain))
    {
        cipher = (char)(((plain - 'A') + key) % ALPHABETS + 'A');
    }
    else if (islower(plain))
    {
        cipher = (char)(((plain - 'a') + key) % ALPHABETS + 'a');
    }
    else
    {
        cipher = plain;
    }
    return cipher;
}