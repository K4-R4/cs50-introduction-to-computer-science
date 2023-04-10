#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned int hash(const string);
bool is_alphabet_only(const string);

int main(int argc, string argv[])
{
    // コマンドライン引数の検証
    if (argc != 2 || !is_alphabet_only(argv[1]))
    {
        printf("Usage: ./problem5 word\n");

        return 1;
    }

    // ハッシュかした値を出力する
    printf("%i\n", hash(argv[1]));

    return 0;
}

bool is_alphabet_only(const string word)
{
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(word[i]))
        {
            return false;
        }
    }

    return true;
}

// ハッシュ関数
// TODO：オリジナルのハッシュ関数をさせよう。
//       返却値は必ず0または正の整数である。
//       引数wordは、すべてアルファベットのみで構成される文字列である。
//       ハッシュ値になるべく偏りのないように実装してください。
//       難易度1：26パターン(0-25を返す)
//       難易度2：52パターン(0-51を返す)
//       難易度3：256パターン(0-255を返す)
unsigned int hash(const string word)
{
    /*1
    if (isupper(word[0]))
    {
        return word[0] - 'A';
    }
    else
    {
        return word[0] - 'a';
    }
    */
   /*2
    unsigned int tmp = 0;
    if (strlen(word) > 1)
    {
        for (int i = 0; i < 2; i++)
        {
            if (isupper(word[i]))
            {
                tmp += word[i] - 'A';
            }
            else
            {
                tmp += word[i] - 'a';
            }
        }
    }
    else
    {
            if (isupper(word[0]))
            {
                tmp += (word[0] - 'A') * 2;
            }
            else
            {
                tmp += (word[0] - 'a') * 2;
            }
    }
    return tmp;
    */
    unsigned int tmp = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (i % 2 == 0)
        {
            if (isupper(word[i]))
            {
                tmp += (word[i] - 'A') * 2;
            }
            else
            {
                tmp += (word[i] - 'a') * 2;
            }
        }
        else
        {
            if (isupper(word[i]))
            {
                tmp += (word[i] - 'A') * 2 + 1;
            }
            else
            {
                tmp += (word[i] - 'a') * 2 + 1;
            }
        }
        if (tmp + 26 > 255)
        {
            break;
        }
    }
    return tmp;
}



