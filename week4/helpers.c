#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Loop trough the rows
    {
        for (int j = 0; j < width; j++) //Loop trough the pixels
        {
            
            int avg = round(((float) image[i][j].rgbtRed + (float) image[i][j].rgbtBlue + (float) image[i][j].rgbtGreen) /
                            3); //Calculates Avarege
            
            // Setting the color to the new value.
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Loop trough the rows
    {
        for (int j = 0; j < width; j++) //Loop trough the pixels
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            // Calculates with Sepia Algorithm.
            
            int newRed = round(.393 * red + .769 * green + .189 * blue);
            int newGreen = round(.349 * red + .686 * green + .168 * blue);
            int newBlue = round(.272 * red + .534 * green + .131 * blue);
            
            // Checks if value is over 255 if  so, sets it to 255 if not sets it to the result of the calculus.
            if (newRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = newRed;
            }
            
            if (newGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = newGreen;
            }
            
            if (newBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = newBlue;
            }
        }
    }
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    for (int i = 0; i < height; i++) //Loop trough rows
    {
        for (int j = 0; j < (width / 2); j++) //Loop trough the pixels only until the middle
        {
            RGBTRIPLE temp = image[i][j]; //Temporary array to store a value.
    
            //Swaping the pixel we are in with his mirror pixel.
            
            image[i][j] = image[i][width - (j + 1)]; 
            image[i][width - (j + 1)] = temp;
            
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    //Loop the image to create a copy.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    
    //Loop trough the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Create variables and initialize them.
            float avgRed = 0;
            float avgGreen = 0;
            float avgBlue = 0;
            
            //Checking the Corners first
            //Corner on Top Left
            if (i == 0 && j == 0) 
            {
                //Calculating the avarage
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 4);
                
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen  + copy[i + 1][j].rgbtGreen  + 
                                         copy[i + 1][j + 1].rgbtGreen) / 4);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue  + copy[i + 1][j].rgbtBlue  + 
                                        copy[i + 1][j + 1].rgbtBlue) / 4);
                
                //Setting the colors of the img pixel to the new average.
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
            }
            
            //Corner on Top Right
            else if (i == 0 && j == (width - 1))
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed) /  4);
                
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + 
                                         copy[i + 1][j - 1].rgbtGreen) / 4);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + 
                                        copy[i + 1][j - 1].rgbtBlue) / 4);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;            
            }
            
            //Corner on Bottom Left
            
            else if (i == (height - 1) && j == 0)
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 4);
                
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen + 
                                         copy[i - 1][j + 1].rgbtGreen) / 4);
                                 
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue + 
                                        copy[i - 1][j + 1].rgbtBlue) / 4);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
            }
            
            //Corner on Bottom Right
            
            else if (i == (height - 1) && j == (width - 1))
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed) / 4);
                
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + 
                                         copy[i - 1][j - 1].rgbtGreen) / 4);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + 
                                        copy[i - 1][j - 1].rgbtBlue) / 4);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
            }
            
            //Checking the Edges Pixels
            //Top Edge Pixels
            
            else if (i == 0 && (j > 0 && j < (width - 1)))
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + 
                                       copy[i + 1][j - 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6);
                                       
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + 
                                         copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + 
                                        copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
            }
            //Bottom Edge Pixels
            else if (i == (height - 1) && (j > 0 && j < (width - 1)))
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + 
                                       copy[i - 1][j - 1].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6);
                                       
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + 
                                         copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 6);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + 
                                        copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 6);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
                
            }
            //Left Edge Pixels
            else if (j == 0 && (i > 0 && i < (height - 1)))
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed + 
                                       copy[i - 1][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6);
                                       
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i + 1][j].rgbtGreen + 
                                         copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i + 1][j].rgbtBlue + 
                                        copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
            }
            //Right Edge Pixels
            else if (j == (width - 1) && (i > 0 && i < (height - 1)))
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j - 1].rgbtRed + 
                                       copy[i - 1][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 6);
                                       
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i + 1][j].rgbtGreen + 
                                         copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 6);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i + 1][j].rgbtBlue + 
                                        copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 6);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
            }
            
            //Middle Pixels
            else
            {
                avgRed = round((float)(copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + 
                                       copy[i - 1][j - 1].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + 
                                       copy[i + 1][j - 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 9);
                                       
                avgGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + 
                                         copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + 
                                         copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 9);
                                         
                avgBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + 
                                        copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + 
                                        copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 9);
                
                image[i][j].rgbtRed = avgRed;
                image[i][j].rgbtGreen = avgGreen;
                image[i][j].rgbtBlue = avgBlue;
            }
        }
    }
    
    
    return;
}
