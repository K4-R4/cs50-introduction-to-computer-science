#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //それぞれのピクセルについてRGBの平均を計算してRGBを上書き
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE grayScale = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = grayScale;
            image[i][j].rgbtGreen = grayScale;
            image[i][j].rgbtRed = grayScale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //imageのコピーを生成し、セピアに変換する計算の際、すでに変換したピクセルの影響を受けないようにする
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //RGB値が255を超える場合は255で上書き
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Red
            if (round(.393 * copy[i][j].rgbtRed + .769 * copy[i][j].rgbtGreen + .189 * copy[i][j].rgbtBlue) < 256)
            {
                image[i][j].rgbtRed = round(.393 * copy[i][j].rgbtRed + .769 * copy[i][j].rgbtGreen + .189 * copy[i][j].rgbtBlue);
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
            //Green
            if (round(.349 * copy[i][j].rgbtRed + .686 * copy[i][j].rgbtGreen + .168 * copy[i][j].rgbtBlue) < 256)
            {
                image[i][j].rgbtGreen = round(.349 * copy[i][j].rgbtRed + .686 * copy[i][j].rgbtGreen + .168 * copy[i][j].rgbtBlue);
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            //Blue
            if (round(.272 * copy[i][j].rgbtRed + .534 * copy[i][j].rgbtGreen + .131 * copy[i][j].rgbtBlue) < 256)
            {
                image[i][j].rgbtBlue = round(.272 * copy[i][j].rgbtRed + .534 * copy[i][j].rgbtGreen + .131 * copy[i][j].rgbtBlue);
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //左右のピクセルをindexを参照して入れ替える
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //blurをかける計算の際に、すでに変換したピクセルの影響を受けないようにコピーを生成してそれを参照する
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    //対象のピクセルを含む周囲9マスについてそこのindexが有効な場合は計算に含む
    //9マスについて有効な場合はRGBを一時的に変数に格納、さらに計算に含んだピクセルの数もカウント
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel = 0;
            float tmpSumR = 0;
            float tmpSumG = 0;
            float tmpSumB = 0;
            //上一列
            if ((0 <= i - 1 && i - 1 <= height - 1) && (0 <= j - 1 && j - 1 <= width - 1))
            {
                tmpSumR += copy[i - 1][j - 1].rgbtRed;
                tmpSumG += copy[i - 1][j - 1].rgbtGreen;
                tmpSumB += copy[i - 1][j - 1].rgbtBlue;
                pixel += 1;
            }
            if ((0 <= i - 1 && i - 1 <= height - 1) && (0 <= j && j <= width - 1))
            {
                tmpSumR += copy[i - 1][j].rgbtRed;
                tmpSumG += copy[i - 1][j].rgbtGreen;
                tmpSumB += copy[i - 1][j].rgbtBlue;
                pixel += 1;
            }
            if ((0 <= i - 1 && i - 1 <= height - 1) && (0 <= j + 1 && j + 1 <= width - 1))
            {
                tmpSumR += copy[i - 1][j + 1].rgbtRed;
                tmpSumG += copy[i - 1][j + 1].rgbtGreen;
                tmpSumB += copy[i - 1][j + 1].rgbtBlue;
                pixel += 1;
            }
            //中一列
            if ((0 <= i && i <= height - 1) && (0 <= j - 1 && j - 1 <= width - 1))
            {
                tmpSumR += copy[i][j - 1].rgbtRed;
                tmpSumG += copy[i][j - 1].rgbtGreen;
                tmpSumB += copy[i][j - 1].rgbtBlue;
                pixel += 1;
            }
            if ((0 <= i && i <= height - 1) && (0 <= j && j <= width - 1))
            {
                tmpSumR += copy[i][j].rgbtRed;
                tmpSumG += copy[i][j].rgbtGreen;
                tmpSumB += copy[i][j].rgbtBlue;
                pixel += 1;
            }
            if ((0 <= i && i <= height - 1) && (0 <= j + 1 && j + 1 <= width - 1))
            {
                tmpSumR += copy[i][j + 1].rgbtRed;
                tmpSumG += copy[i][j + 1].rgbtGreen;
                tmpSumB += copy[i][j + 1].rgbtBlue;
                pixel += 1;
            }
            //下一列
            if ((0 <= i + 1 && i + 1 <= height - 1) && (0 <= j - 1 && j - 1 <= width - 1))
            {
                tmpSumR += copy[i + 1][j - 1].rgbtRed;
                tmpSumG += copy[i + 1][j - 1].rgbtGreen;
                tmpSumB += copy[i + 1][j - 1].rgbtBlue;
                pixel += 1;
            }
            if ((0 <= i + 1 && i + 1 <= height - 1) && (0 <= j && j <= width - 1))
            {
                tmpSumR += copy[i + 1][j].rgbtRed;
                tmpSumG += copy[i + 1][j].rgbtGreen;
                tmpSumB += copy[i + 1][j].rgbtBlue;
                pixel += 1;
            }
            if ((0 <= i + 1 && i + 1 <= height - 1) && (0 <= j + 1 && j + 1 <= width - 1))
            {
                tmpSumR += copy[i + 1][j + 1].rgbtRed;
                tmpSumG += copy[i + 1][j + 1].rgbtGreen;
                tmpSumB += copy[i + 1][j + 1].rgbtBlue;
                pixel += 1;
            }
            //RGBについて、有効なindexを持つマスの値の和を、計算したピクセルの数で割ることで平均を求める
            image[i][j].rgbtRed = round(tmpSumR / pixel);
            image[i][j].rgbtGreen = round(tmpSumG / pixel);
            image[i][j].rgbtBlue = round(tmpSumB / pixel);
        }
    }
    return;
}