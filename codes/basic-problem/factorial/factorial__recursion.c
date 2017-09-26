#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N, length, carry;
char result[SIZE];

void init()
{
	carry = length = 0;
}

void solveCase(int number)
{
	int index, num, remainder;
	if (number == 1)
	{
		length++;
		result[0] = '1';
	}
	else
	{
		solveCase(number - 1);

		/************************************************************************
		*	1. Multiply each digit, add carry and get final carry.				*
		*	2. Result is stored reversly, as most significant digit increases.	*
		************************************************************************/
		for (index = 0; index < length; index++)
		{
			num = result[index] - '0';
			num = num * number + carry;
			remainder = num % 10;
			carry = num / 10;

			// Bracket () is necessary, because '=' is right to left operator
			result[index] = (remainder + '0');
		}

		/************************************************
		*	1. If carry remains add to blank spaces.	*
		*	2. Max possible carry: 2 digit.				*
		*		(ex. 20 * 9 = 180 => 180 / 10 => 18)	*
		************************************************/
		while (carry)
		{
			length++;

			num = carry;
			remainder = num % 10;
			// Bracket () is necessary, because '=' is right to left operator
			result[index] = (remainder + '0');
			index++;

			carry = num / 10;
		}
	}
}

void printCase()
{
	int i;
	for (i = length - 1; i >= 0; i--)
		printf("%c", result[i]);
	printf("\n");
}

int main()
{
	int i, test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (test = 1; test <= T; test++)
	{
		init();
		scanf("%d\n", &N);
		solveCase(N);

		printf("#%d %d! = ", test, N);
		printCase();
	}

	return 0;
}
