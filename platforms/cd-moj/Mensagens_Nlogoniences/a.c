#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
	unsigned k;
	char v;
} Item;

#define HT_SIZE 1572869u
#define key(a) (a.k)
#define eq(a, b) (a.k == b.k)

#ifdef STRING_HASH
#define INITIAL_HASH_VALUE 5381
#define MULT_HASH_VALUE 33
unsigned hashu(const char *x)
{
	unsigned h = INITIAL_HASH_VALUE;
	for (int i = 0; x[i] != '\0'; i++)
		h = (h * MULT_HASH_VALUE + x[i]) % HT_SIZE;
	return h;
}
#define key_t const char *
#define hash_k(k) (hashu(k))
#define eq_k(x, k) (strcmp(key(x), k) == 0)
#else
#define hash_k(k) (k % HT_SIZE)
#define key_t unsigned
#define eq_k(x, k) (key(x) == k)
#endif

#define hash(x) (hash_k(key(x)))

typedef struct LinkedItem
{
	Item item;
	struct LinkedItem *next;
} LinkedItem;

typedef struct HashTable
{
	unsigned size;
	LinkedItem **v;
} HashTable;

HashTable HT_init (void)
{
	HashTable ht = {.size = 0};
	ht.v = (LinkedItem **)malloc(HT_SIZE * sizeof(LinkedItem *));
	for (unsigned i = 0; i < HT_SIZE; i++)
		ht.v[i] = NULL;
	return ht;
}

int HT_insert(HashTable *ht, Item x)
{
	unsigned h = hash(x);
	if (!ht->v[h])
	{
		ht->v[h] = (LinkedItem *)malloc(sizeof(LinkedItem));
		*ht->v[h] = (LinkedItem){.next = NULL, .item = x};
		return 1;
	}
	LinkedItem *curr = ht->v[h];
	while (curr->next && !eq(curr->item, x))
		curr = curr->next;
	if (eq(curr->item, x))
		return 0;

	curr->next = (LinkedItem *)malloc(sizeof(LinkedItem));
	*curr->next = (LinkedItem){.item = x, .next = NULL};
	ht->size++;
	return 1;
}

LinkedItem *HT_search(HashTable ht, key_t k)
{
	unsigned h = hash_k(k);
	LinkedItem *curr = ht.v[h];
	while (curr)
	{
		if (eq_k(curr->item, k))
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void solve (void)
{
	HashTable ht = HT_init();
	Item item;
	unsigned mn = (unsigned)1 << 31, mx = 0;
	while (scanf(" %u %c", &item.k, &item.v) == 2)
	{
		HT_insert(&ht, item);
		mn = item.k < mn ? item.k : mn;
		mx = item.k > mx ? item.k : mx;
	}

	for (unsigned i = mn; i <= mx; i++)
	{
		LinkedItem *li = HT_search(ht, i);
		if (li)
			printf("%c", li->item.v);
	}
	printf("\n");
}

int main (void)
{
	solve();

	return 0;
}
