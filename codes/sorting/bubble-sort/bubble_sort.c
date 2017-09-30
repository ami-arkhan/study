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

void bubbleSort()
{
	int i, temp, index;
	
	// Pruning: If sorting complete early stop checking
	//int isSwapped;

	/****************************************************************
	*	Bubble Sort:												*
	*	1. Move large elements sequentially to last index.			*
	*	2. Once last index is reached, element is sorted.			*
	*	3. Reduce last index position and repeat process untill		*
	*		all elements are sorted.								*
	****************************************************************/

	index = N;
	while(index != 0)
	{
		// Pruning: Initially consider that swapping is not required, data already sorted
		//isSwapped = 0;
		for (i = 1; i < index; i++)
		{
			if (data[i - 1] > data[i])
			{
				temp = data[i];
				data[i] = data[i - 1];
				data[i - 1] = temp;

				// Swap occured
				isSwapped = 1;
			}
		}

		// Pruning: If no swapping occured, it means data are already in sorted state
		//if (!isSwapped)
		//	break;

		index--;
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
		bubbleSort();

		printf("#%d ", test);
		printCase();
	}
}
