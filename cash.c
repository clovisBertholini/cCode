//Author: Clovis Wangerley Bertholini Sobrinho
//Date: April, 18, 2020.
//Source: cash.c
//input a change value and reurn how many coins it is equal
//only 25, 10, 5 and 1 cents

#include <stdio.h>
#include <math.h> //Don't forget use -lm when compile this code to link math lib

int getChangeValue(void);
int calculateChangeCoins(int n);

int main(void)
{
	printf("%i\n", calculateChangeCoins(getChangeValue()));
}

int getChangeValue(void)
{
	float changeValue;	
	do
	{
		printf("Type your change value:\n");
		scanf("%f", &changeValue);
	}
	while (changeValue < 0);
	return (int) roundf(changeValue * 100);
}

int calculateChangeCoins(int n)
{
	int coins = 0;
	while (n >= 25)
	{
		coins++;
		n -= 25;
	}
	if (n >= 10)
	{
		while (n >= 10)
		{
			coins++;
			n -= 10;
		}
	}
       	if (n >= 5)
	{
		while (n >= 5)
		{
			coins++;
			n -= 5;
		}
	}
	coins += n;
	return coins;
}
