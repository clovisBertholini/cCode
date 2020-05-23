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
		numbers[i] = rand(); 
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
	int selected;
	int sorted = 0;
	for (int i = 0; i < QTD; i++)
	{
		int j = sorted;
		while (j < QTD)
		{
			if (v[i] <= v[j])
			{
				j++;
			}
			else
			{
				break;
			}
		}
		if (j == QTD)
		{
			sorted++;
			selected = v[i];
			v[i] = v[j];
			v[j] = selected;
		}
	}
	//print numbers sorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
}
