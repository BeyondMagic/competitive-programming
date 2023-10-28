#include <stdio.h>
#include <stdlib.h>

#define hash(ht, key) (key%ht->M)

int aumentaTamanho(int M); //retorna proximo tamanho de M

int aumentaTamanho1(int M)
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

typedef struct {
	int *tb; // tabela hash
	int M; // tamanho da tabela hash
	int N; // total de chaves presentes na tabela
}TH;

int THbusca (TH *h, int ch){
	int key = hash(h, ch);
	int i = h->M;
	while(h->tb[key] != ch && i++ < h->M) key = (key+1)%h->M;

	if(h->tb[key] == ch) return 1;

	return 0;
}

void THinsere (TH *h, int ch){
	// redimensionar
	if(h->N > h->M / 2){
		//criar nova tabela
		TH *new_h = malloc(sizeof(TH));
		new_h->M = aumentaTamanho(h->M);
		new_h->tb = malloc(sizeof(int)*(size_t)new_h->M);

		// inicializar todos as posicoes com -1
		for(int i = 0; i < new_h->M ; i++) new_h->tb[i] = -1;

		//copiar elementos da tabale A para a tabela B
		for(int i = 0 ; i < h->M ; i++)
			if(h->tb[i] != -1)
				THinsere(new_h, h->tb[i]);

		//free na tabela antiga
		// free(h);
		// h = malloc(sizeof(TH));
		h->N = new_h->N;
		h->tb = new_h->tb;
		h->M = new_h->M;
	}

	if(THbusca(h, ch)) return;

	// inserir
	int key = hash(h, ch);
	//while(h->tb[key] != -1){
	//    key = (key+1)%h->M;
	//}
	int i = 0;
	while(h->tb[key] != -1 && i++ < h->M) key = (key+1)%h->M;

	h->tb[key] = ch;
	h->N += 1;
}

int THremove (TH *h, int ch){
	if(!THbusca(h, ch)) return -1;

	int key = hash(h, ch);
	while(h->tb[key] != ch) key = (key+1)%h->M;
	h->tb[key] = -1;
	h->N -= 1;

	return 0;
}

/*
 * novas coisas
*/

#include <string.h>

TH *hash_table_create (int M)
{
	TH *hash_table = malloc(sizeof(TH));
	hash_table->M = M;
	hash_table->N = 0;
	hash_table->tb = malloc((size_t) M * sizeof(int));
	memset(hash_table->tb, -1, sizeof(int) * (size_t)M);

	return hash_table;
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

// 
// int main(){
// 	TH *table = hash_table_create(2);
// 
// 	THinsere(table, 153421);
// 	THinsere(table, 22123);
// 	THinsere(table, 3);
// 	THinsere(table, 4);
// 	THinsere(table, 1342);
// 	THinsere(table, 4232);
// 	THinsere(table, 321989);
// 	THinsere(table, 3289);
// 	THinsere(table, 721989);
// 	THinsere(table, 3219329);
// 	THinsere(table, 289);
// 	THinsere(table, 321989);
// 	THinsere(table, 989);
// 
// 	printf("%d", THbusca(table, 1));
// 	printf("%d", THbusca(table, 6));
// 	printf("%d", THbusca(table, 3));
// 	printf("\n");
// 
// 	hash_table_print(table);
// 
// 	printf("r: %d\n",THremove(table, 3));
// 
// 	hash_table_print(table);
// }
// 
