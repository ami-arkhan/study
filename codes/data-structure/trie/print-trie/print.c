#define CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define SIZE 27

struct TrieNode {
	int count;
	int freq;
	struct TrieNode *child[SIZE];
};

struct TrieNode *createNode()
{
	int i;
	struct TrieNode *tNode;
	tNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));
	tNode->count = 0;
	tNode->freq = 0;
	for (i = 0; i < SIZE; i++)
		tNode->child[i] = NULL;
	return tNode;
}

void insertTrie(struct TrieNode *root, char word[])
{
	int i, j, index;
	struct TrieNode *cur = root;
	for (j = 0; word[j]; j++)
	{
		cur = root;
		for (i = j; word[i]; i++)
		{
			index = word[i] - 'a';
			if (NULL == cur->child[index]) {
				cur->child[index] = createNode();
				cur->count++;
			}
			cur = cur->child[index];
			cur->freq++;
		}

	}
}

void printTrie(struct TrieNode *root, char output[], int index)
{
	int i;
	if (0 == root->count) {
		output[index] = '\0';
		printf("%s\n", output);
		return;
	}
	for (i = 0; i < SIZE; i++) {
		if (root->child[i]) {
			output[index] = i + 'a';
			printTrie(root->child[i], output, index + 1);
		}
	}
}

void printSubString(struct TrieNode *root, char output[], int index)
{
	int i, freq;
	for (i = 0; i < SIZE; i++) {
		if (root->child[i]) {
			output[index] = i + 'a';
			output[index + 1] = '\0';
			freq = root->child[i]->freq;
			while (freq--)
				printf("%s\n", output);
			printSubString(root->child[i], output, index + 1);
		}
	}
}

int main()
{
	struct TrieNode *root;
	char st[SIZE];
	root = createNode();
	insertTrie(root, "banana");

	//printTrie(root, st, 0);
	printSubString(root, st, 0);
	return 0;
}
