#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define NAME 70
#define P 257
#define M 100019

typedef struct cell_person
{
	int id;
	char first_name[NAME];
	char last_name[NAME];
	char birthday[NAME];
	char phone_number[NAME];
} cell_person;

typedef struct cell
{
	cell_person item;
	struct cell *next;
} cell;

typedef struct cell_head
{
	int size;
	cell *first;
} cell_head;

cell_head *cell_head_init()
{
	cell_head *new = malloc(sizeof(cell_head));
	new->size = 0;
	new->first = NULL;
	return new;
}
cell *cell_init()
{
	cell *new = malloc(sizeof(cell));
	new->next = NULL;
	return new;
}

bool list_push(cell_head *head, cell_person x)
{
	cell *new = cell_init();
	new->item = x;
	if (!head->size)
	{
		head->first = new;
		return ++head->size, false;
	}
	cell *cur = head->first;
	cell *prev = NULL;
	while (cur)
	{
		if (cur->item.id == new->item.id)
			return true;
		if (cur->item.id > new->item.id)
			break;
		prev = cur;
		cur = cur->next;
	}
	if (!prev)
	{
		new->next = cur;
		head->first = new;
		return ++head->size, false;
	}

	if (!cur)
	{
		prev->next = new;
		return ++head->size, false;
	}

	prev->next = new;
	new->next = cur;
	return ++head->size, false;
}

bool list_remove(cell_head *head, cell_person x)
{
	cell *cur = head->first;
	cell *prev = NULL;
	while (cur)
	{
		if (cur->item.id ==  x.id)
			break;
		if (cur->item.id > x.id)
			return true;
		prev = cur;
		cur = cur->next;
	}

	if (!cur)
		return true;

	if (prev)
	{
		prev->next = cur->next;
		return --head->size, false;
	}
	else
	{
		head->first = cur->next;
		return --head->size, false;
	}
}

bool list_find_close(cell_head *head, cell_person x)
{
	cell *cur = head->first;
	while (cur)
	{
		if (cur->item.id == x.id)
			return true;
		if (cur->item.id > x.id)
			break;
		cur = cur->next;
	}
	return 0;
}

cell_person *list_find_by_id(cell_head *head, int id)
{
	cell *cur = head->first;
	while (cur)
	{
		if (cur->item.id == id)
			return &(cur->item);
		cur = cur->next;
	}
	return NULL;
}

typedef struct Hash_Table
{
	int mod;
	int size;
	int k;
	int (*hash_func)(cell_person);
	cell_head *table;
} Hash_Table;

int f(char c) { return c + 1; }

int hash_first_name(cell_person x)
{
	int h = 0;
	for (int i = 0; x.first_name[i++]; )
		h = (h * P) % M,
		h = (h + x.first_name[i] + 1) % M;
	return h;
}
int hash_last_name(cell_person x)
{
	int h = 0;
	for (int i = 0; x.last_name[i++];)
		h = (h * P) % M,
		h = (h + f(x.last_name[i])) % M;
	return h;
}
int hash_birthday(cell_person x)
{
	int h = 0;
	for (int i = 0; x.birthday[i++];)
		h = (h * P) % M,
		h = (h + f(x.birthday[i])) % M;
	return h;
}
int hash_phone_number(cell_person x)
{
	int h = 0;
	for (int i = 0; x.phone_number[i++];)
		h = (h * P) % M,
		h = (h + f(x.phone_number[i])) % M;
	return h;
}

int hash_id (cell_person x)
{
	return x.id % M;
}

Hash_Table *hash_table_create(int (*hash_func)(cell_person))
{
	Hash_Table *new = malloc(sizeof(Hash_Table));
	new->size = 0;
	new->hash_func = hash_func;
	new->table = calloc(M, sizeof(cell_head));
	return new;
}

bool hash_table_insert(Hash_Table *ht, cell_person x)
{
	return list_push(ht->table + ht->hash_func(x), x);
}

bool hash_table_remove(Hash_Table *ht, cell_person x)
{
	return list_remove(ht->table + ht->hash_func(x), x);
}

