//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 11, 2020.
//Harvard X --> cs50 --> shorts --> recursion --> collatz.c
//Takes a natural number and calculate its factorial.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//function factorial declaration
int collatz(int n);
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
	    if (n > 2E5)
	    {
	    	printf("This number is too large, use 0 > n < 26\n");
	    	return 1;
	    }
	    else
	    {
			int result = collatz(n);
			printf("collatz(%i) = %i\n", n, result);
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

int collatz(int n)
{
	int collatz_number = 0;
	while ( true )
	{
		if (n == 1)
		{
			break;
		}
		else if (n % 2 == 0)
		{
			collatz_number++;
			collatz(n / 2);
		}
		else
		{
			collatz_number++;
			collatz(3 * n - 1);
		}
	}
	return collatz_number;
}
