#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101
#define DIGIT 10

int N;
int data[SIZE], result[SIZE], count[DIGIT];

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &data[i]);
}

void countingSort()
{
	int i;

	// Initialize count
	for (i = 0; i < DIGIT; i++)
		count[i] = 0;

	// Count each digit
	for (i = 0; i < N; i++)
		count[data[i]]++;

	// Count total, it will indicate last index position of digit in the result array 
	for (i = 1; i < DIGIT; i++)
		count[i] += count[i - 1];

	// Result is generated
	for (i = 0; i < N; i++)
	{
		result[count[data[i]] - 1] = data[i];
		count[data[i]]--;
	}
}

void printCase()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", result[i]);
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
		countingSort();

		printf("#%d ", test);
		printCase();
	}
}
