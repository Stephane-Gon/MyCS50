#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

// Declaration of my functions.
int count_letters(string a);
int count_words(string a);
int count_sentences(string a);
int calculate_grade(int word, int letter, int sentence);


int main(void)
{
    //Variables
    string text;
    int numberLetters;
    int numberWords;
    int numberSentences;
    int grade;

    text = get_string("Text: \n"); //Prompting the user for a text.

    numberLetters = count_letters(text);
    numberWords = count_words(text);
    numberSentences = count_sentences(text);
    grade = calculate_grade(numberWords, numberLetters, numberSentences);
    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", grade);
    }
    
    
}



int count_letters(string a) //Function that checks for the ammount of letters.
{
    int letter = 0;

    for (int i = 0; i < strlen(a) ; i++)
    {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A'
                                             && a[i] <= 'Z')) //Any time a letter between the "a/z" or "A/Z" appears 1 will be added to letter.
        {
            letter++;
        }
    }
    return letter;
}


int count_words(string a) //Function that checks for the ammount of words.
{
    int words = 0;
    for (int i = 0; i < strlen(a) ; i++)
    {
        if (a[i] == ' ') //Any time a space apears 1 will be added to words.
        {
            words++;
        }
    }
    return words + 1; //Here we have "+1" because of the first word of the sentence.
}


int count_sentences(string a) //Function that counts the ammount of sentences.
{
    int sentences = 0;

    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '.' || a[i] == '!' || a[i] == '?') //If one of those characters appears setences will be added by one.
        {
            sentences++;
        }
    }
    return sentences;
}


int calculate_grade(int word, int letter, int sentence) //Function that calculates the Coleman-Liau index.
{
    

    float result = 0.0588 * (100 * (float) letter / (float) word) - 0.296 * (100 * (float) sentence / 
                   (float) word) - 15.8; //Coleman-Liau formula

    return round(result);
}