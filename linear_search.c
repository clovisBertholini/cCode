// Author: Clovis Wanderley Bertholini Sobrinho
// Date: May, 28, 2020.
// Harvard X --> cs50 --> Week 3 --> Linear Search
// linear_search.c

#include <stdio.h>
#include <stdlib.h>

const int N = 100;

int linear_search(int n, int v[]);

int main(void)
{
	int number = 288; //rand();
	int a[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = rand();
		printf("%iº --> %i\n", i, a[i]);
	}
	int exist = linear_search(number, a);
	if (exist == 1)
	{
		printf("The number %i was found in array a!", number);
	}
	else
	{
		printf("The number %i wasn't found in array a!", number);
	}
	return 0;
}

int linear_search(int n, int v[])
{
	for (int i = 0; i < N; i++)
	{
		if (n == v[i])
		{
			return 1;
		}
	}
	return 0;
}
