#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Creating a 512 byte block
#define BLOCK 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Counter to count the jpg's
    int counter = 0;
    
    //Buffer to store 512 byte blocks of information from inputFile
    BYTE buffer[BLOCK];
    
    //String that stores ***.jpg\0
    char images[8];
    
    //Output File
    FILE *img = NULL;
    
    //Checks if we already found a jpg
    int foundJpg = 0; //False
    
    //If user didn't type exactly program name and 1 argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    //Opening the file
    char *inputFile = argv[1];
    FILE *fpointer = fopen(inputFile, "r");
    
    //If file is NULL return 1
    if (fpointer == NULL)
    {
        printf("Unable to Open %s\n", inputFile);
        return 1;
    }
    
    //Loop that goes trough the entire Inputfile
    while (fread(buffer, BLOCK, 1, fpointer) == 1) //True
    {
        //Condition to check the start of a JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If found new start of JPG closes current imgFile
            if (foundJpg == 1)
            {
                fclose(img);
            }
            //If first JPG found to this set "foundJpg" to 1(true)
            else 
            {
                foundJpg = 1;
            }
            
            //Prints to a string the name of the img, regarding the counter value
            sprintf(images, "%03i.jpg", counter);
            
            //Opens Output File 
            img = fopen(images, "a");
            
            //Adds 1 to the counter
            counter++;
            
        }
        //If its not the start of a JPG keeps writing to the current one.
        if (foundJpg == 1)
        {
            fwrite(buffer, BLOCK, 1, img);
        }
    }
    
    //Closing the files
    if (fpointer == NULL)
    {
        fclose(fpointer);
    }
    if (img == NULL)
    {
        fclose(img);
    }
    return 0;
}
