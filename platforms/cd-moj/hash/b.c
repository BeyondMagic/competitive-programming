#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

typedef struct celula
{
	unsigned dado; // id
	char *first_name;
	char *last_name;
	char *birthday;
	char *phone_number;
	struct celula *prox;
} celula;

// Frees the list from node until NULL (only data).
void list_destroy_simple_list (register celula *node)
{
	register celula *temp = node;
	while (temp)
	{
		node = temp;
		temp = temp->prox;
		// free(node);
	}
}

// Frees the list from node until NULL (all data).
void list_destroy (register celula *node)
{
	register celula *temp = node;
	while (temp)
	{
		node = temp;
		temp = temp->prox;
		// free(node->birthday);
		// free(node->last_name);
		// free(node->first_name);
		// free(node->phone_number);
		// free(node);
	}
}

// Print the list from node until NULL.
void list_print (register celula *node)
{
	while (node)
	{
		printf("%u", node->dado);
		if (node->prox)
			putchar(' ');
		node = node->prox;
	}
	putchar('\n');
}

// Returns the element we want OR where it should be on the list.
celula *list_find_less (register celula *node, register unsigned x)
{
	while (node && node->prox && node->prox->dado <= x)
		node = node->prox;
	return node;
}

// Returns the element before the element we want or NULL.
celula *list_find_before (register celula *node, register unsigned x)
{
	while (node && node->prox && node->prox->dado != x)
		node = node->prox;
	return node;
}

// Returns the element or NULL.
celula *list_find (register celula *le, register unsigned x)
{
	while (le && le->dado != x)
		le = le->prox;
	return le;
}

// True if successfully inserted.
// False if failed.
bool list_insert (register celula *node, register unsigned x, register char *first_name, register char *last_name, register char *birthday, register char *phone_number)
{
	// returns the element that has the same value or the lower...
	node = list_find_less(node, x);

	// duplicada.
	if (node->dado == x)
		return false;

	// add element after this one
	register celula *nova = malloc(sizeof(celula));
	*nova = (celula){.dado = x, .prox = node->prox, .first_name = strdup(first_name), .last_name = strdup(last_name), .birthday = strdup(birthday), .phone_number = strdup(phone_number) };

	return node->prox = nova, true;
}

// True if succesfully removed.
// False if failed.
bool list_remove (register celula *p, register unsigned x)
{
	p = list_find_before(p, x);

	// Did not find such element.
	if (!p)
		return false;

	// celula *temp = p->prox;
	if (p->prox->prox)
		p->prox = p->prox->prox;
	else
		p->prox = NULL;

	return true;
	// free(temp->birthday);
	// free(temp->last_name);
	// free(temp->first_name);
	// free(temp->phone_number);
	// return free(temp), true;
}

typedef struct
{
	celula **tb; // Hash table.
	size_t N; // Total of all keys in the table.
} TH;

// #define M 1572869
#define M 100019

#define hash_table_position(pos) pos % M

TH hash_table_create ()
{
	register TH hash_table = {.N = 0 };
	hash_table.tb = malloc(M * sizeof(celula *));
	for (register size_t i = 0; i < M; ++i)
		hash_table.tb[i] = NULL;
	return hash_table;
}

void hash_table_print (register TH *hash_table)
{
	printf("Hash Table | M = %u | N = %zu\n", M, hash_table->N);
	for (register unsigned i = 0; i < M; ++i)
	{
		if (hash_table->tb[i])
		{
			printf(" - Key %u => ", i),
			list_print(hash_table->tb[i]);
		}
	}
}

// True if succesfully inserted.
// False if failed.
bool hash_table_insert (register TH *h, register unsigned ch, register char *first_name, register char *last_name, register char *birthday, register char *phone_number)
{
	register const unsigned pos = hash_table_position(ch);

	// head, or the first element
	if (!h->tb[pos])
	{
		h->tb[pos] = malloc(sizeof(celula));
		*h->tb[pos] = (celula){.dado = ch, .prox = NULL, .first_name = strdup(first_name), .last_name = strdup(last_name), .birthday = strdup(birthday), .phone_number = strdup(phone_number) };
		++h->N;
		return true;
	}

	if (list_insert(h->tb[pos], ch, first_name, last_name, birthday, phone_number))
		return ++h->N, true;
	return false;
}

// True if succesfully removed.
// False if failed (didn't find).
bool hash_table_remove (register TH *h, register unsigned ch)
{
	register const unsigned pos = hash_table_position(ch);

	// If it is on the head and there isn't anything more than it.
	if (h->tb[pos] && h->tb[pos]->dado == ch && !h->tb[pos]->prox)
	{
		// free(h->tb[pos]->birthday);
		// free(h->tb[pos]->last_name);
		// free(h->tb[pos]->first_name);
		// free(h->tb[pos]->phone_number);
		// free(h->tb[pos]);
		h->tb[pos] = NULL;
		return true;
	}

	if (list_remove(h->tb[pos], ch))
		return --h->N, true;
	return false;
}

