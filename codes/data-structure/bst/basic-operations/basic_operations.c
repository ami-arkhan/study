#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

// BST Implementation
struct TNode{
	int data;
	struct TNode *left, *right;
};

struct TNode *createNode(int n)
{
	struct TNode *temp;
	temp = (struct TNode *)malloc(sizeof(struct TNode));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct TNode *insert(struct TNode *root, int n)
{
	if (NULL == root)
	{
		root = createNode(n);
		return root;
	}
	if (n < root->data)
		root->left = insert(root->left, n);
	else if (n > root->data)
		root->right = insert(root->right, n);

	return root;
}

int search(struct TNode *root, int key)
{
	if (NULL == root)
		return 0;
	else if (key < root->data)
		return search(root->left, key);
	else if (key > root->data)
		return search(root->right, key);
	else
		return 1;
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

struct TNode *immediateUp(struct TNode *root, int n)
{
	struct TNode *temp;
	if (NULL == root)
		return root;
	if (n < root->data)
	{
		temp = immediateUp(root->left, n);
		if (NULL == temp)
			return root;
		else
			return temp;
	}
	else if (n >= root->data)
		return immediateUp(root->right, n);
}

struct TNode *immediateDown(struct TNode *root, int n)
{
	struct TNode *temp;
	if (NULL == root)
		return root;
	if (n > root->data)
	{
		temp = immediateDown(root->right, n);
		if (NULL == temp)
			return root;
		else
			return temp;
	}
	else if (n <= root->data)
		return immediateDown(root->left, n);
}

int absDif(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

struct TNode *closestNode(struct TNode *root, int n)
{
	struct TNode *temp;
	if (NULL == root)
		return root;
	if (root->data < n)
	{
		temp = closestNode(root->right, n);
		if (temp && absDif(root->data, n) < absDif(temp->data, n))
			return temp;
		else
			return root;
	}
	else if (root->data > n)
	{
		temp = closestNode(root->left, n);
		if (temp && absDif(root->data, n) <= absDif(temp->data, n))
			return temp;
		else
			return root;
	}
	else
		return root;
		//temp = closestNode(root->left, n);
	/*if (temp && absDif(root->data, n) > absDif(temp->data, n))
		return temp;
	else
		return root;*/
}

int isBST(struct TNode *root, int n)
{
	struct TNode *temp, *leftMax, *rightMin;

	if (NULL == root)
		return 1;
	
	//if (n > root->data)
	//	isBST(root-> , root->data);


}

struct TNode *makeTree(struct TNode *root)
{
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 70);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 80);

	return root;
}

struct TNode *makeTree2(struct TNode *root)
{
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 75);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 80);

	return root;
}

int compareTree(struct TNode *root1, struct TNode *root2)
{
	if (NULL == root1 && NULL == root2)
		return 1;
	if (NULL == root1)
		return 0;
	if (NULL == root2)
		return 0;
	if (root1->data != root2->data)
		return 0;
	if (0 == compareTree(root1->left, root2->left))
		return 0;
	if (0 == compareTree(root1->right, root2->right))
		return 0;

	return 1;
}

