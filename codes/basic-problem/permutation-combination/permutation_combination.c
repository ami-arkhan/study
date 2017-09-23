#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 10

char str[SIZE], result[SIZE];
int N, K, length, used[SIZE];

void readCase()
{
	scanf("%s\n", &str);
	scanf("%d\n", &N);
	scanf("%d\n", &K);
}

// Total permutation: nPr
void permutation(int index, int n, int r)
{
	int j, k;
	if (index == r)
	{
		for (int k = 0; k < r; k++)
			printf("%c", result[k]);
		printf("\n");
		return;
	}
	for (j = 0; j < n; j++)
	{
		if (!used[j])
		{
			used[j] = 1;
			result[index] = str[j];
			permutation(index + 1, n, r);
			used[j] = 0;
		}
	}
}

// Total combination: nCr
void combination(int index, int start, int n, int r)
{
	int j, k;
	if (index == r)
	{
		for (int k = 0; k < r; k++)
			printf("%c", result[k]);
		printf("\n");
		return;
	}
	for (j = start; j < n; j++)
	{
		result[index] = str[j];
		combination(index + 1, j + 1, n, r);
	}
}

void solveCase()
{
	// Total permutation: nPr
	permutation(0, N, N);

	// Total combination: nCr
	combination(0, 0, N, K);
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();
		printf("#%d\n", test);
		solveCase();
	}
	return 0;
}
