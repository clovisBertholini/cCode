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
	int numberOfCoins = 0, change;
	change = getChangeValue();
	numberOfCoins = calculateChangeCoins(change);
	printf("%i\n", numberOfCoins);
}

int getChangeValue(void)
{
	float changeValue, aux;
	int roundedChangeValue;
	do
	{
		printf("Type your change value:\n");
		scanf("%f", &aux);
	}
	while (aux < 0);
	changeValue = roundf(aux * 100);
	roundedChangeValue = (int)changeValue;
	return roundedChangeValue;
}

int calculateChangeCoins(int n)
{
	int coins = 0, coin25 = 0, coin10 = 0, coin5 = 0, coin1 = 0;
	while (n >= 25)
	{
		coin25++;
		n -= 25;
	}
	if (n >= 10)
	{
		while (n >= 10)
		{
			coin10++;
			n -= 10;
		}
	}
       	if (n >= 5)
	{
		while (n >= 5)
		{
			coin5++;
			n -= 5;
		}
	}
	coin1 = n;
	coins = coin1 + coin5 + coin10 + coin25;
	return coins;
}
