#define _DEFAULT_SOURCE
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// 49157
#define M 2000003
// #define M 1572869u

typedef struct celula
{
	unsigned id;
	char c;
	struct celula *next;
} celula;

typedef struct HT
{
	unsigned size;
	celula **v;
} HT;

HT hash_table_create(void)
{
	register HT ht = {.size = 0};
	ht.v = malloc(M * sizeof(celula *));
	return ht;
}


bool hash_table_insert(register HT *ht, register unsigned x, register char c)
{
	register unsigned id = x % M;
	if (!ht->v[id])
	{
		ht->v[id] = malloc(sizeof(celula));
		*ht->v[id] = (celula){.next = NULL, .c = c, .id = x};
		return true;
	}

	register celula *curr = ht->v[id];
	while (curr->next && curr->id != x)
		curr = curr->next;

	if (curr->id == x)
		return false;

	curr->next = (celula *)malloc(sizeof(celula));
	*curr->next = (celula){.id = x, .c = c, .next = NULL};
	ht->size++;
	return true;
}

celula *hash_table_search(register HT ht, register unsigned x)
{
	register unsigned id = x % M;
	register celula *curr = ht.v[id];
	while (curr)
	{
		if (curr->id == x)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

/*
 * Linear probing...
 */

#define EMPTY -1

typedef struct cell
{
	long long id;
	char c;
} cell;

typedef struct HTP
{
	cell *v;
} HTP;

HTP hash_table_create_probing()
{
	HTP htp;
	htp.v = malloc(M * sizeof(celula));
	for (size_t i = 0; i < M; ++i)
		(htp.v + i)->id = EMPTY;
	return htp;
}

// returns node or where it should be if not found
cell *hash_table_search_probing(HTP *htp, unsigned x)
{
	const unsigned pos = x % M;
	unsigned left = pos;
	cell *node = htp-> v + left++;
	while (node->id != EMPTY && node->id != x && left != pos)
		node = htp-> v + (left % M);
	return node;
}

void hash_table_insert_probing(HTP *htp, unsigned x, char c)
{
	cell *node = hash_table_search_probing(htp, x);
	node->id = x;
	node->c = c;
}

int main (void)
{
	HTP ht = hash_table_create_probing();
	unsigned x;
	char c;

	register unsigned min = UINT_MAX, max = 0;
	while (scanf(" %u %c", &x, &c) == 2)
	{
		if (x == min || x == max)
			continue;

		hash_table_insert_probing(&ht, x, c);
		min = x < min ? x : min;
		max = x > max ? x : max;
	}

	// hash_table_print(hash_table);

	// printf("Range [%u, %u]\n", min, max);
	for (register unsigned i = min; i <= max; i++)
		// celula *e = ;
		// assert(e != NULL);
		putchar(hash_table_search_probing(&ht, i)->c);
	putchar('\n');
}

/*int main (void)
{
	HT ht = hash_table_create();
	unsigned x;
	char c;

	register unsigned min = UINT_MAX, max = 0;
	while (scanf(" %u %c", &x, &c) == 2)
	{
		if (x == min || x == max)
			continue;

		hash_table_insert(&ht, x, c);
		min = x < min ? x : min;
		max = x > max ? x : max;
	}

	// hash_table_print(hash_table);

	// printf("Range [%u, %u]\n", min, max);
	for (register unsigned i = min; i <= max; i++)
		// celula *e = ;
		// assert(e != NULL);
		putchar(hash_table_search(ht, i)->c);
	putchar('\n');
}*/
