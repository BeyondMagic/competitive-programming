#include <stdlib.h>

#define hash(ht, key) (key % ht->M)

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

int aumentaTamanho (int M) { return aumentaTamanho1(M); }

// int aumentaTamanho (int M); // retorna proximo tamanho de M

typedef struct
{
	int *tb; // tabela hash
	int M;   // tamanho da tabela hash
	int N;   // total de chaves presentes na tabela
} TH;

int THbusca(TH *h, int ch)
{
	int key = hash(h, ch);
	int i = h->M;

	while (h->tb[key] != ch && i++ < h->M)
		key = (key + 1) % h->M;

	if (h->tb[key] == ch)
		return 1;

	return 0;
}

void THinsere(TH *h, int ch)
{
	if (THbusca(h, ch))
		return;

	// redimensionar
	if (h->N > h->M / 2)
	{
		// criar nova tabela
		TH *new_h = malloc(sizeof(TH));
		new_h->M = aumentaTamanho(h->M);
		new_h->tb = malloc(sizeof(int) * (size_t)new_h->M);

		// inicializar todos as posicoes com -1
		for (int i = 0; i < new_h->M; i++)
			new_h->tb[i] = -1;

		// copiar elementos da tabale A para a tabela B
		for (int i = 0; i < h->M; i++)
			if (h->tb[i] != -1)
				THinsere(new_h, h->tb[i]);

		// free na tabela antiga
		free(h);

		// atualizar os ponteiros
		h->N = new_h->N;
		h->tb = new_h->tb;
	}

	// inserir
	int key = hash(h, ch);
	while (h->tb[key] != -1)
		key = (key + 1) % h->M;

	h->tb[key] = ch;
	h->N += 1;
}

int THremove(TH *h, int ch)
{
	if (!THbusca(h, ch))
		return -1;

	int key = hash(h, ch);
	while (h->tb[key] != ch)
		key = (key + 1) % h->M;
	h->tb[key] = -1;
	h->N -= 1;

	return 0;
}

/*
 *
 * Rest.
 *
 *
 */

#include <stdio.h>
#include <string.h>

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
	memset(hash_table->tb, -1, sizeof(int) * (size_t)M);

	return hash_table;
}


int main(void)
{
	printf("aumenta de tamanho: %d\n", aumentaTamanho1(402653189));

	TH *hash_table = hash_table_create(2);
	THinsere(hash_table, 5);
	THinsere(hash_table, 10);
	THinsere(hash_table, 15);
	//THinsere(hash_table, 97 + 5);
	//THinsere(hash_table, 97 * 2 + 5);
	//THremove(hash_table, 97 * 2 + 5);
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
}
