#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //高さを受け取る
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

//行
    for (int i = 0; i < height; i++)
    {
        //列
        for (int j = 0; j < height - (i + 1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        //谷
        printf("  ");
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}