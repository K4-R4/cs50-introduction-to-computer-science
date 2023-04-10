#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;
enum {BLOCK_SIZE = 512};
//元データから一度に読み込むデータを格納
BYTE buffer[BLOCK_SIZE];

int main(int argc, char *argv[])
{
    //コマンドライン引数の数を確認
    if (argc != 2)
    {
        printf("Usage ./recover IMAGE\n");
        return 1;
    }

    //ファイルを開く
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Usage ./recover IMAGE\n");
        return 1;
    }

    char filename[8];
    int fileCount = 0;
    //元データから512Bごとに抽出
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        //jpgファイルのヘッダを判定
        //ブロックにjpgファイルのヘッダが含まれているなら新たにファイルを生成
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", fileCount);
            FILE *output = fopen(filename, "a");
            fileCount++;
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
            fclose(output);
        }
        //ブロックにjpgファイルのヘッダが含まれておらず、ファイルが1つ以上生成されているなら最新のファイルに追記
        else
        {
            if (fileCount > 0)
            {
                FILE *output = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
                fclose(output);
            }
        }
    }
    fclose(input);
}