#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N, count;
int start[SIZE], finish[SIZE];

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d %d ", &start[i], &finish[i]);
}

void swap(int a, int b)
{
	int temp;

	// Swap start time
	temp = start[a];
	start[a] = start[b];
	start[b] = temp;

	// Swap finish time
	temp = finish[a];
	finish[a] = finish[b];
	finish[b] = temp;
}

void sortFinishTime()
{
	int i, j, temp;
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (finish[i] > finish[j])
				swap(i, j);
}

void solveCase()
{
	int i, index;

	/************************************************************************
	*	1. Sort finish time in ascending order.								*
	*	2. When one activity is finished, next one will start.				*
	*	3. Most early finished activity is taken as first activity,			*
	*		as this is considered as optimal solution (Greedy Approach).	*
	*	4. In this method, all possible test set (2^n) is not generated,	*
	*		hence time complexity reduced.									*
	************************************************************************/

	sortFinishTime();

	// There will be atleast 1 meeting scheduled
	count = 1;
	index = 0;
	for (i = 1; i < N; i++)
	{
		// If next activity starts after current (initially 1st) activity, increase activity count
		if (start[i] >= finish[index])
		{
			count++;
			index = i;
		}
	}
}

int main()
{
	int test, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();
		solveCase();

		printf("#%d %d\n", test, count);
	}

	return 0;
}