void deleteTree(struct TNode *root)
{
	if (NULL == root)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

struct TNode *deleteTree2(struct TNode *root)
{
	if (NULL == root)
		return NULL;
	root->left = deleteTree2(root->left);
	root->right = deleteTree2(root->right);
	free(root);

	return NULL;
}

void mirrorTree(struct TNode *root)
{
	struct TNode *temp;
	if (NULL == root)
		return;
	temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirrorTree(root->left);
	mirrorTree(root->right);
}

struct TNode *copyTree(struct TNode *src)
{
	struct TNode *dest;
	if (NULL == src)
		return NULL;
	dest = (struct TNode *)malloc(sizeof(struct TNode));
	dest->data = src->data;
	dest->left = copyTree(src->left);
	dest->right = copyTree(src->right);

	return dest;
}

void printLevel(struct TNode *root, int level)
{
	if (NULL == root)
		return;
	if (1 == level)
	{
		printf("%d ", root->data);
		return;
	}
	printLevel(root->left, level-1);
	printLevel(root->right, level - 1);
}

int getHeight(struct TNode *root)
{
	int leftHeight, rightHeight;
	leftHeight = rightHeight = 0;
	if (NULL == root)
		return 0;
	leftHeight = getHeight(root->left);
	rightHeight = getHeight(root->right);

	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
}

void printAllLevel(struct TNode *root)
{
	int height, level;
	height = getHeight(root);
	for (level = 1; level <= height; level++)
	{
		printf("Level %d: ", level);
		printLevel(root, level);
		printf("\n");
	}
}

void printAllLevel2(struct TNode *root)
{
	struct Queue current;
	int lastLevel = 0;
	initQueue();

	if (NULL == root)
		return;

	push(root, 1);
	while (!isEmpty())
	{
		current = pop();
		if (current.level != lastLevel)
		{
			printf("\nLevel %d: ", current.level);
			lastLevel = current.level;
		}
		printf("%d ", current.node->data);
		if (current.node->left)
			push(current.node->left, current.level + 1);
		if (current.node->right)
			push(current.node->right, current.level + 1);
	}
}

void preorder(struct TNode *root)
{
	printf("%d ", root->data);
	if (root->left != NULL)
		preorder(root->left);
	if (root->right != NULL)
		preorder(root->right);
}

void inorder(struct TNode *root)
{
	if (root->left != NULL)
		inorder(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		inorder(root->right);
}

void postorder(struct TNode *root)
{
	if (root->left != NULL)
		postorder(root->left);
	if (root->right != NULL)
		postorder(root->right);
	printf("%d ", root->data);
}

int main()
{
	struct TNode *root, *root2, *temp;
	int choice, n;
	root = NULL;
	root2 = NULL;
	do{
		if (root)
		{
			printf("\nPreorder: ");
			preorder(root);
			printf("\nInorder: ");
			inorder(root);
			printf("\nPostorder: ");
			postorder(root);
			printf("\n");
		}
		else
			printf("\nThe tree is empty\n");
		printf("0. Exit\n");
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Delete\n");
		printf("4. Find Upper, Lower & Closest\n");
		printf("5. Print Level\n");
		printf("6. Height\n");
		printf("7. Print All Level\n");
		printf("8. Compare Tree\n");
		printf("9. Delete Tree\n");
		printf("10. Mirror Tree\n");
		printf("11. Copy Tree\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("\n");
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
				printf("Enter any number to search: ");
				scanf("%d", &n);
				if (search(root, n))
					printf("Found.\n");
				else
					printf("Not found.\n");
				break;
			case 3:
				printf("Enter any number to delete: ");
				scanf("%d", &n);
				root = deleteNode(root, n);
				break;
			case 4:
				printf("Enter any number to search upper, lower & closest value: ");
				scanf("%d", &n);
				// Upper Value
				temp = immediateUp(root, n);
				if (NULL == temp)
					printf("Existing Upper Value: None\n");
				else
					printf("Existing Upper Value: %d\n", temp->data);
				// Lower Value
				temp = immediateDown(root, n);
				if (NULL == temp)
					printf("Existing Lower Value: None\n");
				else
					printf("Existing Lower Value: %d\n", temp->data);
				// Closest Value
				temp = closestNode(root, n);
				if (NULL == temp)
					printf("Existing Closest Value: None\n");
				else
					printf("Existing Closest Value: %d\n", temp->data);
				break;
			case 5:
				printf("Enter level to print: ");
				scanf("%d", &n);
				printf("Level %d: ", n);
				printLevel(root, n);
				printf("\n");
				break;
			case 6:
				printf("Height : %d\n", getHeight(root));
				break;
			case 7:
				printAllLevel(root);
				printAllLevel2(root);
				break;
			case 8:
				root = makeTree(root);
				//root2 = makeTree2(root2);
				//if (compareTree(root, root2))
				//	printf("Tree is same.\n");
				//else
				//	printf("Tree is Not same.\n");
				break;
			case 9:
				deleteTree(root);
				root = NULL;

				//root = deleteTree2(root);
				break;
			case 10:
				mirrorTree(root);
				break;
			case 11:
				root2 = makeTree2(root2);
				root = copyTree(root2);
				break;
		}
	} while (choice != 0);

	return 0;
}
