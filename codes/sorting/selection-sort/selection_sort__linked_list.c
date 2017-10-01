#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N;
struct node {
	int data;
	struct node *next;
}*head;

struct node *createNode(int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->next = NULL;

	return temp;
}

void insertList(int data)
{
	struct node *cur = head;

	while (cur->next != NULL)
		cur = cur->next;

	cur->next = createNode(data);
}

void readCase()
{
	int i, data;

	// Initialize head with dummy value
	head = createNode(-1);

	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
	{
		// Read data and make initial list
		scanf("%d ", &data);
		insertList(data);
	}
}

void selectionSort()
{
	int isMinFound;
	struct node *pos = head;
	struct node *cur, *min;

	// If list is empty or list contains only 1 element
	if (head->next == NULL || head->next->next == NULL)
		return;

	/************************************************************************************
	*	Selection Sort:																	*
	*	1. Search for smaller value and swap with elements from start sequentially.		*
	*	2. Comparison is done on all remaining elements.								*
	*	3. As elements are sorted sequentiall from start, insert position is known.		*
	************************************************************************************/

	while (pos->next != NULL)
	{
		// Both starts from same insert location
		min = pos->next;
		cur = pos->next;

		// Pruning: If only 1 element remains, no need to check as it is already sorted
		//if (cur->next == NULL)
		//	break;

		// Search for minimum node: Initially no minimum element found to swap
		isMinFound = 0;
		while (cur->next != NULL)
		{
			cur = cur->next;
			if (min->data > cur->data)
			{
				min = cur;
				isMinFound = 1;
			}
		}
		// If minimum element found: Remove and insert minimum element node
		if (isMinFound)
		{
			// Traverse to node before minimum location
			cur = pos;
			while (cur->next->data != min->data)
				cur = cur->next;

			// Remove minimum node
			min = cur->next;
			cur->next = cur->next->next;

			// Add removed minimum node
			min->next = pos->next;
			pos->next = min;
		}

		// Point to next sequential insert location from start
		pos = pos->next;
	}
}

void printCase()
{
	struct node *cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
		printf("%d ", cur->data);
	}
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
		selectionSort();

		printf("#%d ", test);
		printCase();
	}
}
