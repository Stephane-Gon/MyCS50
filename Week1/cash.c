#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coinsUsed = 0;
    float change;
    do
    {
        change = get_float("Change owed?\n"); //This is a propmt that asks the user how much change is owed.
    }
    while (change < 0); //This is a loop that keeps, asking the question if the user gives a negative number.

    int cents = round(change * 100); //This turns the value the user gave in dollars to cents.
    
    while (cents >= 25) //This checks how many quarters fit in the change.
    {
        cents -= 25;
        coinsUsed++;
    }
    while (cents >= 10) //This checks how many dimes still fit in the change.
    {
        cents -= 10;
        coinsUsed++;
    }
    while (cents >= 5) //This checks how many nickels still fit in the change.
    {
        cents -= 5;
        coinsUsed++;
    }
    while (cents >= 1) //This checks how many pennies still fit in the change. 
    {
        cents -= 1;
        coinsUsed++;
    }
    printf("%i\n", coinsUsed);
}
