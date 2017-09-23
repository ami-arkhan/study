#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

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

struct node* createArrayToList(int n, int a[])
{
	int i;
	struct node* head;
	struct node* list;

	head = createNode(a[0]);
	list = head;
	for (i = 1; i < n; i++)
	{
		list->next = createNode(a[i]);
		list = list->next;
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

int search(struct node* head, int value)
{
	while (head != NULL)
	{
		if (head->data == value)
			return 1;
		head = head->next;
	}
	return 0;
}

int searchValue(struct node* head, int value)
{
	int found = 0;
	struct node* list;
	list = head;
	if (head->data == value)
		return ++found;

	while (list->next != NULL)
	{
		list = list->next;
		if (list->data == value)
			found++;
	}

	return found;
}

int searchPosition(struct node* head, int pos)
{
	int countNode = 0, possible = 0;
	struct node* list;
	list = head;
	countNode++;
	while (list->next != NULL)
	{
		list = list->next;
		countNode++;
	}
	printf("count: %d", countNode);
	if (pos < countNode + 2 && pos > 0)
		possible++;

	return possible;
}


struct node* insertFirst(struct node* head, int item)
{
	struct node* temp;
	temp = createNode(item);
	temp->next = head;

	return temp;
}

struct node* insertLast(struct node* head, int item)
{
	struct node* temp;
	if (head == NULL)
	{
		head = createNode(item);

		return head;
	}

	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = createNode(item);

	return head;
}

struct node* insertByPosition(struct node* head, int pos, int item)
{
	int location;
	struct node* temp;
	struct node* list;

	if (!searchPosition(head, pos))
		return head;

	temp = createNode(item);

	if (1 == pos)
	{
		temp->next = head;
		head = temp;

		return head;
	}

	list = head;
	location = 1;
	while (pos > 2)
	{
		list = list->next;
		pos--;
	}
	temp->next = list->next;
	list->next = temp;

	return head;
}

struct node* insertAfterValue(struct node* head, int value, int item)
{
	struct node* temp;
	struct node* list;

	if (!searchValue(head, value))
		return head;

	temp = createNode(item);
	list = head;
	while (list->data != value)
	{
		list = list->next;
	}
	temp->next = list->next;
	list->next = temp;

	return head;
}

struct node* insertBeforeValue(struct node* head, int value, int item)
{
	struct node* temp;
	struct node* list;

	if (!searchValue(head, value))
		return head;

	temp = createNode(item);
	list = head;
	if (head->data == value)
	{
		temp->next = head;

		return temp;
	}

	while (list->next->data != value)
	{
		list = list->next;
	}
	temp->next = list->next;
	list->next = temp;

	return head;
}

struct node* deleteFirst(struct node* head)
{
	struct node* temp;
	if (head == NULL)
		return head;

	temp = head->next;
	free(head);

	return temp;
}

struct node* deleteLast(struct node* head)
{
	struct node* list;
	if (head == NULL)
		return head;

	if (head->next == NULL)
	{
		free(head);

		return NULL;
	}

	list = head;
	while (list->next->next != NULL)
	{
		list = list->next;
	}
	free(list->next);
	list->next = NULL;

	return head;
}

struct node* deleteByPosition(struct node* head, int pos)
{
	struct node* temp;
	struct node* list;

	if (!searchPosition(head, pos))
		return head;

	if (1 == pos)
	{
		temp = head->next;
		free(head);

		return temp;
	}

	list = head;
	while (pos > 2)
	{
		list = list->next;
		pos--;
	}
	temp = list->next->next;
	free(list->next);
	list->next = temp;

	return head;
}

struct node* deleteAfterValue(struct node* head, int value)
{
	struct node* temp;
	struct node* list;

	if (!search(head, value))
		return head;

	list = head;
	while (list != NULL && list->data != value)
	{
		list = list->next;
	}
	if (list->next != NULL)
	{
		temp = list->next->next;
		free(list->next);
		list->next = temp;
	}

	return head;
}

struct node* deleteBeforeValue(struct node* head, int value)
{
	struct node* temp;
	struct node* list;
	
	if (!search(head, value))
		return head;

	list = head;
	if (list->data == value)
		return head;

	if (list->next->data == value)
	{
		temp = list->next;
		free(list);

		return temp;
	}

	while (list->next->next->data != value)
	{
		list = list->next;
	}
	temp = list->next->next;
	free(list->next);
	list->next = temp;

	return head;
}

struct node* deleteAllDuplicates(struct node* head)
{
	struct node* inner;
	struct node* outer;
	struct node* temp;

	outer = head;
	while (outer != NULL)
	{
		inner = outer;
		while (inner->next != NULL)
		{
			if (outer->data == inner->next->data)
			{
				//temp = inner->next->next;
				//free(inner->next);
				//inner->next = temp;

				temp = inner->next;
				inner->next = inner->next->next;
				free(temp);
			}
			else
			{
				inner = inner->next;
			}
		}
		outer = outer->next;
	}
	return head;
}

struct node* deleteLinkedList(struct node* head)
{
	struct node* temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}

	return head;
}

struct node* swapTwoNodes(struct node* head, int x, int y)
{
	struct node* newHead;
	struct node* px;
	struct node* py;
	struct node* temp;

