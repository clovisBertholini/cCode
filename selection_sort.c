//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 20, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithm --> Selection Sort
//selection_sort.c --> takes the given array and sort it

#include <stdio.h>
#include <stdlib.h>

const int QTD = 5;

//functions declarations
void selection_sort(int v[]);

int main(void)
{
	int numbers[QTD];
       	//populate numbers array
	for (int i = 0; i < QTD; i++)
		numbers[i] = random(); 
	//print numbers unsorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", numbers[i]);
		printf("\n");
	}
	printf("\n");
	//sort numbers array with selection sort algorithm
	selection_sort(numbers);
	return 0;
}

void selection_sort(int v[])
{
	//TODO
	//print sorted numbers
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
}
