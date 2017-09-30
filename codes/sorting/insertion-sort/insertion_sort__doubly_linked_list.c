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

void insertionSort()
{
	int key, removeRequired;

	struct node *temp = head;
	struct node *prevNode, *cur;

	// If list is empty, that's not possible because atleast 1 data is read
	if (head->next == NULL)
		return;

	/****************************************************************************
	*	Insertion Sort:															*
	*	1. Search for small value and store it.									*
	*	2. Compare with all previous value to find correct position to insert.	*
	*	3. Once correct location is located, remove element and update links.	*
	*	4. Insert element to correct location and update links.					*
	****************************************************************************/
	while (temp->next != NULL)
	{
		// No more removing and insertion required initially
		removeRequired = 0;

		temp = temp->next;
		prevNode = temp->prev;
		key = temp->data;

		// If previous data is greater than key value, search for correct position to insert
		while ((prevNode->data != -1) && (prevNode->data > key))
		{
			// Remove and insertion is required
			removeRequired = 1;
			prevNode = prevNode->prev;
		}
		// If remove and insertion is required
		if (removeRequired)
		{
			// Remove node, store last checked node position
			cur = temp->prev;
			cur->next = temp->next;
			// If removing node is not tail node
			if (temp->next != NULL)
				temp->next->prev = cur;

			// Inserting to correct location found previously
			temp->prev = prevNode;
			temp->next = prevNode->next;
			temp->next->prev = temp;
			prevNode->next = temp;

			// Set current location as last checked node position
			temp = cur;
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
