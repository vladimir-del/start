//-------------------------------------------------
//Date: 19.10.2020
//Autor: Vlaimir Draga
//S. Prata. Chapter 11
// Programming exercise 12
//-------------------------------------------------

/* 
Text programmming exersice.
12. Write a program that reads input up to EOF and reports the number of words, the
number of uppercase letters, the number of lowercase letters, the number of punctuation
characters, and the number of digits. Use the ctype.h family of functions.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#define LINE_MAX 80

int NumWords(char *s);
int NumUpLetters(char *s);
int NumLowLetters(char *s);
int NumPunc(char *s);
int NumDig(char *s);


int main (int  argc, char *argv[])

{
    char string[LINE_MAX];

    if (fgets(string, LINE_MAX, stdin) && string[0] != '\0')
		puts("You input the right string");
	else
		puts("Error");
    
	puts("In this string there are:");
	printf("Words         = %d \n", NumWords(string));
	printf("Upper letters = %d \n", NumUpLetters(string));
	printf("Lower letters = %d \n", NumLowLetters(string));
	printf("Punctuation   = %d \n", NumPunc(string));
	printf("digits        = %d \n", NumDig(string));
    printf("End programm");
	return 0;
}

int NumWords(char *s)
{
        int inword = false;
        int word = 0;
        //int i = 0;
        while (*s != '\n')
        {
            if (*s == ' ')
            {
                inword = false;
                s++;
                continue;
            }
            else if (inword == false)
            {
                inword = true;
                word++;
            }
            s++;
        }
    return word;
}

int NumUpLetters(char *s)
{
	int NumUpper = 0;	
	
	while(*s != '\n')
	{
		if (isupper(*s))
			NumUpper++;
		s++;
	}
	
	return NumUpper;
}

int NumLowLetters(char *s)
{
	int NumLower = 0;
	while(*s != '\n')
	{
		if (islower(*s))
			NumLower++;
		s++;
	}
	
	return NumLower;
}

int NumPunc(char *s)
{
	int NumPunct = 0;
	while(*s != '\n')
	{
		if (ispunct(*s))
			NumPunct++;
		s++;
	}
	
	return NumPunct;
}

int NumDig(char *s)
{
	int NumDig = 0;
	while(*s != '\n')
	{
		if (isdigit(*s))
			NumDig++;
		s++;
	}
	
	return NumDig;
}
