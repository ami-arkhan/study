#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N;
int data[SIZE];

// Pruning: If sorting complete early stop checking
//int isSwapped;

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &data[i]);
}

void bubbleSort(int n)
{
	int i, temp;

	/************************************************************
	*	Bubble Sort:											*
	*	1. Sort for (n-1)th position, once element is sorted,	*
	*		recursively sort for (n-1)th position.				*
	*	2. Move large elements sequentially to last index.		*
	*	3. Once last index is reached, element is sorted.		*
	************************************************************/

	// Pruning: No need to sort for 0th position, as it is already sorted
	if (n == 1)
		return;

	// Pruning: Initially consider that swapping is not required, data already sorted
	//isSwapped = 0;
	for (i = 1; i < n; i++)
	{
		if (data[i - 1] > data[i])
		{
			temp = data[i];
			data[i] = data[i - 1];
			data[i - 1] = temp;

			// Pruning: Swap occured
			//isSwapped = 1;
		}
	}

	// Pruning: If no swapping occured, it means data are already in sorted state
	//if (isSwapped)
		// Recursive call for (n-1)th position sorting
		bubbleSort(n - 1);
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
		// Initially call for (n-1)th position sorting
		bubbleSort(N);

		printf("#%d ", test);
		printCase();
	}
}
