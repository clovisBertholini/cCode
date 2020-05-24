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
	int unsorted = 0;
	while (unsorted < QTD)
	{
		int i, j;
		for (i = unsorted; i < QTD; i++)
		{
			j = unsorted;
			while (j < QTD)
			{
				if (v[i] <= v[j])
				{
				j++;
				}
				else
				{
					selected = v[j];
					break;
				}
			}
		}
		v[j] = v[i];
		v[i] = selected;
		unsorted++;
	}
	//print numbers sorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
	system("pause");
}
