//Author: Clovis Wanderley Bertholini Sobrinho
//Date: April, 17, 2020.
//Title: Pyramid with a hole File: marioMore.c
//Ref.: Exercise from cs50 Course

#include <stdio.h>

//functions declarations
int getInt(void);
void drawPyramid(int n);

//main code
int main(void)
{
	int height = getInt();
	drawPyramid(height);
}

//getInt()'s code
int getInt(void)
{
	int num;
	do
	{
		//you must to consider that its my first code and I have no how to know
		//to validate the input yet :), so type only integer numbers please!
		printf("Type an integer number, between 1 and 8, inclusive: \n");
		scanf("%d", &num);
	}
	while (num < 1 || num > 8);
	return num;
}
	
//drawPyramid()' codes
void drawPyramid(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < n - i - 1)
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		}
		printf("  ");
		for (int k = 0; k < i + 1; k++)
		{
			printf("#");
		}
		printf("\n");
	}
}
