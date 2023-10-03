#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct cell_person
{
	int id;
	char *first_name;
	char *last_name;
	char *birthday;
	char *phone_number;
	struct cell_person *next;
} cell_person;

// Frees the list from node until NULL (all data).
void list_destroy (cell_person *node)
{
	cell_person *temp = node;
	while (temp)
	{
		node = temp;
		temp = temp->next;
		free(node->birthday);
		free(node->last_name);
		free(node->first_name);
		free(node->phone_number);
		free(node);
	}
}

// Print the list from node until NULL.
void list_print (cell_person *node)
{
	while (node)
		printf("%d -> ", node->id),
		node = node->next;
	puts("NULL");
}

// Returns the element we want OR where it should be on the list.
cell_person *list_find_less (cell_person *node, int id)
{
	while (node && node->next && node->next->id <= id)
		node = node->next;
	return node;
}

// Returns the element before the element we want or NULL.
cell_person *list_find_before (cell_person *node, int id)
{
	while (node && node->next && node->next->id != id)
		node = node->next;
	return node;
}

cell_person *list_copy_item (cell_person *item)
{
	cell_person *fresh = calloc(1, sizeof(cell_person));
	fresh->id = item->id;
	fresh->birthday = strdup(item->birthday);
	fresh->first_name = strdup(item->first_name);
	fresh->last_name = strdup(item->last_name);
	fresh->phone_number = strdup(item->phone_number);
	return fresh->next = NULL, fresh;
}

// Insert in order by ID.
//   Pointer to element if successfully inserted.
//   NULL if failed.
cell_person *list_insert (cell_person *node, cell_person *item)
{
	// Returns the element that has the same value or the lower...
	node = list_find_less(node, item->id);

	// Duplicated.
	if (node->id == item->id)
		return NULL;

	// Add element after the onde found.
	return node->next = list_copy_item(item), node->next;
}

void list_delete (cell_person *node)
{
	// free(node->birthday);
	// free(node->last_name);
	// free(node->first_name);
	// free(node->phone_number);
	free(node);
}

// Pointer to element if succesfully removed from list.
// NULL if failed.
cell_person *list_remove (cell_person *node, int id)
{
	node = list_find_before(node, id);

	// Did not find such element.
	if (!node)
		return NULL;

	cell_person *temp = node->next;

	if (node->next->next)
		node->next = node->next->next;
	else
		node->next = NULL;

	return temp;
}

bool list_empty (cell_person *head)
{
	return head == NULL;
}

// Returns the element or NULL.
cell_person *list_find (cell_person *node, int id)
{
	while (node && node->id != id)
		node = node->next;
	return node;
}

/*
 * Hash table for people.
 * Hash IDs (integer) by hash modular function.
 */

typedef struct
{
	cell_person **table; // Hash table.
	int N; // Total of all keys in the table.
} hash_table_person;

#define M 12289

int hash_table_position (int pos)
{
	return pos % M;
}

hash_table_person *hash_table_person_create ()
{
	hash_table_person *hash_table = calloc(1, sizeof(hash_table_person));
	*hash_table = (hash_table_person){.N = 0, .table = calloc(M, sizeof(cell_person *))};
	for (int i = 0; i < M; ++i)
		hash_table->table[i] = NULL;
	return hash_table;
}

void hash_table_person_destroy (hash_table_person *h)
{
	for (int i = 0; i < M; ++i)
		list_destroy(h->table[i]);
	free(h->table);
	free(h);
}

void hash_table_print (hash_table_person *h)
{
	printf("Hash Table Person | M = %u | N = %d\n", M, h->N);
	for (int i = 0; i < M; ++i)
		if (h->table[i])
		{
			printf(" - Key %d => ", i),
			list_print(h->table[i]);
		}
}

// Pointer to element if succesfully inserted.
// NULL if failed.
cell_person *hash_table_insert (hash_table_person *h, cell_person *item)
{
	const int pos = hash_table_position(item->id);

	if (list_empty(h->table[pos]))
	{
		++h->N;
		return h->table[pos] = list_copy_item(item), h->table[pos];
	}

	cell_person *element = list_insert(h->table[pos], item);
	if (element)
		return ++h->N, element;

	return NULL;
}