	newHead = createNode(0);
	newHead->next = head;

	px = newHead;
	while (px->next != NULL && px->next->data != x)
	{
		px = px->next;
	}

	py = newHead;
	while (py->next != NULL && py->next->data != y)
	{
		py = py->next;
	}
	if (px->next == NULL || py->next == NULL)
	{
		free(newHead);

		return head;
	}

	temp = px->next;
	px->next = py->next;
	py->next = temp;

	temp = px->next->next;
	px->next->next = py->next->next;
	py->next->next = temp;

	temp = newHead->next;
	free(newHead);

	return temp;
}

struct node* reverseLinkedList(struct node* head)
{
	struct node* temp;
	struct node* reverse;

	if (head == NULL)
		return head;

	reverse = head;
	head = head->next;
	reverse->next = NULL;

	while (head != NULL)
	{
		temp = head->next;
		head->next = reverse;
		reverse = head;
		head = temp;
	}

	return reverse;
}

struct node* reverseLinkedListRecursion(struct node* head)
{
	struct node* first = head;
	struct node* second = head->next;

	if (head == NULL)
		return head;

	if (head->next == NULL)
		return head;
	head = reverseLinkedListRecursion(second);
	first->next = NULL;
	second->next = first;

	return head;
}

struct node* createCycle(struct node* head)
{
	struct node* list;

	list = head;
	while (list->next != NULL)
	{
		list = list->next;
	}
	list->next = head->next;

	return head;
}

int detectLoop(struct node* head)
{
	struct node* first;
	struct node* second;
	first = second = head;
	while (second->next != NULL && second->next->next != NULL)
	{
		first = first->next;
		second = second->next->next;
		if (first == second)
			return 1;
	}
	return 0;
}

void deleteByPointer(struct node *ptr)
{
	struct node *temp;

	temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;
	free(temp);
}

int searchPalindrom(struct node* head)
{
	struct node* list;
	int i, Len = 0, Mid, Center, data[1001];

	list = head;
	while (list != NULL)
	{
		list = list->next;
		Len++;
	}

	if (Len == 0)
	{
		return 0;
	}

	if (Len == 1)
	{
		return 1;
	}

	list = head;
	for (i = 1; i <= (Len / 2); i++)
	{
		data[i] = list->data;
		list = list->next;
	}
	if (1 == Len % 2)
	{
		i++;
		list = list->next;
	}

	for (; i <= Len; i++)
	{
		if (data[Len - i + 1] != list->data)
		{
			return 0;
			break;
		}
		list = list->next;
	}

	return 1;
}

struct node* mergeTwoList(struct node* first, struct node* second)
{
	struct node* list;
	struct node* head;

	if (first->data < second->data)
	{
		head = first;
		first = first->next;
	}
	else
	{
		head = second;
		second = second->next;
	}

	list = head;
	while (first != NULL && second != NULL)
	{
		if (first->data < second->data)
		{
			list->next = first;
			first = first->next;
		}
		else
		{
			list->next = second;
			second = second->next;
		}
		list = list->next;
	}
	/*while (first != NULL)
	{
		list->next = first;
		first = first->next;
		list = list->next;
	}
	while (second != NULL)
	{
		list->next = second;
		second = second->next;
		list = list->next;
	}*/

