#include <stdio.h>

#define MAX 50
#define EMPTY '.'

char garden[MAX][MAX + 1]; // + 1 para espaço do '\0'.

int total = 0;

int main (void)
{
	int L, C;
	scanf("%d %d\n", &L, &C);

	/* Ler o jardim. */
	for (int i = 0; i < L; ++i)
		scanf("%s\n", garden[i]);

	int n;
	scanf("%d\n", &n);

	while (n--)
	{
		char command;
		scanf("%c ", &command);

		/* Remover todas as flores. */
		if (command == 't')
		{
			char specie;
			scanf("%c\n", &specie);

			for (int i = 0; i < L; ++i)
				for (int j = 0; j < C; ++j)
					if (garden[i][j] == specie)
						garden[i][j] = EMPTY,
						++total;
		}

		/* Remover flor na posição. */
		else if (command == 'r')
		{
			int l, c;
			scanf("%d %d\n", &l, &c);
			if (garden[--l][--c] != EMPTY)
				++total;
			garden[l][c] = EMPTY;
		}

		/* Plantar flor na posição. */
		else {
			char specie;
			int l, c;
			scanf("%c %d %d\n", &specie, &l, &c);
			if (garden[--l][--c] != EMPTY)
				++total;
			garden[l][c] = specie;
		}
	}

	printf("%d\n", total);
	/* Imprimir o jardim na tela. */
	for (int i = 0; i < L; ++i)
		printf("%s\n", garden[i]);
}
