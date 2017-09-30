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

	/************************************************************************
	*	Bubble Sort:														*
	*	1. Move large elements sequentially to last index.					*
	*	2. Once last index is reached, element position is fixed.			*
	*	3. Reduce last index position and repeat process untill				*
	*		all elements are sorted.										*
	************************************************************************/

	index = N;
	while(index != 0)
	{
		for (i = 1; i < index; i++)
		{
			if (data[i - 1] > data[i])
			{
				temp = data[i];
				data[i] = data[i - 1];
				data[i - 1] = temp;
			}
		}
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
