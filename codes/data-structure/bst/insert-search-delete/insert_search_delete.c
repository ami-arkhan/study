#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int preIndex, postIndex;

struct TNode{
	int data;
	struct TNode *left, *right;
	int count;
};

struct TNode *createNode(int n)
{
	struct TNode *temp;
	temp = (struct TNode *)malloc(sizeof(struct TNode));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	temp->count = 0;
	return temp;
}

struct TNode *insert(struct TNode *root, int n)
{
	if (NULL == root)
		root = createNode(n);
	else if (n < root->data)
		root->left = insert(root->left, n);
	else if (n > root->data)
		root->right = insert(root->right, n);
	root->count++;

	return root;
}

struct TNode *search(struct TNode *root, int n)
{
	if (root->left)
	{
		if (n <= root->left->count)
			return search(root->left, n);
		n -= root->left->count;
	}
	if (1 == n)
		return root;
	n--;
	
	return search(root->right, n);
}

struct TNode *deleteNode(struct TNode *root, int n)
{
	struct TNode *temp, *leftMax, *rightMin;
	if (NULL == root)
		return root;
	else if (n < root->data)
		root->left = deleteNode(root->left, n);
	else if (n > root->data)
		root->right = deleteNode(root->right, n);
	else
	{
		if (NULL == root->left && NULL == root->right)
		{
			free(root);
			return NULL;
		}
		else if (NULL == root->left)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if (NULL == root->right)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			/* Replacing root with max value from left sub-tree*/
			//leftMax = root->left;
			//while (leftMax->right)
			//	leftMax = leftMax->right;
			//root->data = leftMax->data;
			//root->left = deleteNode(root->left, leftMax->data);

			/* Replacing root with min value from right sub-tree*/
			rightMin = root->right;
			while (rightMin->left)
				rightMin = rightMin->left;
			root->data = rightMin->data;
			root->right = deleteNode(root->right, rightMin->data);

			return root;
		}
	}

	return root;
}

void inorder(struct TNode *root)
{
	if (NULL == root)
		return;
	inorder(root->left);
	printf("%d:%d ", root->data, root->count);
	inorder(root->right);
}

int main()
{
	struct TNode *root, *temp;
	int n, choice;
	root = NULL;
	do{
		if (root)
		{
			printf("\nInorder: ");
			inorder(root);
			printf("\n");
		}
		else
			printf("\nThe tree is empty\n");
		printf("0. Exit\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 0:
				printf("The program is now exit.\n");
				break;
			case 1:
				printf("Enter any number to insert: ");
				scanf("%d", &n);
				root = insert(root, n);
				break;
			case 2:
				printf("Enter any number to delete: ");
				scanf("%d", &n);
				root = deleteNode(root, n);
				break;
			case 3:
				printf("Enter any number to search: ");
				scanf("%d", &n);
				temp = search(root, n);
				if (temp)
					printf("%d found.\n", temp->data);
				else
					printf("Not found.\n");
				break;
		}
	} while (choice != 0);
	return 0;
}
