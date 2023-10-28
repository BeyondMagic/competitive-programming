#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

typedef struct {
	int *tb; // tabela hash, vazio é -1
	int M; // tamanho da tabela hash
	int N; // total de chaves presentes na tabela
} TH;

int aumentaTamanho (int M);

void hash_table_destroy (TH *hash_table)
{
	free(hash_table->tb);
	free(hash_table);
}

void hash_table_print (TH *hash_table)
{
	printf("Hash Table | M = %d | N = %d\n", hash_table->M, hash_table->N);
	printf("[ ");
	for (int i = 0; i < hash_table->M; ++i)
	{
		if (hash_table->tb[i] == -1)
			putchar('-');
		else
			printf("%d", hash_table->tb[i]);
		putchar(' ');
	}
	puts("]");
}

TH *hash_table_create (int M)
{
	TH *hash_table = malloc(sizeof(TH));
	hash_table->M = M;
	hash_table->N = 0;
	hash_table->tb = malloc((size_t) M * sizeof(int));
	memset(hash_table->tb, EMPTY, sizeof(int) * (size_t)M);

	return hash_table;
}

// 1.
//   implementada aumentaTamanho() que recebe o tamanho atual da tabela hash e retorna o novo tamanho.
//   Esta função deve ser declarada no preâmbulo do seu código.
// 2.
//   fazer busca binaria na tabela para pegar o maior numero depois do M.
int aumentaTamanho1 (int M)
{
	static const int table_primes[] =
	{
		53,
		97,
		193,
		389,
		769,
		1543,
		3079,
		6151,
		12289,
		24593,
		49157,
		98317,
		196613,
		393241,
		786433,
		1572869,
		3145739,
		6291469,
		12582917,
		25165843,
		50331653,
		100663319,
		201326611,
		402653189,
		805306457,
		1610612741,
	};
	static const int size = sizeof(table_primes) / sizeof(table_primes[0]);

	// busca binaria
	int l = 0,
		r = size - 1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (table_primes[m] == m)
			// if it's the last, return itself
			// if not, return next one.
			return m + 1 == size ? M : table_primes[m + 1];

		else if (table_primes[m] < M)
			l = m + 1;
		else
			r = m - 1;
	}

	return l + 1 == size ? M : table_primes[l + 1];
}


// returns position of where it should be,
// if it returns -1, it looped through the entire table and did not found
// if it returns a position, do VERIFY if the element has the same value of the position in case of duplicate.
int hash_array_find (int *tb, const int x, const int M)
{
	const int pos = x % M;
	int left = pos;
	// printf("posicao a ser inserido %d\n", left);
	// 1. encontrar -1
	// 2. depois do && sem chave duplicada
	while (tb[left] != EMPTY && tb[left] != x)
	{
		++left;
		left %= M;
		// deu um loop completo, nao tem mais espaco
		// nao deveria acontecer
		if (left == pos)
			return -1;
	}
	// printf("posicao que vai ser inserido %d\n", left);
	return left;
}

// return 1 if there is already the element
int hash_array_add (int *tb, const int x, const int M)
{
	const int pos = hash_array_find(tb, x, M);
	// elemento ja existe
	// duplicada
	if (pos == -1 || tb[pos] == x)
		return 1;

	return tb[pos] = x, 0;
}

void hash_table_realloc (TH *ht)
{
	// achar novo M
	const int M = aumentaTamanho1(ht->M);

	// ja chegou no limite
	if (M == ht->M)
		return;

	// re-alloc new array and initialize empty
	int *tb = malloc(sizeof(int) * (size_t)M);
	memset(tb, EMPTY, (size_t)M * sizeof(int));
	//for (int i = 0; i < M; ++i)
	//	tb[i] = EMPTY;

	const int old_M = ht->M;
	ht->M = M;

	// rehash all old elements
	for (int i = 0; i < old_M; ++i)
		if (ht->tb[i] != EMPTY)
			hash_array_add(tb, ht->tb[i], M);
	ht->tb = tb;
}

