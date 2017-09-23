#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

struct DNode {
	int data;
	struct DNode *prev;
	struct DNode *next;
};

struct DNode *createNode(int value)
{
	struct DNode *temp;
	temp = (struct DNode *) malloc(sizeof(struct DNode));
	temp->data = value;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void printList(struct DNode *list)
{
	struct DNode *last = list;
	printf("Head to tail contains: ");
	while (list) {
		printf("%d ", list->data);
		last = list;
		list = list->next;
	}
	printf("\n");
	printf("Tail to head contains: ");
	list = last;
	while (list) {
		printf("%d ", list->data);
		list = list->prev;
	}
	printf("\n");
}

struct DNode *insertFirst(struct DNode *head, int value)
{
	struct DNode *temp;

	if (head == NULL)
	{
		head = createNode(value);
	}
	else
	{
		temp = head;
		head = createNode(value);
		head->next = temp;
		temp->prev = head;
	}
		return head;
}

struct DNode *insertAnyPosition(struct DNode *head, int pos, int value)
{
	struct DNode *list;
	struct DNode *temp;

	if (1 == pos)
	{
		if (NULL == head)
			head = createNode(value);
		else
		{
			temp = head;
			head = createNode(value);
			head->next = temp;
			temp->prev = head;
		}
	}
	else
	{
		list = head;
		while (pos > 2)
		{
			pos--;
			list = list->next;
		}
		temp = list->next;
		list->next = createNode(value);
		if (temp)
			temp->prev = list->next;
		//list->next->next = temp;
		list->next->prev = list;
	}

	return head;
}

struct DNode *insertLast(struct DNode *head, int value)
{
	struct DNode *list;
	struct DNode *temp;

	if (head == NULL)
	{
		head = createNode(value);
	}
	else
	{
		temp = createNode(value);
		list = head;
		while (list->next != NULL)
		{
			list = list->next;
		}
		list->next = temp;
		temp->prev = list;
	}

	return head;
}

struct DNode *deleteFirst(struct DNode *head)
{
	struct DNode *temp;

	if (head)
	{
		temp = head->next;
		free(head);
		head = temp;
		if (head)
			head->prev = NULL;
	}

	return head;
}

struct DNode *deleteAnyPosition(struct DNode *head, int pos)
{
	struct DNode *temp;
	struct DNode * list = head;

	if (1 == pos)
	{
		if (NULL == list)
			return NULL;
		if (list->next == NULL)
		{
			free(list);
			return NULL;
		}
		temp = list->next;
		free(list);
		head = temp;
		head->prev = NULL;
	}

	return head;
}

struct DNode *deleteLast(struct DNode *head)
{
	return head;
}

int main()
{
	int choice, value, pos;
	struct DNode *head = NULL;
	do {
		printList(head);
		printf("Enter your choice from 0 to 6.\n");
		printf("0. Exit\n");
		printf("1. Insert first\n");
		printf("2. Insert any position\n");
		printf("3. Insert last\n");
		printf("4. Delete first\n");
		printf("5. Delete any postion\n");
		printf("6. Delete last\n");
		printf("Enter  your Choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			printf("The program is now exit.\n");
			break;
		case 1:
			printf("Enter any value to insert first: ");
			scanf("%d", &value);
			head = insertFirst(head, value);
			break;
		case 2:
			printf("Enter any position to insert: ");
			scanf("%d", &pos);
			printf("Enter any value to insert: ");
			scanf("%d", &value);
			head = insertAnyPosition(head, pos, value);
			break;
		case 3:
			printf("Enter any value to insert last: ");
			scanf("%d", &value);
			head = insertLast(head, value);
			break;
		case 4:
			head = deleteFirst(head);
			break;
		case 5:
			printf("Enter any position to delete: ");
			scanf("%d", &pos);
			head = deleteAnyPosition(head, pos);
			break;
		case 6:
			head = deleteLast(head);
			break;
		}
	} while (choice);
	return 0;
}
