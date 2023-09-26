#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000 + 10
int digits = 0;

// função que recebe uma string que representa um numero e retorna ele + 1
// obviamente só funciona para números positivos
char * number_add_one (char to_add[])
{
	int N = (int)strlen(to_add);
	digits = N;
	char *novo = calloc(sizeof(char), MAX);
	for (int i = MAX - N - 1, j = 0; j < N; ++i, ++j)
		novo[i] = to_add[j];
	novo[MAX - 1] = '\0'; // ja tem \0 la?

	int r = MAX - 2; // right de novo, ultimo caractere real
	// se o ultimo caractere nao for 9, so somar mais um e nao fazer mais nada
	if (novo[r] != '9')
		return ++novo[r], novo;

	// continuar ate todos os ultimos carecteres nao forem 0
	while (novo[r] == '9')
	{
		novo[r] = '0'; // transforma esse em 0
		--r; // volta um caractere
		// adiciona mais um se nao for 9
		if (novo[r] == '\0')
		{
			novo[r] = '1';
			++digits;
			break;
		} else if (novo[r] != '9')
		{
			++novo[r];
			break; // para ser q ele tenha se trasnformado em 9.
		}
	}
	
	return novo;
}

#define offset MAX - digits - 1

int main(void)
{
	int n;
	scanf("%d\n", &n);
	char numbers[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%c", &numbers[i]);
		if (numbers[i] == ' ')
			--i;
	}
	char A[MAX];
	int A_digits = 1;
	while (true)
	{
		// copy new A
		for (int i = 0; i <= A_digits; ++i)
			A[i] = i == A_digits ? '\0' : numbers[i];


		bool good = true;
		char *next = number_add_one(A);
		for (int i = A_digits; i < n && good;)
		{
			// printf("numbers + i = [%c]\n", *(numbers + i));
			// printf("next + offset = [%c]\n", *(next + offset));
			// printf("digits = [%d]\n", digits);
			if (strncmp(numbers + i, next + offset, (size_t)digits))
				good = false;
			else
			{
				// puts("good");
				i += digits;
				// free(next);
				next = number_add_one(next + offset);
			}
		}

		free(next);

		if (good)
			break;

		// puts("get new digit\n");
		++A_digits; // get new digit
	}
	for (int i = 0; i < A_digits; ++i)
		putchar(A[i]);
	putchar('\n');
	// char *plus_one = number_add_one("28328523525329");
	// printf("digits %d\n", digits);
	// putchar('\n');
	// puts(plus_one + offset);
	// free(plus_one);
}
