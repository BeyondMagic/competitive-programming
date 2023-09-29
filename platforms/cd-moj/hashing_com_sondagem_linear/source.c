#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum
{
	EMPTY = -1
};

typedef struct {
	int *tb; // tabela hash, vazio é -1
	int M; // tamanho da tabela hash
	int N; // total de chaves presentes na tabela
} TH;

inline int hash_table_position (TH *hash_table, int pos)
{
	return pos % hash_table->M;
}

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
	for (int i = 0; i < M; ++i)
		hash_table->tb[i] = EMPTY;

	return hash_table;
}

// 1.
//   implementada aumentaTamanho() que recebe o tamanho atual da tabela hash e retorna o novo tamanho.
//   Esta função deve ser declarada no preâmbulo do seu código.
// 2.
//   fazer busca binaria na tabela para pegar o maior numero depois do M.
int aumentaTamanho (int M)
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

// 1.
//   procura posição a direita
//   com salto de uma casa.
// 2. sem chaves duplicadas
void THinsere (TH *h, int ch)
{
	const int pos = hash_table_position(h, ch);
	int left = pos;
	// printf("posicao a ser inserido %d\n", left);
	while (h->tb[left] != -1)
	{
		++left;
		left %= h->M;
		// sem chave duplicada = deu um loop completo
		if (left == pos)
			return;
	}
	// printf("posicao que vai ser inserido %d\n", left);
	h->tb[left] = ch;
}

// 1.
//   caso a tabela hash tenha taxa de ocupação de mais de 50% (ou seja, se N > floor(M/2)), antes de inserir um novo
//   elemento você deve redimensionar a tabela. Para tanto, você deve consultar o próximo primo usando aumentaTamanho()

// 1.
//    0 se for encontrada
//    1 se nao for
// 2.
//    se tiver a direita outras chaves, deve-se dar rehash nelas.
int THremove (TH *h, int ch);

// 1.
//   1 se for encontrada.
//   0 se nao for
int THbusca (TH *h, int ch);

int main(void)
{
	// printf("aumenta de tamanho: %d\n", aumentaTamanho(402653189));

	TH *hash_table = hash_table_create(53);
	THinsere(hash_table, 10);
	THinsere(hash_table, 63);
	THinsere(hash_table, 116);
	THinsere(hash_table, 5);
	THinsere(hash_table, 11);
	hash_table_print(hash_table);

	hash_table_destroy(hash_table);
}
