//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 11, 2020.
//Harvard X --> cs50 --> shorts --> recursion --> fibonacci.c
//Takes a natural number and calculate its fibonacci number.
//Multiples recursion cases.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//function factorial declaration
int fibonacci(int n);
bool validate(string s);

int main(int argc, string argv[])
{
	if (argc != 2 || validate(argv[1]) == 1)
	{
		printf("Usage: fibonacci [natural number]\n");
		return 1;
	}
	else
	{
	    string s = argv[1];
	    int n = atoi(s);
	    if (n > 2E5 || n == 0)
	    {
	    	printf("This number is too large or its equal to 0, use 0 > n < 26\n");
	    	return 1;
	    }
	    else
	    {
			int result = fibonacci(n);
			printf("fibonacci(%i) = %i\n", n, result);
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

int fibonacci(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1; 
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2); 
	}
}
