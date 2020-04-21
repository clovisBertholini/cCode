//Author: Clovis Wanderley Bertholini Sobrinho
//Date: April, 19, 2020.
//Problem set 1: credit.c Harvard X
//This app ask for a credit card's number and verify its is a valid number

#include <stdio.h>
#include <cs50.h>

//funciton declaration
void checkCardNum(unsigned long long int n);
unsigned long long int getCardNum(void);

//main code
int main (void)
{
	checkCardNum(getCardNum());
}

//functio getCardNum implementation
unsigned long long int getCardNum(void)
{
	unsigned long long int num = 0;
	do
	{
		printf("Type a credit card number: \n");
		scanf("%llu", &num);
		printf("num: %llu\n", num);
	}
	while (num < 0);
	return num;
}

//function checkCardNum implementation
void checkCardNum(unsigned long long int n)
{
	int checkSumAcumulator = 0;
	int digitsNumber = 0;
	int nModTen = 0;
	unsigned long long int cardNumber = n;

	//checking the sum
	while (n % 10 != n)
	{
		if (digitsNumber % 2 == 0) //if is an even digit, it runs block
		{
			nModTen = n % 10;
			n = (unsigned long long int)(n / 10);
			checkSumAcumulator += nModTen;
			digitsNumber++;
		}
		else // if odd...
		{
			nModTen = n % 10;
			n = (unsigned long long int)(n / 10);
			checkSumAcumulator += ((nModTen * 2) % 10) + ((unsigned long long int) nModTen * 2 / 10);
			digitsNumber++;
		}
	}

	if (digitsNumber % 2 == 0)
	{
		checkSumAcumulator += n;
		digitsNumber++;
	}
	else
	{
		checkSumAcumulator += ((n % 10 * 2) % 10) + ((int) n % 10 * 2 / 10);
		digitsNumber++;
	}

	if (digitsNumber == 13 && n == 4 && checkSumAcumulator % 10 == 0)
	{
		printf("VISA\n");
	}
	else if (digitsNumber == 15 && checkSumAcumulator % 10 == 0) 
	{
		if (n * 10 + nModTen == 35 || n * 10 + nModTen == 37)
		{
			printf("AMEX\n");
		}
		else
		{
			printf("INVALID\n");
		}
	}
	else if (digitsNumber == 16 && checkSumAcumulator % 10 == 0) 
	{
		if (n == 4)
		{
			printf("VISA\n");
		}
		else if (n * 10 + nModTen > 50 && n * 10 + nModTen < 56)
		{
			printf("MASTERCARD\n");
		}
		else
		{
			printf("INVALID\n");
		}
	}
	else
	{
		printf("INVALID\n");
	}
}

