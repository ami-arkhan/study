#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double X, result;
// 10 <= N <= 500000000
long int N;

// For debugging how many iterations are called to find the solution
//int iteration_count;

void power()
{
	int i;

	// Initialized with 1 for multiplication
	result = 1;
	for (i = 1; i <= N; i++)
	{
		// For debugging how many test iterations are called to find the solution
		//iteration_count++;

		result *= X;
	}
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (test = 1; test <= T; test++)
	{
		// For debugging how many iterations are called to find the solution
		//iteration_count = 0;

		scanf("%lf %ld\n", &X, &N);
		power();
		printf("#%d %0.5lf\n", test, result);

		// For debugging how many iterations are called to find the solution
		//printf("Iteration count: %d\n", iteration_count);
	}

	return 0;
}
