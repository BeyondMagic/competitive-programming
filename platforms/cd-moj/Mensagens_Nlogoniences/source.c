#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct celula
{
	size_t dado;
	char c;
	struct celula *prox;
} celula;

void list_destroy (celula *le)
{
	celula *temp = le;
	while (temp)
	{
		le = temp;
		temp = temp->prox;
		free(le);
	}
}

/*
void list_print (celula *le)
{
	while (le && le->prox)
		printf("%zu -> ", le->prox->dado), le = le->prox;
	puts("NULL");
}*/

// returns the pointed node OR the node that has less data
celula *list_find_less (celula *le, size_t x)
{
	if (!le->prox)
		return le;

	while (le && le->prox && le->prox->dado <= x)
		le = le->prox;
	return le;
}

// returns the element
celula *list_find (celula *le, size_t x)
{
	le = le->prox; // move out of the head
	while (le && le->dado != x)
		le = le->prox;
	return le;
}


bool list_insert_start (celula *le, size_t x, char c)
{
	celula *p = list_find(le, x);

	// did not find such element.
	if (p)
		return false;

	// inserir no começo
	celula *nova = malloc(sizeof(celula));
	nova->dado = x;
	nova->prox = le->prox;
	nova->c = c;
	le->prox = nova;

	return true;
}


int list_insert (celula *node, size_t x, char c)
{
	// returns the element that has the same value or the lower...
	node = list_find_less(node, x);

	// duplicada.
	if (node->dado == x)
		return false;

	// add element after this one
	celula *nova = malloc(sizeof(celula));
	nova->dado = x;
	nova->prox = node->prox;
	nova->c = c;
	node->prox = nova;

	return true;
}

// returns the element before the find
celula *list_find_before (celula *le, size_t x)
{
	while (le && le->prox && le->prox->dado != x)
		le = le->prox;
	return le;
}

int list_remove (celula *p, size_t x)
{
	p = list_find_before(p, x);

	// did not find such element.
	if (!p || !p->prox)
		return false;

	celula *temp = p->prox;
	if (p->prox->prox)
		p->prox = p->prox->prox;
	else
		p->prox = NULL;

	return free(temp), true;
}


typedef struct
{
	// NOTE: Professor está errado?... deveria ser uma matriz...
	celula *tb; // tabela hash
	size_t M; // tamanho da tabela hash
	size_t N; // total de chaves presentes na tabela
} TH;

inline size_t hash_table_position (TH *hash_table, size_t pos)
{
	return pos % hash_table->M;
}

void hash_table_destroy (TH *hash_table)
{
	list_destroy(hash_table->tb);
	free(hash_table);
}

TH *hash_table_create (size_t M)
{
	TH *hash_table = malloc(sizeof(TH));

	// inicializar valores
	hash_table->M = M;
	hash_table->N = 0;

	// inicializar tabela
	hash_table->tb = malloc(M * sizeof(celula));
	for (size_t i = 0; i < M; ++i)
	{
		// hash_table->tb[i].dado = SSIZE_MAX;
		hash_table->tb[i].prox = NULL;
		// hash_table->tb[i].c = '\0';
	}

	return hash_table;
}

/*void hash_table_print (TH *hash_table)
{
	printf("Hash Table | M = %zu | N = %zu\n", hash_table->M, hash_table->N);
	for (size_t i = 0; i < hash_table->M; ++i)
	{
		if ((hash_table->tb + i)->prox)
		{
			printf(" - Key %zu => ", i);
			list_print(hash_table->tb + i);
		}
	}
}*/

// true se foi inserido
// falso se falhou
bool hash_table_insert (TH *h, size_t ch, char c)
{
	const size_t pos = hash_table_position(h, ch);
	if (list_insert_start(&h->tb[pos], ch, c))
		return ++h->N, true;
	return false;
}

// true se foi removido
// falso se falhou (não encontrou)
bool hash_table_remove (TH *h, size_t ch)
{
	const size_t pos = hash_table_position(h, ch);
	if (list_remove(&h->tb[pos], ch))
		return --h->N, true;
	return false;
}

// retorna NULL se não encontrar
celula * hash_table_find_id (TH *h, size_t ch)
{
	const size_t pos = hash_table_position(h, ch);
	return list_find(&h->tb[pos], ch);
}

int main(void)
{
	TH *hash_table = hash_table_create(1572869);
	size_t id;
	char c;
	size_t max = 0,
		   min = SSIZE_MAX;
	while (scanf(" %zu %c", &id, &c) == 2)
	{
		hash_table_insert(hash_table, id, c);
		if (id > max)
			max = id;
		if (id < min)
			min = id;
	}

	// printf("Range [%zu, %zu]\n", min, max);
	for (size_t i = min; i <= max; ++i)
	{
		celula *e = hash_table_find_id(hash_table, i);
		assert(e != NULL);
		putchar(e->c);
	}
	putchar('\n');
	hash_table_destroy(hash_table);
}
