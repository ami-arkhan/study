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
	int a = 55;
	int b = 10;
	int c = 23;
	int d = 75;

	printf("-------------------------------------------------\n");
	printf("1. Changing variables without temporary variable:");
	printf("\n-------------------------------------------------\n\n");
	printf("Initial values:\n");
	printf("a = %d, b = %d\n\n", a, b);

	printf("XOR operations:\n");
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d, b = %d => Number exchanged.\n", a, b);

	printf("\n--------------------------------------\n");
	printf("2. Variable Encryption and Decryption:");
	printf("\n--------------------------------------\n\n");
	printf("Initial value:\n");
	printf("c = %d = ", c);
	bitPrint(c);
	printf("\nd = %d = ", d);
	bitPrint(d);
	printf("\n=====================\n");
	c = c ^ d;
	printf("c = c^d = %d = ", c);
	bitPrint(c);
	printf(" => Encryption. Number changed.\n", c);

	printf("\nc = %d = ", c);
	bitPrint(c);
	printf("\nd = %d = ", d);
	bitPrint(d);
	printf("\n=====================\n");
	c = c ^ d;
	printf("c = c^d = %d = ", c);
	bitPrint(c);
	printf(" => Decryption. Number returned to it's original value.\n\n", c);

	return 0;
}
