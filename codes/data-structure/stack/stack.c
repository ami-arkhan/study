#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N, count;
int stack[SIZE];

void init()
{
	count = 0;
}

void push(int num)
{
	stack[count++] = num;
}
void read_data()
{
	int i, num;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		push(num);
	}
}

int pop()
{
	return stack[--count];
}
void print_stack()
{
	int i;
	while (count)
		printf(" %d", pop());
	printf("\n");
}

int main()
{
	int i, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (i = 1; i <= T; i++)
	{
		init();
		read_data();
		printf("#%d", i);
		print_stack();
	}

	return 0;
}
