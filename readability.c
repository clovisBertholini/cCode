//Author: Clovis Wanderley Bertholini Sobrinho
//Date: April, 21, 2020.
//pset2 --> readabbility.c --> cs50 --> Harvard X
//This app takes a string as an input from the user and grade yours reading's level
//with Coleman-Liau Index.

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

//functions' declaration
int countL(string text);
int countW(string text);
int countS(string text);
int computeIndexColemanLiau(int v[]);
void printResult(int n);

//main code
int main(void)
{
	string userInput = get_string("Text: ");
	int lWS[3];
	lWS[0] = countL(userInput);
	lWS[1] = countW(userInput);
	lWS[2] = countS(userInput);
	int grade = computeIndexColemanLiau(lWS);
	printResult(grade);
}
//end main

//function to count letters
int countL(string text)
{
	int l = 0;
	for (int c = 0; c < strlen(text); c++)
	{
		//ASCII [A-Z]-->65-90 and [a-z]-->97-122
		if ((text[c] > 64 && text[c] < 91) || (text[c] > 96 && text[c] < 123))
		{
			l++;
		}
	}
	return l;
}
//end function countL

//function to count Words
int countW(string text)
{
	int w = 0;
	for (int c = 0; c < strlen(text); c++)
	{
		//ASCII 33->!, 46->. and 63->?: before the last word of the
		//text, we have no spaces, so we need to count that words too.
		if (text[c] == 33 || text[c] == 46 || text[c] == 63)
		{
			//to confirm that those signals are the last one. Once
			//strings are arrays with one element plus to configure
			//its finished, whitch is \0-->NULL.
			if (c + 1 == strlen(text))
			{
				w++;
			}
		}
		//ASCII 32->SPACE: before each space we count one word.
		if (text[c] == 32)
		{
			w++;
		}
	}
	return w;
}
//end countW

//functio to count sentences
int countS(string text)
{
	int s = 0;
	for (int c = 0; c < strlen(text); c++)
	{
		//ASCII !->33 .->46 and ?->63: in that problem, the sentences
		//only are ended with those signals.
		if (text[c] == 33 || text[c] == 46 || text[c] == 63)
		{
			s++;
		}
	}
	return s;
}
//end countS

//function to compute Coleman-Liau Index
int computeIndexColemanLiau(int v[])
{
	float f[3];
	for (int i = 0; i < 3; i++)
	{
		f[i] = (float)v[i];
	}
	float l = (f[0] / f[1]) * 100;
	float s = (f[2] / f[1]) * 100;
	int index = (int)round(0.0588 * l - 0.296 * s - 15.8);
	return index;
}
//end computeIndexColemanLiau

//function printResult
void printResult(int n)
{
	if (n < 1)
	{
		printf("Before Grade 1\n");
	}
	else if (n >= 1 && n <= 16)
	{
		printf("Grade %i\n", n);
	}
	else
	{
		printf("Grade 16+\n");
	}
}
//end printResult
