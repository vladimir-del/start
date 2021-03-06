/*-------------------------------------------------
//Date: 05.11.2020
//Autor: Vlaimir Draga
//S. Prata. Chapter 13
//Programming exercise 7a
//-------------------------------------------------
/* 
Text programmming exersice.
7. Write a program that opens two files. You can obtain the filenames either by using
command-line arguments or by soliciting the user to enter them.
 a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
first file, line 2 of the second file, and so on, until the last line of the longer file (in
terms of lines) is printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fa, *fb;
	char ch1, ch2;
	if (argc != 3)
	{
		printf("Usage: $%s [file name1], [file name2]", argv[0]);
		exit(3);
	}
	
	if ((fa = fopen(argv[1], "r")) == NULL)
		{
			puts("Cannot open file");
			exit(1);
		}
		
	if ((fb = fopen(argv[2], "r")) == NULL)
		{
			puts("Cannot open file");
			exit(2);
		}
	
	ch1 = getc(fa);
	ch2 = getc(fb);
	
		while((ch1 != EOF) || (ch2 != EOF))
		{
			while ((ch1 != EOF) && (ch1 != '\n'))
			{
				putchar(ch1);
				ch1 = getc(fa);
			}
			if (ch1 != EOF)
			{
				putchar('\n');
				ch1 = getc(fa);
			}
			
			
			while ((ch2 != EOF) && (ch2 != '\n'))
			{
				putchar(ch2);
				ch2 = getc(fb);
			}
			
			if (ch2 != EOF)
			{
				putchar('\n');
				ch2 = getc(fb);
			}
		}	
		putchar('\n');
	return 0;
}