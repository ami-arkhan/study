#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define SIZE 101

int N, start, end;
int queue[SIZE];

struct listNode{
	int value;
	struct listNode *prev;
	struct listNode *next;
}*head;

struct listNode *createNode(int num)
{
	struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
	node->value = num;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

void insert(int num)
{
	struct listNode *cur = head;
	if (head == NULL)
	{
		head = createNode(num);
		return;
	}
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = createNode(num);
	cur->next->prev = cur;
}

void read_case()
{
	int i, num;
	struct listNode *cur;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		insert(num);
	}
	cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = head;
	head->prev = cur;
}

void deleteNode(struct listNode *node)
{
	head = head->next;
	head->prev = head->prev->prev;
	head->prev->next = head;

	free(node);
}

void solve_case()
{
	struct listNode *cur = head;
	while (cur->next != NULL && cur->prev != NULL && cur != cur->next)
	{
		deleteNode(cur);
		head = head->next->next;
		cur = head;
	}
}

void print_case()
{
	int i;
	printf("%d\n", head->value);
}

int main()
{
	int i, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (i = 1; i <= T; i++)
	{
		head = NULL;

		read_case();
		solve_case();

		printf("#%d ", i);
		print_case();

		free(head);
	}

	return 0;
}
