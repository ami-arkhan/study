#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define MAX_TABLE 4096
#define MAX_KEY 65
#define MAX_DATA 129

int N, Q;

struct HNode{
	char key[MAX_KEY];
	char data[MAX_DATA];
}table[MAX_TABLE];

void init()
{
	int i;
	for (i = 0; i < MAX_TABLE; i++)
		table[i].key[0] = '\0';
}

int hash(char *ch)
{
	unsigned long hash = 5381;
	int c;
	while (c = *ch++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash;
}

int strcmp(char *des, char *src)
{
	int i;
	for (i = 0; src[i] && des[i] && src[i] == des[i]; i++);

	return src[i] - des[i];
}

void strcopy(char *des, char *src)
{
	int i = 0;
	while (src[i])
		des[i] = src[i++];
	des[i] = '\0';
}

int add(char *key, char *data)
{
	unsigned long h = hash(key);

	while (table[h].key[0] != '\0')
	{
		if (strcmp(table[h].key, key) == 0)
			return 0;
		h = (h + 1) % MAX_TABLE;
	}
	strcopy(table[h].key, key);
	strcopy(table[h].data, data);

	return 1;
}

void read_case()
{
	int i;
	char key[MAX_KEY], data[MAX_DATA];

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s %s", &key, &data);
		if (!add(key, data))
			break;
	}
}

int find(char *key, char *data)
{
	unsigned long h = hash(key);
	int count = MAX_TABLE;
	while (table[h].key[0] != '0' && count--)
	{
		if (strcmp(table[h].key, key) == 0)
		{
			strcopy(data, table[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}

	return 0;
}

void solve_case()
{
	int i, index;
	char key[MAX_KEY], data[MAX_DATA];

	scanf("%d", &Q);
	for (i = 0; i < Q; i++)
	{
		scanf("%s", &key);

		if(find(key, data))
			printf("%s\n", data);
		else
			printf("not find\n");
	}
}

int main()
{
	int i, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (i = 1; i <= T; i++)
	{
		init();
		read_case();
		printf("#%d\n", i);
		solve_case();
	}

	return 0;
}
