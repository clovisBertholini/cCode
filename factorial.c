//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 11, 2020.
//Harvard X --> cs50 --> shorts --> recursion --> factorial.c
//Takes a natural number and calculate its factorial.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//function factorial declaration
unsigned long long int factorial(int n);
bool validate(string s);

int main(int argc, string argv[])
{
	if (argc != 2 || validate(argv[1]) == 1)
	{
		printf("Usage: factorial [natural number]\n");
		return 1;
	}
	else
	{
	    string s = argv[1];
	    int n = atoi(s);
	    if (n > 25)
	    {
	    	printf("This number is too large, use 0 > n < 26\n");
	    	return 1;
	    }
	    else
	    {
			unsigned long long int result = factorial(n);
			printf("%i! = %lli\n", n, result);
			return 0;
	    }
	}
}

bool validate(string s)
{
	bool only_numbers;
	for (int i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			only_numbers = true;
		}
		else
		{
			only_numbers = false;
		}
	}
	return only_numbers;
}

unsigned long long int factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}
