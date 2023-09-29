#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct celula
{
	int dado;
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

void list_print (celula *le)
{
	while (le && le->prox)
		printf("%d -> ", le->prox->dado), le = le->prox;
	puts("NULL");
}

// returns the pointed node OR the node that has less data
celula *list_find_less (celula *le, int x)
{
	if (!le->prox)
		return le;

	while (le && le->prox && le->prox->dado <= x)
		le = le->prox;
	return le;
}

int list_insert (celula *node, int x)
{
	// returns the element that has the same value or the lower...
	node = list_find_less(node, x);

	// duplicada.
	if (node->dado == x)
		return 0;

	// add element after this one
	celula *nova = malloc(sizeof(celula));
	nova->dado = x;
	nova->prox = node->prox;
	node->prox = nova;

	return 1;
}

// returns the element before the find
celula *list_find_before (celula *le, int x)
{
	while (le && le->prox && le->prox->dado != x)
		le = le->prox;
	return le;
}

// returns the element
celula *list_find (celula *le, int x)
{
	le = le->prox; // move out of the head
	while (le && le->dado != x)
		le = le->prox;
	return le;
}

int list_insert_start (celula *le, int x)
{
	celula *p = list_find(le, x);

	// did not find such element.
	if (p)
		return -1;

	// inserir no começo
	celula *nova = malloc(sizeof(celula));
	nova->dado = x;
	nova->prox = le->prox;
	le->prox = nova;

	return 0;
}

int list_remove (celula *p, int x)
{
	p = list_find_before(p, x);

	// did not find such element.
	if (!p || !p->prox)
		return -1;

	celula *temp = p->prox;
	if (p->prox->prox)
		p->prox = p->prox->prox;
	else
		p->prox = NULL;

	return free(temp), 0;
}


typedef struct
{
	// NOTE: Professor está errado?... deveria ser uma matriz...
	celula *tb; // tabela hash
	int M; // tamanho da tabela hash
	int N; // total de chaves presentes na tabela
} TH;

inline int hash_table_position (TH *hash_table, int pos)
{
	return pos % hash_table->M;
}

void hash_table_destroy (TH *hash_table)
{
	list_destroy(hash_table->tb);
	free(hash_table);
}

TH *hash_table_create (int M)
{
	TH *hash_table = malloc(sizeof(TH));

	// inicializar valores
	hash_table->M = M;
	hash_table->N = 0;

	// inicializar tabela
	hash_table->tb = malloc((size_t) M * sizeof(celula));
	for (int i = 0; i < M; ++i)
		hash_table->tb[i].dado = INT_MIN,
		hash_table->tb[i].prox = NULL;

	return hash_table;
}

void hash_table_print (TH *hash_table)
{
	printf("Hash Table | M = %d | N = %d\n", hash_table->M, hash_table->N);
	for (int i = 0; i < hash_table->M; ++i)
	{
		// if (hash_table->tb[i]->prox)
		// {
		printf(" - Key %d => ", i);
		list_print(&hash_table->tb[i]);
		// }
	}
}

void THinsere (TH *h, int ch)
{
	const int pos = hash_table_position(h, ch);
	if (!list_insert_start(&h->tb[pos], ch))
		++h->N;
}

// 0 se for encontrada
// -1 se não for
int THremove (TH *h, int ch)
{
	const int pos = hash_table_position(h, ch);
	const int result = list_remove(&h->tb[pos], ch);
	if (!result)
		--h->N;
	return result;
}

// 1 se for encontrado
// 0 se nao for encontrado
int THbusca (TH *h, int ch)
{
	const int pos = hash_table_position(h, ch);
	return list_find(&h->tb[pos], ch) ? 1 : 0;
}

/*int main(void)
{
	TH *hash_table = hash_table_create(13);
	THinsere(hash_table, 4);
	THinsere(hash_table, 2);
	THinsere(hash_table, 15);
	THinsere(hash_table, 28);
	THinsere(hash_table, 12);
	if (THbusca(hash_table, 15))
		puts("Achado o elemento 15");
	if (!THremove(hash_table, 28))
		puts("Removido o elemento 28");
	// THinsere(hash_table, 28);
	// THinsere(hash_table, 28);
	THinsere(hash_table, 11);
	THremove(hash_table, 11);
	hash_table_print(hash_table);
	hash_table_destroy(hash_table);
}*/
