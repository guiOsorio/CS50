// Program which classifies a sentence entered by the user according to its Coleman-Liau index
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// find numbers of letters, sentences and words in the text
int get_letters(char* text);
int get_sentences(char* text);
int get_words(char* text);

int main(void)
{
    // ask user for text and store it in the text variable
    char text[50];
	printf("Text: ");
	scanf("%s", text);
    // storing number of letters, sentences and words in text in individual variables
    int letters = get_letters(text);
    int sentences = get_sentences(text);
    int words = get_words(text);
    // get letters and sentences per 100 words
    float letters100 = ((float) letters / (float) words) * 100;
    float sentences100 = ((float) sentences / (float) words) * 100;
    // calculate the grade level readability
    int grade = round(0.0588 * letters100 - 0.296 * sentences100 - 15.8);
    // print your findings
    if(grade < 1)
    {
        printf("Before Grade 1...\n");
    }
    else if(grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int get_letters(char* text)
{
    int total = 0;
    int i;
    for(i = 0; i < strlen(text); i++)
    {
        if(isupper(text[i]) || islower(text[i]))
        {
            total += 1;
        }
    }
    return total;
}

int get_sentences(char* text)
{
    int total = 0;
    int i;
    for(i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            total += 1;
        }
    }
    return total;
}

int get_words(char* text)
{
    int total = 1;
    int i;
    for(i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
        {
            total += 1;
        }
    }
    return total;
}

