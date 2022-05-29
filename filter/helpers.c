#include "helpers.h"
#include <math.h>

int min(int n);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;


    // loop over pixels and update the pixels by filtering
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);

            image[i][j].rgbtBlue  = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed   = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = min(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            image[i][j].rgbtGreen = min(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            image[i][j].rgbtBlue = min(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmp[i][j] = image[i][width -1 - j];
            image[i][width -1 - j] = image[i][j];
            image[i][j] = tmp[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Store the original image in a new 2D array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }


    // Filter all the  pixels

    int totalRed = 0;
    int totalGreen = 0;
    int totalBlue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            totalRed = 0;
            totalGreen = 0;
            totalBlue = 0;

            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k < 0 || k > height - 1 || l < 0 || l > width - 1)
                    {
                        continue;
                    }

                    totalRed += copy[k][l].rgbtRed;
                    totalGreen += copy[k][l].rgbtGreen;
                    totalBlue += copy[k][l].rgbtBlue;
                }
            }

            image[i][j].rgbtRed = round(totalRed / 9.0);
            image[i][j].rgbtGreen = round(totalGreen / 9.0);
            image[i][j].rgbtBlue = round(totalBlue / 9.0);
        }

    }


    return;
}


int min(int n)
{
    if (n < 255)
    {
        return n;
    }

    return 255;
}