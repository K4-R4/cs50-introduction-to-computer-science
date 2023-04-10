#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //高さを受け取る
        height = get_int("height: ");

    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - (i + 1); j++)
        {
            //空白を入力
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            //#を入力
            printf("#");
        }
        printf("\n");
    }
}