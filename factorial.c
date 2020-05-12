//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 11, 2020.
//Harvard X --> cs50 --> shorts --> recursion --> factorial.c
//Takes a natural number and calculate its factorial.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

//function factorial declaration
unsigned long long int factorial(int n);

int main(int argc, string argv[])
{
	if (argc != 2 || !isdigit(argv[1]))
	{
		printf("Usage: factorial [natural number]");
		return 1;
	}
	else
	{
		int n = atoi(argv[1]); 
		unsigned long long int result = factorial(n);
		printf("%i! = %lli", n, result);
		return 0;
	}
}

unsigned long long int factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n);
	}
}
