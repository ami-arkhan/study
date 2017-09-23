#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int M, S;
int data[SIZE], query[SIZE];

void readCase()
{
	int i;
	scanf("%d\n", &M);
	scanf("%d\n", &S);
	for (i = 0; i < M; i++)
		scanf("%d ", &data[i]);
	for (i = 0; i < S; i++)
		scanf("%d ", &query[i]);
}

void binarySearch(int value, int start, int end)
{
	// If 'start' and 'end' index are same, search for value
	if (start == end)
	{
		if (value == data[start])
			printf("%d ", start);
		else
			printf("-1 ");
		return;
	}

	int middle;
	middle = (start + end) / 2;

	// Divide sorted array into half and search in half
	if (value <= data[middle])
		binarySearch(value, start, middle);
	else if (value > data[middle])
		binarySearch(value, middle + 1, end);
}

int main()
{
	int i, test, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();
		printf("#%d ", test);
		// For each query search binary tree
		for (i = 0; i < S; i++)
			binarySearch(query[i], 0, M - 1);
		printf("\n");
	}
}
