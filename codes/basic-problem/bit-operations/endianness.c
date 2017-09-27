#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void bitPrint(char p)
{
	int i;
	for (i = 7; i >=0; i--)
		printf("%d", (p >> i) & 1);
}

int main()
{
	char i, *p;

	char a = 0x10;
	int x = 0x01020304;
	int y = 123456789;

	printf("Little-Endians:\n\n");
	printf("%d = ", a);
	p = &a;
	bitPrint(*p);
	printf("\n\n");

	printf("0%x = ", x);
	p = (char *) &x;
	for (i = 0; i < 4; i++)
	{
		bitPrint(*p++);
		printf(" ");
	}
	printf("\n\n");

	printf("%d = ", y);
	p = (char *)&y;
	for (i = 0; i < 4; i++)
	{
		bitPrint(*p++);
		printf(" ");
	}
	printf("\n\n");


	return 0;
}
