#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompt users
    string text = get_string("Text: ");

    //count L and S
    float avgLetters = count_letters(text) / (float)count_words(text) * 100;
    float avgSentences = count_sentences(text) / (float)count_words(text) * 100;

    //get index
    int index = round(0.0588 * avgLetters - 0.296 * avgSentences - 15.8);

    //print the output
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//count letters
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        //check whether each char is alpha
        if (isalpha(text[i]))
        {
            count += 1;
        }
        else
        {
            count += 0;
        }
    }
    return count;
}

//count words
int count_words(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        //check whether each char is space
        if (text[i] == ' ')
        {
            count += 1;
        }
        else
        {
            count += 0;
        }
    }
    return count += 1;
}

//count sentences
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        //check whether each char is comma, exclamtion or question mark
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count += 1;
        }
        else
        {
            count += 0;
        }
    }
    return count;
}