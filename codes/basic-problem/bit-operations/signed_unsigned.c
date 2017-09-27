#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void bitPrint(int x)
{
	int i;
	for (i = 7; i >= 0; i--)
		printf("%d", (x >> i) & 1);
}

int main()
{
	signed int a;
	unsigned int b;

	printf("-----------------------------------\n");
	printf("1. Signed numbers: 0~127 & -1~-128:");
	printf("\n-----------------------------------\n");
	for (a = 0; a < 6; a++)
	{
		printf("%5d = ", a);
		bitPrint(a);
		printf("\n");
	}
	printf(" ...............\n");
	printf(" ...............\n");
	for (a = 125; a < 128; a++)
	{
		printf("%5d = ", a);
		bitPrint(a);
		printf("\n");
	}
	printf(" ...............\n");
	printf(" ...............\n");
	for (a = -128; a < -123; a++)
	{
		printf("%5d = ", a);
		bitPrint(a);
		printf("\n");
	}
	printf(" ...............\n");
	printf(" ...............\n");
	for (a = -5; a < 0; a++)
	{
		printf("%5d = ", a);
		bitPrint(a);
		printf("\n");
	}

	printf("\n---------------------------\n");
	printf("2. Unsigned numbers: 0~255:");
	printf("\n---------------------------\n");
	for (b = 0; b < 6; b++)
	{
		printf("%5d = ", b);
		bitPrint(b);
		printf("\n");
	}
	printf(" ...............\n");
	printf(" ...............\n");
	for (b = 250; b < 256; b++)
	{
		printf("%5d = ", b);
		bitPrint(b);
		printf("\n");
	}

	printf("\n-----------------------------------------------------------\n");
	printf("3. Negative numbers are 2's complement of positive numbers:");
	printf("\n-----------------------------------------------------------\n");
	b = 5;
	printf("Original value: %4d = ", b);
	bitPrint(b);
	printf("\n");
	printf("1's complement of %2d = ", b);
	bitPrint(~b);
	printf("\n");
	printf("2's complement of %2d = ", b);
	bitPrint(~b + 1);
	printf(" => -5, Equivalent to negative of original value.\n\n");

	return 0;
}