	if (first != NULL)
	{
		list->next = first;
	}
	if (second != NULL)
	{
		list->next = second;
	}

	return head;
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

int main()
{
	//freopen("input.txt", "r", stdin);
	int choice, value, item, x, y, pos, isCycle = 0;
	struct node* head;
	struct node* first;
	struct node* second;
	int a[] = { 1, 4, 6, 9 };
	int b[] = { 2, 3, 5 };
	//head = createList();
	head = NULL;
	do{
		printf("###############\n");
		printf("Current List: ");
		//if (!isCycle)
			printList(head);
		printf("###############\n");
		printf("List Operations:\n");
		printf("================\n");
		printf("0. Exit\n");
		printf("1. Insert First\n");
		printf("2. Enter Last\n");
		printf("3. Insert by Position\n");
		printf("4. Insert After a Value\n");
		printf("5. Insert Before a Value\n");
		printf("6. Delete First\n");
		printf("7. Delete Last\n");
		printf("8. Delete by Position\n");
		printf("9. Delete After a Value\n");
		printf("10. Delete Before a Value\n");
		printf("11. Delete all duplicate values\n");
		printf("12. Delete a link list\n");
		printf("13. Swap two Nodes\n");
		printf("14. Reverse Linked List\n");
		printf("15. Detect Loop\n");
		printf("16. Merge Two List\n");
		printf("17. Delete by Pointer\n");
		printf("18. Search Palindrome\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 0:
				printf("The program is now exit.\n");
				break;
			case 1:
				printf("Enter any item to insert first: ");
				scanf("%d", &item);
				head = insertFirst(head, item);
				break;
			case 2:
				printf("Enter any item to insert last: ");
				scanf("%d", &item);
				head = insertLast(head, item);
				break;
			case 3:
				printf("Enter any position to insert: ");
				scanf("%d", &pos);
				printf("Enter any item to insert: ");
				scanf("%d", &item);
				head = insertByPosition(head, pos, item);
				break;
			case 4:
				printf("Enter any value to search: ");
				scanf("%d", &value);
				printf("Enter any item to insert: ");
				scanf("%d", &item);
				head = insertAfterValue(head, value, item);
				break;
			case 5:
				printf("Enter any value to search: ");
				scanf("%d", &value);
				printf("Enter any item to insert: ");
				scanf("%d", &item);
				head = insertBeforeValue(head, value, item);
				break;
			case 6:
				head = deleteFirst(head);
				break;
			case 7:
				head = deleteLast(head);
				break;
			case 8:
				printf("Enter any position to delete: ");
				scanf("%d", &pos);
				head = deleteByPosition(head, pos);
				break;
			case 9:
				printf("Enter any value to delete After: ");
				scanf("%d", &value);
				head = deleteAfterValue(head, value);
				break;
			case 10:
				printf("Enter any value to delete Before: ");
				scanf("%d", &value);
				head = deleteBeforeValue(head, value);
				break;
			case 11:
				head = deleteAllDuplicates(head);
				break;
			case 12:
				head = deleteLinkedList(head);
				isCycle = 0;
				break;
			case 13:
				printf("Enter 1st value to Swap: ");
				scanf("%d", &x);
				printf("Enter 2nd value to Swap: ");
				scanf("%d", &y);
				head = swapTwoNodes(head, x, y);
				break;
			case 14:
				head = reverseLinkedList(head);
				//	head = reverseLinkedListRecursion(head);
				break;
			case 15:
				//head = createCycle(head);
				if (detectLoop(head))
					printf("Yes\n");
				else
					printf("No\n");
				break;
			case 16:
				first = createArrayToList(0, a);
				printf("First list contains: ");
				printList(first);
				second = createArrayToList(3, b);
				printf("Second list contains: ");
				printList(second);
				head = mergeTwoList(first, second);
				printf("Merge list contains: ");
				printList(head);
				break;
			case 17:
				deleteByPointer(head->next);
				break;
			case 18:
				if (searchPalindrom(head))
					printf("Yes\n");
				else
					printf("No\n");
				break;
		}
	} while (choice != 0);

	return 0;
}
