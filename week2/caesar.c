//These are the references for the different librarys

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//This is the declaration of my functions
int check_digits(string a);
string encypher_text(int n, string a);



int main(int argc, string argv[])
{
    // These are my variables.
    int key;
    string plainText;

    if (argc < 2 || argc > 2) //This checks if the user has write the right number of arguments.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        if (check_digits(argv[1]) == 0) //Here we see if the string has only numbers.
        {
            key = atoi(argv[1]); //If true, here we turn the string to an int.
        }
        else
        {
            return 1;
        }
    }

    plainText = get_string("What is your plain text: "); //Asking the user for a text.
    
    plainText = encypher_text(key, plainText); //Here we run the function to encypher the text.
    
    printf("ciphertext:  %s\n", plainText); //Here we output the cypher text.
    
    return 0; //Exit program.

}


int check_digits(string a) //This function checks if a string only has numbers.
{
    int onlyNumbers = 0;

    for (int i = 0; i < strlen(a); i++)
    {
        if (isdigit(a[i]) == false) //Checks the individuals chars of the string.
        {
            onlyNumbers = 0;
            break; //If 1 of the char is not a number the loop stops.
        }
        else
        {
            onlyNumbers = 1;
        }
    }
    if (onlyNumbers == 1)
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

string encypher_text(int n, string a) //Function that encypher's the text.
{

    for (int i = 0; i < strlen(a); i++)
    {
        char ch = a[i];
        
        if (ch >= 97 && ch <= 122) //Checks if char is a lowercase letter.
        {
            ch -= 97; //Converts ASCII to alphabeticla order.
            ch += n;
            
            if (ch > 25)
            {
                ch = ((a[i] - 97) + n) % 26; //Formula that converts plainText to cypherText.
            }
            
            ch += 97; //Converts alphabetical order back to ASCII.
            a[i] = ch;
        }
        else if (ch >= 65 && ch <= 90) //Checks if char is a uppercase letter.
        {
            ch -= 65; //Converts ASCII to alphabeticla order.
            ch += n;
            
            if (ch > 25)
            {
                ch = ((a[i] - 65) + n) % 26; //Formula that converts plainText to cypherText.
            }
            
            ch += 65; //Converts alphabetical order back to ASCII.
            a[i] = ch;
        }
    }
    return a;
}