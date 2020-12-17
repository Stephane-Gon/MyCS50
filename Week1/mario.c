#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("What height do you want?\n"); //This is a propmt for the user to get an int that will be the height of the pyramid.
    }
    while (height < 1 || height > 8); //This is a loop that keeps asking the user an height if they do not provide a int between 1 and 8 inclusive.

    for (int i = 0; i < height; i++) //This is the column maker
    {
        for (int k = height - 1; k > i; k--) //This is a loop to print blank spaces in a row before the #
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) //This is a loop to print # after the blank spaces
        {

            printf("#");
        }
        printf("\n");

    }

}