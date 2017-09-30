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
	int i, j, key;

	/****************************************************************************
	*	Insertion Sort:															*
	*	1. Search for small value and store it.									*
	*	2. Compare with previously sorted values to find position to insert.	*
	*	3. Once element is moved, insert stored value into correct location.	*
	****************************************************************************/
	for (i = 0; i < N; i++)
	{
		// Store small value
		key = data[i];

		// Compare with all previous value and move all intermediate elements
		j = i - 1;
		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j--;
		}
		// Insert element to correct location
		data[j + 1] = key;
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