// Returns the element or NULL if did not find.
celula * hash_table_find_id (register TH *h, register unsigned ch)
{
	return list_find(h->tb[hash_table_position(ch)], ch);
}

void hash_table_find_characteristic (register TH *h, register char *first_name, register char *last_name, register char *birthday, register char *phone_number)
{
	register celula *temp;

	// FIXIT: MEU TLE TA AQUI, eu TO PESQUISANDO EM TUDO AO INVES DE USAR HASH PARA CADA CHAVE DA QUERY...
	for (size_t i = 0; i < M; ++i)
	{
		temp = h->tb[i];
		for (; temp; temp = temp->prox)
		{
			if (first_name[0] && first_name && strcmp(first_name, temp->first_name))
				continue;

			if (last_name[0] && last_name && strcmp(last_name, temp->last_name))
				continue;

			if (birthday[0] && temp->birthday && strcmp(birthday, temp->birthday))
				continue;

			if (phone_number[0] && phone_number && strcmp(phone_number, temp->phone_number))
				continue;

			printf("%d ", temp->dado);
		}
	}
	putchar('\n');
}

/*
 * Hash table for string.
 */

typedef struct cell
{
	size_t id; // The ID itsel.f
	char *string; // What is used for the hash
	celula *person; // All we need is the pointer to the node.
	struct cell *next;
} cell;

// Frees the list from node until NULL (all data).
void list_string_destroy (cell *node)
{
	cell *temp = node;
	while (temp)
	{
		node = temp;
		temp = temp->next;
		free(node->string);
		free(node);
	}
}

// Print the list from node until NULL.
void list_string_print (cell *node)
{
	while (node)
		// printf("[%zu] -> ", node->id),
		printf("[%s] -> ", node->string),
		node = node->next;
	puts("NULL");
}

// Returns the element we want OR where it should be on the list.
cell *list_string_find_less (cell *node, size_t id)
{
	while (node && node->next && node->next->id <= id)
		node = node->next;
	return node;
}

// Returns the element before the element we want or NULL.
cell *list_string_find_before (cell *node, size_t id)
{
	while (node && node->next && node->next->id != id)
		node = node->next;
	return node;
}

cell *list_string_copy_item (cell *item)
{
	cell *fresh = calloc(1, sizeof(cell));
	fresh->string = strdup(item->string);
	fresh->id = item->id;
	fresh->person = item->person;
	return fresh->next = NULL, fresh;
}

// Insert in order by ID.
//   Pointer to element if successfully inserted.
//   NULL if failed.
cell *list_string_insert (cell *node, cell *item)
{
	// Returns the element that has the same value or the lower...
	node = list_string_find_less(node, item->id);

	// Duplicated.
	if (node->id == item->id)
	{
		puts("DUPLICADO");
		return NULL;
	}

	// Add element after the onde found.
	cell *temp = list_string_copy_item(item);
	temp->next = node->next;
	node->next = temp;
	return node->next;
}

void list_string_delete (cell *node)
{
	free(node->string);
	free(node);
}

// True if succesfully removed.
// False if failed.
bool list_string_remove (cell *node, size_t id)
{
	node = list_string_find_before(node, id);

	// Did not find such element.
	if (!node)
		return false;

	cell *temp = node->next;

	if (node->next->next)
		node->next = node->next->next;
	else
		node->next = NULL;

	return list_string_delete(temp), true;
}

bool list_string_empty (cell *head)
{
	return head == NULL;
}

typedef struct
{
	cell **table; // Hash table.
	size_t N; // Total of all keys in the table.
} hash_table_string;

#define P 257

// Polynomial Rolling Hash.
size_t hash_string_position (char *string)
{
	size_t hash = 0;
	for (size_t i = 0; string[i]; ++i)
		hash = (hash * P) % M,
		hash = (hash + (size_t)string[i] + 1) % M;
	return hash;
}

hash_table_string *hash_table_string_create ()
{
	hash_table_string *hash_table = calloc(1, sizeof(hash_table_string));
	*hash_table = (hash_table_string){.N = 0, .table = calloc(M, sizeof(cell *))};
	for (size_t i = 0; i < M; ++i)
		hash_table->table[i] = NULL;
	return hash_table;
}

void hash_table_string_destroy (hash_table_string *h)
{
	for (size_t i = 0; i < M; ++i)
		list_string_destroy(h->table[i]);
	free(h->table);
	free(h);
}

