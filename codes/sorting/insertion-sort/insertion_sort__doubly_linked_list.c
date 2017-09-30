#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N;
struct node {
	int data;
	struct node *prev;
	struct node *next;
}*head;

struct node *createNode(int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

void insertList(int data)
{
	struct node *cur = head;

	while (cur->next != NULL)
		cur = cur->next;

	cur->next = createNode(data);
	cur->next->prev = cur;
}

void readCase()
{
	int i, data;

	// Initial head with dummy value
	head = createNode(-1);

	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
	{
		// Read data and make initial list
		scanf("%d ", &data);
		insertList(data);
	}
}

void insertionSort()
{
	int key, moveRequired;
	struct node *cur = head;
	struct node *prev, *temp;

	// If list is empty, that's not possible because atleast 1 data is read
	if (head->next == NULL)
		return;

	while (cur->next != NULL)
	{
		// No more removing and insertion required initially
		moveRequired = 0;

		cur = cur->next;
		prev = cur->prev;
		key = cur->data;

		// If previous data is greater than key value, search for correct position to insert
		while ((prev->data != -1) && (prev->data > key))
		{
			// Remove and insertion is required
			moveRequired = 1;
			prev = prev->prev;
		}
		// If remove and insertion is required
		if (moveRequired)
		{
			// Remove node, store last node position
			temp = cur->prev;
			temp->next = cur->next;
			// If removing node is not tail node
			if (cur->next != NULL)
				cur->next->prev = temp;

			// Inserting to correct location found previously
			cur->prev = prev;
			cur->next = prev->next;
			cur->next->prev = cur;
			prev->next = cur;

			// Set new current location from previously stored location
			cur = temp;
		}
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
		insertionSort();

		printf("#%d ", test);
		printCase();
	}
}
