//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 19, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithm --> Insertion Sort
//insertion_sort.c --> takes the given array and sort it

#include <stdio.h>
#include <stdlib.h>

const int QTD = 5;

//functions declarations
void insertion_sort(int v[]);

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
	//sort numbers array with bubble sort algorithm
	insertion_sort(numbers);
	return 0;
}

void insertion_sort(int v[])
{
	for (int i = 1; i < QTD; i++)
	{
		int j = 0;
		int sorted = numbers[j];
		while (numbers[i] < numbers[j])
		{
			numbers[i] = numbers[j];
			j--;
		}
		numbers[j] = numbers[i];
		numbers[i] = sorted;
	}
	//print sorted numbers
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
}
