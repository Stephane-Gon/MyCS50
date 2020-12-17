#include <stdio.h>//Including the printf() function
#include <cs50.h>//Including the get_string() function

int main(void)
{
    string name = get_string("What's your name?\n");//Asking the user a question and getting a answer from them that is string type
    printf("hello, %s \n", name);//Printing Hello, and the answer the user gave to the wuestion above
}