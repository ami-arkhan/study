#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double X, result;
// 10 <= N <= 500000000
long int N;

// For debugging how many recursions are called to find the solution
//int recursion_count;

double power(long int pow)
{
	// For debugging how many test recursions are called to find the solution
	//recursion_count++;

	if (pow == 1)
		return X;

	// Divide and conquer
	if (pow % 2 == 0)
		return ((power(pow / 2)) * (power(pow / 2)));
	else
		return ((power((pow - 1) / 2)) * (power((pow - 1) / 2)) * X);
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (test = 1; test <= T; test++)
	{
		// For debugging how many recursions are called to find the solution
		//recursion_count = 0;

		scanf("%lf %ld\n", &X, &N);
		result = power(N);
		printf("#%d %0.5lf\n", test, result);

		// For debugging how many recursions are called to find the solution
		//printf("Recursion called: %d\n", recursion_count);
	}

	return 0;
}