// True if succesfully removed.
// False if failed (didn't find).
cell_person *hash_table_remove (hash_table_person *h, cell_person *item)
{
	const int pos = hash_table_position(item->id);

	// If it is on the head and there isn't anything more than it.
	if (!list_empty(h->table[pos]) && h->table[pos]->id == item->id && list_empty(h->table[pos]->next))
	{
		cell_person *temp = h->table[pos];
		--h->N;
		return h->table[pos] = NULL, temp;
	}

	cell_person *temp = list_remove(h->table[pos], item->id);
	if (temp)
		--h->N;

	return temp;
}

// Returns the element or NULL if did not find.
cell_person *hash_table_find_id (hash_table_person *h, int id)
{
	return list_find(h->table[hash_table_position(id)], id);
}

/*
 * Hash table for string.
 */

typedef struct cell
{
	int id; // The ID itsel.f
	char *string; // What is used for the hash
	cell_person *person; // All we need is the pointer to the node.
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
		// printf("[%d] -> ", node->id),
		printf("[%s] -> ", node->string),
		node = node->next;
	puts("NULL");
}

// Returns the element we want OR where it should be on the list.
cell *list_string_find_less (cell *node, int id)
{
	while (node && node->next && node->next->id <= id)
		node = node->next;
	return node;
}

// Returns the element before the element we want or NULL.
cell *list_string_find_before (cell *node, int id)
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
bool list_string_remove (cell *node, int id)
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
	int N; // Total of all keys in the table.
} hash_table_string;

#define P 257

// Polynomial Rolling Hash.
int hash_string_position (char *string, char *fixed)
{
	int hash = 0;
	for (int i = 0; string[i]; ++i)
		hash = (hash * P) % M,
		hash = (hash + (int)fixed[i] + 1) % M;
	return hash;
}

hash_table_string *hash_table_string_create ()
{
	hash_table_string *hash_table = calloc(1, sizeof(hash_table_string));
	*hash_table = (hash_table_string){.N = 0, .table = calloc(M, sizeof(cell *))};
	for (int i = 0; i < M; ++i)
		hash_table->table[i] = NULL;
	return hash_table;
}

void hash_table_string_destroy (hash_table_string *h)
{
	for (int i = 0; i < M; ++i)
		list_string_destroy(h->table[i]);
	free(h->table);
	free(h);
}

void hash_table_string_print (hash_table_string *h)
{
	printf("Hash Table String | M = %u | N = %d\n", M, h->N);
	for (int i = 0; i < M; ++i)
		if (h->table[i])
		{
			printf(" - Key %d => ", i),
			list_string_print(h->table[i]);
		}
}

// True if succesfully inserted.
// False if failed.
bool hash_table_string_insert (hash_table_string *h, cell *item)
{
	const int pos = hash_string_position(item->string);

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
	const int pos = hash_string_position(item->string);

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
void hash_table_print_query (hash_table_string *h, char *string, cell_person *match)
{
	const int pos = hash_string_position(string);
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

		printf("%d ", node->id);
	}
	putchar('\n');
}

void hash_table_find_characteristic (register hash_table_person *h, register cell_person *match)
{
	register cell_person *temp;

	for (int i = 0; i < M; ++i)
	{
		temp = h->table[i];
		for (; temp; temp = temp->next)
		{
			if (match->first_name[0] && temp->first_name[0] && strcmp(match->first_name, temp->first_name))
				continue;

			if (match->last_name[0] && temp->last_name[0] && strcmp(match->last_name, temp->last_name))
				continue;

			if (match->birthday[0] && temp->birthday[0] && strcmp(match->birthday, temp->birthday))
				continue;

			if (match->phone_number[0] && temp->phone_number[0] && strcmp(match->phone_number, temp->phone_number))
				continue;

			printf("%d ", temp->id);
		}
	}
	putchar('\n');
}

#define NAME 200

