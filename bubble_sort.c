//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 18, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithm --> Bubble Sort
//bubble_sort.c --> takes the given array and sort it

#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <stdlib.h>

const int QTD = 5;

//functions declarations
void bubble_sort(int v[]);

int main(void)
{
	int numbers[QTD];
       	//populate numbers array
	for (int i = 0; i < QTD; i++)
		numbers[i] = (int)random(); 
	//print numbers unsorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", numbers[i]);
		printf("\n");
	}
	printf("\n");
	//sort numbers array with bubble sort algorithm
	bubble_sort(numbers);
	return 0;
}

void bubble_sort(int v[])
{
	int swap = -1;
	while (swap != 0)
	{
		swap = 0;
		for (int i = 1; i < QTD; i++)
		{
			if (v[i] < v[i - 1])
			{
				int aux = v[i];
				v[i] = v[i - 1];
				v[i - 1] = aux;
				swap++;
			}
		}
	}
	//print sorted numbers
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
}