void hash_table_string_print (hash_table_string *h)
{
	printf("Hash Table String | M = %u | N = %zu\n", M, h->N);
	for (size_t i = 0; i < M; ++i)
		if (h->table[i])
		{
			printf(" - Key %zu => ", i),
			list_string_print(h->table[i]);
		}
}

// True if succesfully inserted.
// False if failed.
bool hash_table_string_insert (hash_table_string *h, cell *item)
{
	const size_t pos = hash_string_position(item->string);

	if (list_string_empty(h->table[pos]))
	{
		++h->N;
		return h->table[pos] = list_string_copy_item(item), true;
	}

	// It's the head and the ID is less.
	if (list_string_empty(h->table[pos]->next) && h->table[pos]->id > item->id)
	{
		cell *temp = list_string_copy_item(item);
		temp->next = h->table[pos];
		h->table[pos] = temp;
		return ++h->N, true;
	}

	if (list_string_insert(h->table[pos], item))
		return ++h->N, true;

	return false;
}

// True if succesfully removed.
// False if failed (didn't find).
bool hash_table_string_remove (hash_table_string *h, cell *item)
{
	const size_t pos = hash_string_position(item->string);

	// If it is on the head and there isn't anything more than it.
	if (!list_string_empty(h->table[pos])
			&& h->table[pos]->id == item->id)
	{
		--h->N;

		if (list_string_empty(h->table[pos]->next))
		{
			list_string_delete(h->table[pos]);
			return h->table[pos] = NULL, true;
		}

		cell *temp = h->table[pos];
		h->table[pos] = temp->next;
		return list_string_delete(temp), true;
	}

	if (list_string_remove(h->table[pos], item->id))
		return --h->N, true;
	return false;
}

// Returns the element or NULL if did not find.
void hash_table_print_query (hash_table_string *h, char *string, celula *match)
{
	const size_t pos = hash_string_position(string);
	cell *node = h->table[pos];
	for (; node; node = node->next)
	{
		// First name was needed for query and is not the same.
		if (match->first_name[0] && strcmp(match->first_name, node->person->first_name))
			continue;

		// Last name was needed for query and is not the same.
		if (match->last_name[0] && strcmp(match->last_name, node->person->last_name))
			continue;

		// Birthday was needed for query and is not the same.
		if (match->birthday[0] && strcmp(match->birthday, node->person->birthday))
			continue;

		// Phone number was needed for query and is not the same.
		if (match->phone_number[0] && strcmp(match->phone_number, node->person->phone_number))
			continue;

		printf("%zu ", node->id);
	}
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

#define NAME 101

int main(void)
{
	unsigned id;
	char command[5],
		 query[70 * 2],
		 first_name[70],
		 last_name[70],
		 birth_day[70],
		 phone_number[70];

	char *string = NULL,
		 *token  = NULL,
		 fn[70],
		 ln[70],
		 bd[70 / 4],
		 pn[70 / 4];

	register celula *node = NULL;

	TH hash_table = hash_table_create();
	hash_table_string *hash_first_name = hash_table_string_create();
	hash_table_string *hash_last_name = hash_table_string_create();
	hash_table_string *hash_birthday = hash_table_string_create();
	hash_table_string *hash_phone_numer = hash_table_string_create();

	while (scanf("%s", command) != EOF)
	{
		// scanf("%*c"); // limpar espaço.
		switch (command[0])
		{
			// add
			case 'a':
				scanf("%u %s %s %s %s", &id, first_name, last_name, birth_day, phone_number);
				if (!hash_table_insert(&hash_table, id, first_name, last_name, birth_day, phone_number))
					printf("ID %d ja cadastrado.\n", id);
			break;

			// del
			case 'd':
				scanf("%u", &id);
				if (!hash_table_remove(&hash_table, id))
					printf("ID %d nao existente.\n", id);
			break;

			// info
			case 'i':
				scanf("%u", &id);
				node = hash_table_find_id(&hash_table, id);
				if (!node)
				{
					printf("ID %d nao existente.\n", id);
					continue;
				}
				printf("%s %s %s %s\n", node->first_name, node->last_name, node->birthday, node->phone_number);
			break;

			// query
			case 'q':
				scanf("%*c");
				fgets(query, 70 * 2, stdin);
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
					// printf("fn [%s] ln [%s] bd [%s] pn [%s]\n", fn, ln, bd, pn);
					hash_table_find_characteristic(&hash_table, fn, ln, bd, pn);
					// list_print(node);

					fn[0] = '\0';
					ln[0] = '\0';
					bd[0] = '\0';
					pn[0] = '\0';
					// list_destroy_simple_list(node);
				}
				// free(string);

			break;

			default:
				break;

		}
	}
	// hash_table_print(&hash_table);
	// hash_table_destroy(hash_table);
}
