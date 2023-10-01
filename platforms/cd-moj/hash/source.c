#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

typedef struct celula
{
	int dado; // id
	char *first_name;
	char *last_name;
	char *birthday;
	char *phone_number;
	struct celula *prox;
} celula;

void list_destroy_simple_list (celula *le)
{
	celula *temp = le;
	while (temp)
	{
		le = temp;
		temp = temp->prox;
		free(le);
	}
}

void list_destroy (celula *le)
{
	celula *temp = le;
	while (temp)
	{
		le = temp;
		temp = temp->prox;
		free(le->birthday);
		free(le->last_name);
		free(le->first_name);
		free(le->phone_number);
		free(le);
	}
}

void list_print (celula *le)
{
	while (le && le->prox)
	{
		printf("%d", le->prox->dado), le = le->prox;
		if (le->prox)
			putchar(' ');
	}
	putchar('\n');
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

bool list_insert (celula *node, int x, char *first_name, char *last_name, char *birthday, char *phone_number)
{
	// returns the element that has the same value or the lower...
	node = list_find_less(node, x);

	// duplicada.
	if (node->dado == x)
	{
		// aumentar frequencia
		return false;
	}

	// add element after this one
	celula *nova = malloc(sizeof(celula));
	nova->dado = x;
	nova->prox = node->prox;
	node->prox = nova;
	nova->first_name = strdup(first_name);
	nova->last_name = strdup(last_name);
	nova->birthday = strdup(birthday);
	nova->phone_number = strdup(phone_number);

	return true;
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

/*int list_insert_start (celula *le, int x)
{
	celula *p = list_find(le, x);

	// did not find such element.
	if (p)
		return -1;

	// inserir no começo
	celula *nova = malloc(sizeof(celula));
	nova->dado = x;
	nova->prox = le->prox;
	nova->frequency = 0;
	le->prox = nova;

	return 0;
}*/

int list_remove (celula *p, int x)
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

	free(temp->birthday);
	free(temp->last_name);
	free(temp->first_name);
	free(temp->phone_number);
	return free(temp), true;
}

typedef struct
{
	// NOTE: Professor está errado?... deveria ser uma matriz...
	celula *tb; // tabela hash
	int M; // tamanho da tabela hash
	int N; // total de chaves presentes na tabela
} TH;

int hash_table_position (TH *hash_table, int pos)
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
	{
		hash_table->tb[i].dado = INT_MIN;
		hash_table->tb[i].prox = NULL;
		hash_table->tb[i].phone_number = NULL;
		hash_table->tb[i].birthday = NULL;
		hash_table->tb[i].first_name = NULL;
		hash_table->tb[i].last_name = NULL;
	}

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

// true se foi inserido
// falso se falhou
bool hash_table_insert (TH *h, int ch, char *first_name, char *last_name, char *birthday, char *phone_number)
{
	const int pos = hash_table_position(h, ch);
	if (list_insert(&h->tb[pos], ch, first_name, last_name, birthday, phone_number))
		return ++h->N, true;
	return false;
}

// true se foi removido
// falso se falhou (não encontrou)
bool hash_table_remove (TH *h, int ch)
{
	const int pos = hash_table_position(h, ch);
	if (list_remove(&h->tb[pos], ch))
		return --h->N, true;
	return false;
}

// retorna NULL se não encontrar
celula * hash_table_find_id (TH *h, int ch)
{
	const int pos = hash_table_position(h, ch);
	return list_find(&h->tb[pos], ch);
}

celula *hash_table_find_characteristic (TH *h, char *first_name, char *last_name, char *birthday, char *phone_number)
{
	celula *temp = NULL,
		   *ans = malloc(sizeof(celula)),
		   *node = NULL;
	ans->dado = INT_MIN;
	ans->birthday = NULL;
	ans->first_name = NULL;
	ans->last_name = NULL;
	ans->phone_number = NULL;
	ans->prox = NULL;
	node = ans;

	for (int i = 0; i < h->M; ++i)
	{
		temp = h->tb + i;
		temp = temp->prox; // move out of head
		while (temp)
		{
			if (first_name[0] && first_name && strcmp(first_name, temp->first_name))
			{
				temp = temp->prox;
				continue;
			}

			if (last_name[0] && last_name && strcmp(last_name, temp->last_name))
			{
				temp = temp->prox;
				continue;
			}

			if (birthday[0] && temp->birthday && strcmp(birthday, temp->birthday))
			{
				temp = temp->prox;
				continue;
			}

			if (phone_number[0] && phone_number && strcmp(phone_number, temp->phone_number))
			{
				temp = temp->prox;
				continue;
			}

			node->prox = malloc(sizeof(celula));
			node->first_name = NULL;
			node->last_name = NULL;
			node->birthday = NULL;
			node->phone_number = NULL;

			node = node->prox;
			node->dado = temp->dado;
			node->prox = NULL;
			// printf("2. chegou aqui %d\n", temp->dado);
			temp = temp->prox;
		}
	}
	return ans;
}

/*int hash_table_biggest_frequency(TH *h)
{
	int number = -1, frequency = -1;
	for (int i = 0; i < h->M; ++i)
	{
		celula *node = h->tb + i;
		while (node)
		{
			if (node->frequency > frequency)
			{
				number = node->dado;
				frequency = node->frequency;
			}
			node = node->prox;
		}
	}
	return number;
}*/

#define NAME 1000

int main(void)
{
	int id;
	char command[5],
		 query[NAME],
		 first_name[NAME],
		 last_name[NAME],
		 birth_day[NAME],
		 phone_number[NAME];

	char *string = NULL,
		 *token  = NULL,
		 *tofree = NULL,
		 fn[NAME],
		 ln[NAME],
		 bd[NAME],
		 pn[NAME];

	celula *node = NULL;

	TH *hash_table = hash_table_create(24593);

	while (scanf("%s", command) != EOF)
	{
		// scanf("%*c"); // limpar espaço.
		switch (command[0])
		{
			// add
			case 'a':
				scanf("%d %s %s %s %s", &id, first_name, last_name, birth_day, phone_number);
				if (!hash_table_insert(hash_table, id, first_name, last_name, birth_day, phone_number))
					printf("ID %d ja cadastrado.\n", id);
			break;

			// del
			case 'd':
				scanf("%d", &id);
				if (!hash_table_remove(hash_table, id))
					printf("ID %d nao existente.\n", id);
			break;

			// info
			case 'i':
				scanf("%d", &id);
				node = hash_table_find_id(hash_table, id);
				if (!node)
				{
					printf("ID %d nao existente.\n", id);
					continue;
				}
				printf("%s %s %s %s\n", node->first_name, node->last_name, node->birthday, node->phone_number);
			break;
			// query
			case 'q':
				fgets(query, NAME, stdin);
				query[strlen(query) - 1] = '\0'; // clear \n
				string = strdup(query);

				if (string[0])
				{
					while ((token = strsep(&string, " ")) != NULL)
					{
						switch (token[0])
						{
							// fn: Primeiro nome
							case 'f':
								strcpy(fn, token + 3);
							break;
							// ln: Ultimo nome
							case 'l':
								strcpy(ln, token + 3);
							break;
							// bd: Data de nascimento
							case 'b':
								strcpy(bd, token + 3);
							break;
							// pn: Telefone
							case 'p':
								strcpy(pn, token + 3);
							break;
						}
					}
					free(tofree);
					// printf("fn [%s] ln [%s] bd [%s] pn [%s]\n", fn, ln, bd, pn);
					node = hash_table_find_characteristic(hash_table, fn, ln, bd, pn);
					list_print(node);

					fn[0] = '\0';
					ln[0] = '\0';
					bd[0] = '\0';
					pn[0] = '\0';
					list_destroy_simple_list(node);
				}

			break;

		}
	}
	// hash_table_destroy(hash_table);
}
