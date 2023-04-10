#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //クレカ番号の保存
    long num;
    //クレカ番号の桁数
    int digit = 0;

    num = get_long("Number: ");
    long numCheck = num;
    while (numCheck != 0)
    {
        numCheck /= 10;
        digit ++;
    }
    if (digit < 13 || digit > 16)
    {
        printf("EOF\n");
    }

    int sumA = 0;
    //2番めの数字から1桁ごと計算
    //番号の複製
    long dupeNum1 = num;
    for (int i = 0; i < digit / 2 + 1; i++)
    {
        dupeNum1 /= 10;
        int tempNum = (dupeNum1 % 10) * 2;
        if (tempNum > 9)
        {
            sumA += (tempNum / 10) + (tempNum % 10);
        }
        else
        {
            sumA += tempNum;
        }
        dupeNum1 /= 10;
    }

    int sumB = 0;
    //最後の数字から1桁ごとに計算
    //番号の複製
    long dupeNum2 = num;
    for (int j = 0; j < digit / 2 + 1; j++)
    {
        sumB += dupeNum2 % 10;
        dupeNum2 /= 100;
    }

    int sum = sumA + sumB;

    //番号の真偽判定
    if (sum % 10 == 0)
    {
        int headNum;
        //カード会社の特定
        //桁数15
        if (digit == 15)
        {
            headNum = num / 10000000000000;
            if (headNum == 34 || headNum == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //桁数13
        else if (digit == 13)
        {
            headNum = num / 1000000000000;
            if (headNum == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //桁数16
        else if (digit == 16)
        {
            headNum = num / 100000000000000;
            if (headNum == 51 || headNum == 52 || headNum == 53 || headNum == 54 || headNum == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (headNum / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}