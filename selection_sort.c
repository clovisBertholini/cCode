//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 20, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithm --> Selection Sort
//selection_sort.c --> takes the given array and sort it

#include <stdio.h>
#include <stdlib.h>

const int QTD = 15;

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
	int j = 0;
	int selected;
	for (int i = 0; i < QTD; i++)
	{
		j = i + 1;
		while (j < QTD)
		{
			if (v[i] < v[j])
			{
				j++;
			}
			else
			{
				selected = v[j];
				v[j] = v[i];
				v[i] = selected;
				break;
			}
		}
	}
	//print numbers sorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
}
