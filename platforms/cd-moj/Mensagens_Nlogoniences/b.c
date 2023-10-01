#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// vou falar é nada...
#define M 98317
typedef struct celula
{
	unsigned dado;
	char c;
	struct celula *prox;
} celula;

// void list_destroy (celula *le)
// {
// 	celula *temp = le;
// 	while (temp)
// 	{
// 		le = temp;
// 		temp = temp->prox;
// 		free(le);
// 	}
// }
// 
// void list_print (celula *le)
// {
// 	while (le)
// 		printf("%u -> ", le->dado), le = le->prox;
// 	puts("NULL");
// }

// returns the element
celula *list_find (celula *le, unsigned x)
{
	while (le && le->dado != x)
		le = le->prox;
	return le;
}

typedef struct
{
	// NOTE: Professor está errado?... deveria ser uma matriz...
	celula **tb; // tabela hash
	unsigned N; // total de chaves presentes na tabela
} TH;

#define hash_table_position(hash_table, x) x % M;

TH hash_table_create (void)
{
	TH hash_table = {.N = 0 };

	hash_table.tb = malloc(M * sizeof(celula *));
	for (register unsigned i = 0; i < M; ++i)
		hash_table.tb[i] = NULL;

	return hash_table;
}

// void hash_table_print (TH *hash_table)
// {
// 	printf("Hash Table | M = %u | N = %u\n", hash_table->M, hash_table->N);
// 	for (unsigned i = 0; i < hash_table->M; ++i)
// 		if (hash_table->tb[i])
// 			printf(" - Key %u => ", i),
// 			list_print(hash_table->tb[i]);
// }

// true se foi inserido
// falso se falhou
bool hash_table_insert (TH *h, register unsigned ch, char c)
{
	const unsigned pos = hash_table_position(h, ch);

	// se for null a head
	if (!h->tb[pos])
	{
		// add element after this one
		h->tb[pos] = malloc(sizeof(celula));
		*h->tb[pos] = (celula){.prox = NULL, .dado = ch, .c = c};
		// ++h->N;
		return true;
	}

	celula *node = h->tb[pos];

	// returns the element that has the same value or the lower...
	while (node->prox && node->prox->dado != ch)
		node = node->prox;

	// duplicada.
	if (node->dado == ch)
		return false;

	// add element after this one
	node->prox = malloc(sizeof(celula));
	*node->prox = (celula){.prox = NULL, .dado = ch, .c = c};

	// ++h->N;
	return true;
}

celula * hash_table_find_id (TH *h, unsigned ch)
{
	const unsigned pos = hash_table_position(h, ch);
	celula *node = h->tb[pos];
	while (node)
	{
		if (node->dado == ch)
			return node;
		node = node->prox;
	}
	return NULL;
}

int main(void)
{
	TH hash_table = hash_table_create();
	unsigned id;
	char c;
	register unsigned max = 0,
			 min = UINT_MAX;
	while (scanf(" %u %c", &id, &c) == 2)
	{
		if (id == max || id == min)
			continue;
		hash_table_insert(&hash_table, id, c);
		max = id > max ? id : max;
		min = id < min ? id : min;
	}
	// hash_table_print(hash_table);

	// printf("Range [%u, %u]\n", min, max);
	for (register unsigned i = min; i <= max; ++i)
	{
		// celula *e = ;
		// assert(e != NULL);
		putchar(hash_table_find_id(&hash_table, i)->c);
	}
	putchar('\n');
	// hash_table_destroy(hash_table);
}