// 1.
//   procura posição a direita
//   com salto de uma casa.
// 2. sem chaves duplicadas
// 3.
//   caso a tabela hash tenha taxa de ocupação de mais de 50% (ou seja, se N > floor(M/2)), antes de inserir um novo
//   elemento você deve redimensionar a tabela. Para tanto, você deve consultar o próximo primo usando aumentaTamanho()
void THinsere (TH *h, int ch)
{
	// 3. N > floor(M/2)
	if (h->N > h->M / 2)
		hash_table_realloc(h);

	if (hash_array_add(h->tb, ch, h->M))
		return;

	++h->N;
}

// 1.
//   1 se for encontrada.
//   0 se nao for
int THbusca (TH *h, int ch)
{
	const int pos = hash_array_find(h->tb, ch, h->M);
	return h->tb[pos] == ch ? 1 : 0;
}

// 1.
//    0 se for encontrada
//    -1 se nao for
// 2.
//    se tiver a direita outras chaves, deve-se dar rehash nelas.
int THremove (TH *h, int ch)
{
	const int pos = hash_array_find(h->tb, ch, h->M);
	// nao foi encontrado
	if (pos == -1 || h->tb[pos] != ch)
		return -1;
	int left = pos;

	h->tb[left] = EMPTY;
	--h->N;

	// enquanto nao encontrar -1, rehash!
	for (int dado; h->tb[++left] != EMPTY;)
	{
		left %= h->M;
		dado = h->tb[left];
		h->tb[left]= EMPTY;
		hash_array_add(h->tb, dado, h->M);
	}

	return 0;
}

int main(void)
{
	TH *table = hash_table_create(2);

	THinsere(table, 153421);
	THinsere(table, 22123);
	THinsere(table, 3);
	THinsere(table, 4);
	THinsere(table, 1342);
	THinsere(table, 4232);
	THinsere(table, 321989);
	THinsere(table, 3289);
	THinsere(table, 721989);
	THinsere(table, 3219329);
	THinsere(table, 289);
	THinsere(table, 321989);
	THinsere(table, 989);

	printf("%d", THbusca(table, 1));
	printf("%d", THbusca(table, 6));
	printf("%d", THbusca(table, 3));
	printf("\n");

	hash_table_print(table);

	printf("r: %d\n",THremove(table, 3));

	hash_table_print(table);
}

/*int main(void)
{
	printf("aumenta de tamanho: %d\n", aumentaTamanho1(402653189));

	TH *hash_table = hash_table_create(2);
	THinsere(hash_table, 5);
	THinsere(hash_table, 97 + 5);
	THinsere(hash_table, 97 * 2 + 5);
	THremove(hash_table, 97 * 2 + 5);
	//THinsere(hash_table, 10);
	//THinsere(hash_table, 63);
	//THinsere(hash_table, 116);
	//THinsere(hash_table, 11);
	//THinsere(hash_table, 0);
	//THinsere(hash_table, 1);
	//THinsere(hash_table, 2);
	//THinsere(hash_table, 3);
	//THinsere(hash_table, 4);
	//THinsere(hash_table, 5);
	//THinsere(hash_table, 5);
	//THinsere(hash_table, 5);
	//THinsere(hash_table, 6);
	//THinsere(hash_table, 96);
	//THinsere(hash_table, 95);
	//THinsere(hash_table, 97);
	//THinsere(hash_table, 194);
	//THremove(hash_table, 10);
	//THremove(hash_table, 58);
	//THinsere(hash_table, 91);
	//THinsere(hash_table, 52);
	//THinsere(hash_table, 51);
	//THinsere(hash_table, 104);
	//THremove(hash_table, 4);
	//THremove(hash_table, 98);
	//for (int i = 0; i < 25; ++i)
	//	THinsere(hash_table, i);
	//THremove(hash_table, 4);
	////for (int i = 0; i < 150; ++i)
	////	THremove(hash_table, i);
	//hash_table_realloc(hash_table);
	//hash_table_realloc(hash_table);

	//THinsere(hash_table, 195);
	//THinsere(hash_table, 389 + 193);

	//for (int i = 0; i < 200; ++i)
	//{
	//	if (THbusca(hash_table, i))
	//	{
	//		printf("Foi encontrado %d\n", hash_table->tb[i]);
	//	}
	//}

	hash_table_print(hash_table);

	hash_table_destroy(hash_table);
}*/
