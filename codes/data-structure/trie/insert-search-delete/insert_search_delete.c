#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define SIZE 27

struct TrieNode {
	int count;
	int isLeaf; // isLeaf is added to distinguish if there are samilar letter words such as "bangla" & "bangladesh"
	int freq;
	struct TrieNode *child[SIZE];
};

struct TrieNode *createNode()
{
	int i;
	struct TrieNode *tNode;
	tNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));
	tNode->count = 0;
	tNode->isLeaf = 0;
	tNode->freq = 0;
	for (i = 0; i < SIZE; i++)
		tNode->child[i] = NULL;
	return tNode;
}

void insertTrie(struct TrieNode *root, char word[])
{
	int i, index;
	struct TrieNode *cur = root;
	for (i = 0; word[i]; i++) {
		index = word[i] - 'a';
		if (NULL == cur->child[index]) {
			cur->child[index] = createNode();
			cur->count++;
		}
		cur = cur->child[index];
		cur->freq++;
	}
	cur->isLeaf = 1;
}

int search(struct TrieNode *root, char word[])
{
	int i, index, isFound = 1;
	struct TrieNode *cur = root;
	for (i = 0; word[i]; i++)
	{
		index = word[i] - 'a';
		if (NULL == cur->child[index])
		{
			isFound = 0;
			break;
		}
		cur = cur->child[index];
	}

	if (!cur->isLeaf)
		isFound = 0;

	if (isFound)
		printf("Yes\n");
	else
		printf("No\n");

	return isFound;
}

void delete_recursive(struct TrieNode *root, char word[], int index)
{
	int i, idx;
	struct TrieNode *cur = root;
	idx = word[index] - 'a';
	if (0 == cur->child[idx]->count)
	{
		cur->child[idx]->freq--;
		return;
//		cur->freq--;
	}

	if (cur->child[idx]->count)
	{
		cur = cur->child[idx];
		delete_recursive(cur, word, index + 1);

		if (!cur->freq)
		{
			free(cur->child[index]);
			cur->count--;
		}
	}
}

void delete_word(struct TrieNode *root, char word[])
{
	int i, index, isFound = 1;
	struct TrieNode *cur = root;
	if (search(cur, word))
	{
		delete_recursive(root, word, 0);
	}
	else
		printf("Word not Found\n");
}

void printTrie(struct TrieNode *root, char output[], int index)
{
	int i;
	if (0 == root->count) {
		output[index] = '\0';
		printf("%s\n", output);
		return;
	}
	// This if condition is added for "isLeaf" variable use due to similar letter word: "bangla" & "bangladesh"
	// Now "bangla" will be printed along with "bangladesh" as last "a" is a leaf Node.
	if (root->isLeaf)
	{
		output[index] = '\0';
		printf("%s\n", output);
	}
	for (i = 0; i < SIZE; i++) {
		if (root->child[i]) {
			output[index] = i + 'a';
			printTrie(root->child[i], output, index + 1);
		}
	}
}

int main()
{
	struct TrieNode *root;
	char st[SIZE];
	root = createNode();
	insertTrie(root, "air");
	insertTrie(root, "bangla");
	insertTrie(root, "bangladesh");
	insertTrie(root, "dance");
	search(root, "danc");
	search(root, "dance");
	search(root, "dances");
	delete_word(root, "bangla");


	printTrie(root, st, 0);
	return 0;
}
