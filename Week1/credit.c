#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    // Ask for credit card number  
    long creditNumber;
    
    do
    {
        creditNumber = get_long("Credit card Number:\n");
    }
    while(creditNumber < 0);
    
     // Determine whether it has a valid number of digits
     
     int count = 0;
     long digits = creditNumber;
     
     while (digits > 0)
     {
         digits = digits/10;
         count++;
     }
     if((count != 13) && (count != 15) && (count !=16))
     {
         printf("INVALID\n");
     }
     int number[count];
     
     for (int i = 0; i < count; i++)
     {
         number[i] = creditNumber % 10;
         creditNumber = creditNumber / 10;
     }
     int originalNumber[count];
     for (int i = 1; i < count; i++)
     {
         originalNumber[i] = number[i];
     }
     for (int i = 1; i <count; i += 2)
     {
         number[i] = number[i] * 2;
     }
     int v = 0;
     int temp;
     
     if (count == 13)
     {
         for (int i = 0; i < count; i++)
         {
             temp = (number[i] % 10) + (number[i]/10 % 10);
             v = v + temp;
         }
         if (originalNumber[12] == 4 && v % 10 == 0)
         {
             printf("VISA\n");
         }
         else 
         {
             printf("INVALID\n");
         }
     }
     if (count == 15)
     {
         for (int i = 0; i < count; i++)
         {
             temp = (number[i] % 10) + (number[i]/10 % 10);
             v = v + temp;
         }
         if (originalNumber[14] == 3 && v % 10 == 0 && (originalNumber[13] == 4 || originalNumber[13] == 7))
         {
             printf("AMEX\n");
         }
         else 
         {
             printf("INVALID\n");
         }
     }
     if (count == 16)
     {
         for (int i = 0; i < count; i++)
         {
             temp = (number[i] % 10) + (number[i]/10 % 10);
             v = v + temp;
         }
         if (originalNumber[15] == 4 && v % 10 == 0)
         {
             printf("VISA\n");
         }
         else if (originalNumber[15] == 5 && v % 10 == 0 && (originalNumber[14] == 1 || originalNumber[14] == 2 || originalNumber[14] == 3 || originalNumber[14] == 4 || originalNumber[14] == 5))
         {
             printf("MASTERCARD\n");
         }
         else
         {
             printf("INVALID\n");
         }
     }
     return 0;
   
}