int main(void)
{
	char command[7];
	char query[NAME * 2];

	char *string = NULL,
		 *token  = NULL;

	hash_table_person *hash_table = hash_table_person_create();
	hash_table_string *hash_first_name = hash_table_string_create();
	hash_table_string *hash_last_name = hash_table_string_create();
	hash_table_string *hash_birthday = hash_table_string_create();
	hash_table_string *hash_phone_numer = hash_table_string_create();

	/* add a few things... */
	cell_person *person = calloc(1, sizeof(cell_person));
	*person = (cell_person){
		.id = 0,
		.next = NULL,
		.first_name = calloc(1, sizeof(char) * NAME),
		.last_name = calloc(1, sizeof(char) * NAME),
		.birthday = calloc(1, sizeof(char) * NAME),
		.phone_number = calloc(1, sizeof(char) * NAME),
	};
	cell_person *ptemp;
	cell *scell = calloc(1, sizeof(cell));

	while (scanf("%s", command) != EOF)
	{
		switch (command[0])
		{
			// add
			case 'a':
				scanf("%d %s %s %s %s", &person->id, person->first_name, person->last_name, person->birthday, person->phone_number);
				ptemp = hash_table_insert(hash_table, person);
				if (!ptemp)
				{
					printf("ID %d ja cadastrado.\n", person->id);
					break;
				}
				scell->person = ptemp;
				scell->id = ptemp->id;

				// First name.
				scell->string = ptemp->first_name;
				hash_table_string_insert(hash_first_name, scell);

				// Last name.
				scell->string = ptemp->last_name;
				hash_table_string_insert(hash_last_name, scell);

				// Birthday.
				scell->string = ptemp->birthday;
				hash_table_string_insert(hash_birthday, scell);

				// Phone number.
				scell->string = ptemp->phone_number;
				hash_table_string_insert(hash_phone_numer, scell);
			break;

			// del
			case 'd':
				scanf("%d", &person->id);
				ptemp = hash_table_remove(hash_table, person);
				if (!ptemp)
				{
					printf("ID %d nao existente.\n", person->id);
					break;
				}

				scell->id = ptemp->id;

				scell->string = ptemp->first_name,
				hash_table_string_remove(hash_first_name, scell);

				scell->string = ptemp->last_name,
				hash_table_string_remove(hash_last_name, scell);

				scell->string = ptemp->birthday,
				hash_table_string_remove(hash_birthday, scell);

				scell->string = ptemp->phone_number,
				hash_table_string_remove(hash_phone_numer, scell);
			break;

			// info
			case 'i':
				scanf("%d", &person->id);
				ptemp = hash_table_find_id(hash_table, person->id);
				if (!ptemp)
				{
					printf("ID %d nao existente.\n", person->id);
					continue;
				}
				printf("%s %s %s %s\n", ptemp->first_name, ptemp->last_name, ptemp->birthday, ptemp->phone_number);
			break;

			// query
			case 'q':
				scanf("%*c");
				fgets(query, NAME * 2, stdin);
				query[strlen(query) - 1] = '\0'; // clear \n
				string = strdup(query);

				if (string[0])
				{
					person->first_name[0]   = '\0';
					person->last_name[0]    = '\0';
					person->birthday[0]     = '\0';
					person->phone_number[0] = '\0';

					while ((token = strsep(&string, " ")) != NULL)
					{
						switch (token[0])
						{
							// fn: Primeiro nome
							case 'f':
								strcpy(person->first_name, token + 3);
							break;
							// ln: Ultimo nome
							case 'l':
								strcpy(person->last_name, token + 3);
							break;
							// bd: Data de nascimento
							case 'b':
								strcpy(person->birthday, token + 3);
							break;
							// pn: Telefone
							case 'p':
								strcpy(person->phone_number, token + 3);
							break;
						}
					}
					
					// hash_table_find_characteristic(hash_table, person);

					if (person->first_name[0])
						hash_table_print_query(hash_first_name, person->first_name, person);
					else if (person->last_name[0])
						hash_table_print_query(hash_last_name, person->last_name, person);
					else if (person->birthday[0])
						hash_table_print_query(hash_birthday, person->birthday, person);
					else if (person->phone_number[0])
						hash_table_print_query(hash_phone_numer, person->phone_number, person);

					person->first_name[0] =
					person->last_name[0] =
					person->birthday[0] =
					person->phone_number[0] = '\0';
				}
				free(string);

			break;

			default:
				break;

		}
	}
	// hash_table_string_print(hash_first_name);
	// hash_table_string_print(hash_last_name);
	// hash_table_string_print(hash_birthday);
	// hash_table_string_print(hash_phone_numer);
	// putchar('\n');
	// hash_table_print(hash_table);

	// hash_table_string_destroy(hash_first_name);
	// hash_table_string_destroy(hash_last_name);
	// hash_table_string_destroy(hash_birthday);
	// hash_table_string_destroy(hash_phone_numer);
	// hash_table_person_destroy(hash_table);
	// list_destroy(person);
	// list_string_delete(scell);
}
