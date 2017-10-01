#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N;
int data[SIZE];

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &data[i]);
}

void shellSort()
{
	int i, j, key, gap;

	/********************************************************************
	*	Shell Sort:														*
	*	1. Sort elements like insertion sort, but within a gap.			*
    *	2. Once all elements are sorted, reduce gap and keep sorting.	*
	*	3. When gap reduced to one, it will be like insertion sort,		*
	*		but with minimum changes.									*
	********************************************************************/
	for (gap = N / 2; gap > 0; gap /= 2)
	{
		// Do insertion sort for each elements within this gap
		for (i = gap; i < N; i++)
		{
			// Store small value
			key = data[i];

			// Compare with all previous values in gap and move all intermediate elements
			j = i;
			while (j >= gap && data[j - gap] > key)
			{
				data[j] = data[j - gap];
				j -= gap;
			}

			// Insert element to correct location
			data[j] = key;
		}
	}
}

void printCase()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", data[i]);
	printf("\n");
}

int main()
{
	int test, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();
		shellSort();

		printf("#%d ", test);
		printCase();
	}
}
