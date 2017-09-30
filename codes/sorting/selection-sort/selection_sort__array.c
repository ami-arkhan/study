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

void insertionSort()
{
	int i, j, minIndex, temp, isMinFound;

	/********************************************************************************
	*	Selection Sort:																*
	*	1. Search for smaller value and swap with elements from start sequentially.	*
	*	2. Comparison is done on all remaining elements.							*
	********************************************************************************/
	for (i = 0; i < N - 1; i++)
	{
		isMinFound = 0;

		// Find minimum element index
		minIndex = i;
		for (j = i + 1; j < N; j++)
		{
			if (data[minIndex] > data[j])
			{
				minIndex = j;
				isMinFound = 1;
			}
		}

		// If minimum element found swap with current sorted location
		if (isMinFound)
		{
			temp = data[i];
			data[i] = data[minIndex];
			data[minIndex] = temp;
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
		insertionSort();

		printf("#%d ", test);
		printCase();
	}
}
