#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //名前の入力を受ける
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}