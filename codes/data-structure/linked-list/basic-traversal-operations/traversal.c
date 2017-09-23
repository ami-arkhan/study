#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define SIZE 101
int search_Value, freqValue, Nth;

struct node {
	int data;
	struct node* next;
};

struct node* createNode(int item)
{
	struct node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = item;
	temp->next = NULL;

	return temp;
}

struct node* createList(int N, int *Data)
{
	int i;
	struct node* head;
	struct node* temp;
	head = createNode(Data[1]);
	N--;
	i = 2;
	temp = head;
	while (N--)
	{
		temp->next = createNode(Data[i]);
		temp = temp->next;
		i++;
	}
	return head;
}

int countNode(struct node* head)
{
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}

	return count;
}

int searchValue(struct node* head, int value)
{
	int found = 0;
	struct node* temp;
	temp = head;
	if (temp->data == value)
		return ++found;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data == value)
		{
			found = 1;
			break;
		}
	}

	return found;
}

int countFreq(struct node* head, int value)
{
	int freq = 0;
	struct node* temp;
	temp = head;
	if (temp->data == value)
		freq++;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data == value)
			freq++;
	}

	return freq;
}

int maxValue(struct node* head)
{
	int max = 0;
	struct node* temp;
	temp = head;
	if (temp->data > max)
		max = temp->data;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data > max)
		{
			max = temp->data;
		}
	}

	return max;
}

int minValue(struct node* head)
{
	int min = 9999;
	struct node* temp;
	temp = head;
	if (temp->data < min)
		min = temp->data;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data < min)
		{
			min = temp->data;
		}
	}

	return min;
}

int sumList(struct node* head)
{
	int tempSum = 0;
	struct node* temp;
	temp = head;
	tempSum += temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		tempSum += temp->data;
	}

	return tempSum;
}

int averageList(struct node* head)
{
	return (sumList(head) / countNode(head));
}

void printNth(struct node* head, int value)
{
	int count = 0;
	struct node* temp;
	temp = head;
	count++;
	if (count == value)
	{
		printf("%d", temp->data);
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
		if (count == value)
		{
			printf("%d", temp->data);
			break;
		}
	}
}

void printNthFromLast(struct node* head, int value)
{
	int count = 0;
	struct node* temp;
	temp = head;
	count++;
	value = countNode(head) - value + 1;
	if (count == value)
	{
		printf("%d", temp->data);
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
		if (count == value)
		{
			printf("%d", temp->data);
			break;
		}
	}
}

void printList(struct node* head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void printReverse(struct node* head)
{
	if (head->next == NULL)
		printf("%d ", head->data);
	else
	{
		printReverse(head->next);
		printf("%d ", head->data);
	}
}

void readData(int N, int *Data)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%d ", &Data[i]);
	}

	scanf("%d %d %d", &search_Value, &freqValue, &Nth);
}

int main()
{
	int n, Data[SIZE];
	struct node* head;
	scanf("%d", &n);
	readData(n, &Data[0]);
	head = createList(n, Data);

	printf("Node Count: %d\n", countNode(head));
	printf("Value Search: %d\n", searchValue(head, search_Value));
	printf("Freq Count: %d\n", countFreq(head, freqValue));
	printf("Max Value: %d\n", maxValue(head));
	printf("Min Value: %d\n", minValue(head));
	printf("List Sum: %d\n", sumList(head));
	printf("Average List: %d\n", averageList(head));
	printf("Print Nth Node: ");
	printNth(head, Nth);
	printf("\nPrint Nth Node From Last: ");
	printNthFromLast(head, Nth);
	printf("\nPrint List: ");
	printList(head);
	printf("Print Reverse: ");
	printReverse(head);
	printf("\n");

	return 0;
}