bool hash_table_find(Hash_Table *ht, cell_person x)
{
	return list_find_close(ht->table + ht->hash_func(x), x);
}

cell_person *hash_table_find_by_id(Hash_Table *ht, cell_person x)
{
	return list_find_by_id(ht->table + ht->hash_func(x), x.id);
}

void ht_query(Hash_Table *ht, cell_person x)
{
	int pos = ht->hash_func(x);

	for (cell *cur = ht->table[pos].first; cur; cur = cur->next)
	{
		if (x.id && cur->item.id != x.id)
			break;

		if (x.first_name[0] && strcmp(cur->item.first_name, x.first_name))
			continue;

		if (x.last_name[0] && strcmp(cur->item.last_name, x.last_name))
			continue;

		if (x.birthday[0] && strcmp(cur->item.birthday, x.birthday))
			continue;

		if (x.phone_number[0] && strcmp(cur->item.phone_number, x.phone_number))
			continue;

		printf("%d", cur->item.id);
		if (cur->next)
			putchar(' ');
	}
	putchar('\n');
}

int main(void)
{
	char cmd[6];
	Hash_Table *ht_first_name = hash_table_create(hash_first_name);
	Hash_Table *ht_last_name = hash_table_create(hash_last_name);
	Hash_Table *ht_birthday = hash_table_create(hash_birthday);
	Hash_Table *ht_phone_number = hash_table_create(hash_phone_number);
	Hash_Table *ht_id = hash_table_create(hash_id);

	while (scanf("%s", cmd) != EOF)
	{
		int id;
		cell_person cur;
		cell_person *found;
		switch (*cmd)
		{
			// Case Ad
			case 'a':
				scanf("%d %s %s %s %s", &cur.id, cur.first_name, cur.last_name, cur.birthday, cur.phone_number);
				if (hash_table_find_by_id(ht_id, cur))
				{
					printf("ID %d ja cadastrado.\n", cur.id);
					break;
				}
				hash_table_insert(ht_first_name, cur);
				hash_table_insert(ht_last_name, cur);
				hash_table_insert(ht_birthday, cur);
				hash_table_insert(ht_phone_number, cur);
				hash_table_insert(ht_id, cur);
				break;

			// Delete.
			case 'd':
				scanf("%d", &id);
				cur.id = id;
				found = hash_table_find_by_id(ht_id, cur);
				if (found == NULL)
				{
					printf("ID %d nao existente.\n", id);
					break;
				}
				hash_table_remove(ht_first_name, *found);
				hash_table_remove(ht_last_name, *found);
				hash_table_remove(ht_birthday, *found);
				hash_table_remove(ht_phone_number, *found);
				hash_table_remove(ht_id, *found);
				break;

			// Info
			case 'i':
				scanf("%d", &id);
				cur.id = id;
				found = hash_table_find_by_id(ht_id, cur);
				if (found == NULL)
				{
					printf("ID %d nao existente.\n", id);
					break;
				}
				printf("%s %s %s %s\n", found->first_name, found->last_name, found->birthday, found->phone_number);
				break;

			// Query..
			case 'q':
				scanf("%*c");

				char input[NAME * 3 / 2];
				scanf("%[^\n]s", input);

				cell_person match = {0, {0}, {0}, {0}, {0}};
				char *cur = strtok(input, " ");

				while (cur != NULL)
				{
					switch (*cur)
					{

						case 'b':
							strcpy(match.birthday, cur + 3);
							break;

						case 'f':
							strcpy(match.first_name, cur + 3);
							break;

						case 'l':
							strcpy(match.last_name, cur + 3);
							break;

						case 'p':
							strcpy(match.phone_number, cur + 3);
							break;
					}

					cur = strtok(NULL, " ");
				}

				if (*match.first_name)
					ht_query(ht_first_name, match);

				else if (*match.last_name)
					ht_query(ht_last_name, match);

				else if (*match.birthday)
					ht_query(ht_birthday, match);

				else if (*match.phone_number)
					ht_query(ht_phone_number, match);

			default:
				break;
		}
	}
}
