#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
BYTE min(BYTE min,BYTE value);
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int h = 0,k = height; h < k;h++)
    {
        for(int w = 0,i = width; w < i; w++)
        {
            float sum =  (float)image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen;
            BYTE average = (BYTE)round((sum/3));
            image[h][w].rgbtRed = average;
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int h = 0, k = height; h < k; h++)
    {
        for (int w = 0, i = width/2; w < i; w++)
        {
            RGBTRIPLE temp = *&image[h][ w];
            *&image[h][w] = *&image[h][width - w -1];
            *&image[h][width - w -1] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    float averager,averageb,averageg;
    float r = 0,b= 0,g= 0;
    int counter = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int h = 0, k = height; h < k; h++)
    {
        for (int w = 0, i = width; w < i; w++)
        {
            r =0;
            b =0;
            g =0;
            counter =0;
            for (int dh = h-1 ; dh <= h+1; dh++)
            {
                for (int dw = w-1 ; dw <= w+1; dw++)
                {
                    if(dh >= 0 && dh < height && dw >= 0 && dw < width)
                    {
                        r += (float)temp[ dh][dw].rgbtRed;
                        g += (float)temp[dh][dw].rgbtGreen;
                        b += (float)temp[dh][ dw].rgbtBlue;

                        counter++;

                    }
                }
            }
            averager = (BYTE)round(r/counter);
            averageb = (BYTE)round(b/counter);
            averageg = (BYTE)round(g/counter);

            image[h][w].rgbtRed = averager;
            image[h][w].rgbtBlue= averageb;
            image[h][w].rgbtGreen = averageg;





        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int gy[3][3]= {{-1,-2,-1},{0,0,0},{1,2,1}};

    float srx,sry,sgx,sgy,sbx,sby;

    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            temp[h][w] = image[h][w];
        }
    }



    float srr;
    float srg;
    float srb;

    for(int h = 0; h < height; h++)
    {

        for(int w= 0 ; w< width; w++)
        {
            srx = 0;
            sry = 0;
            sgx = 0;
            sgy = 0;
            sbx =0;
            sby = 0;
            for(int dh = h -1; dh <= h+ 1;dh++)
            {
                for(int dw = w - 1; dw <= w+1; dw++)
                {

                             if(dh >= 0 && dh < height && dw >= 0 && dw < width)
                             {
                                srx += (float)temp[dh][dw].rgbtRed * gx[dh - (h - 1)][ dw - (w - 1)];
                                sry += (float)temp[dh][dw].rgbtRed * gy[dh - (h - 1)][ dw - (w - 1)];
                                sgx += (float)temp[dh][dw].rgbtGreen*gx[dh - (h - 1)][ dw - (w - 1)];
                                sgy += (float)temp[dh][dw].rgbtGreen*gy[dh - (h - 1)][ dw - (w - 1)];
                                sbx += (float)temp[dh][dw].rgbtBlue *gx[dh - (h - 1)][ dw - (w - 1)];
                                sby += (float)temp[dh][dw].rgbtBlue *gy[dh - (h - 1)][ dw - (w - 1)];

                             }





                }

                      srr = sqrt(srx * srx + sry * sry);
                      srg = sqrt(sgx * sgx + sgy * sgy);
                      srb = sqrt(sbx * sbx + sby * sby);
                      image[h][w].rgbtRed = (BYTE)round((srr > 255)? 255 : srr);
                      image[h][w].rgbtGreen = (BYTE)round((srg>255) ? 255 : srg);
                      image[h][w].rgbtBlue = (BYTE)round((srb >255) ? 255 : srb);

            }




        }
    }


    return;
}

