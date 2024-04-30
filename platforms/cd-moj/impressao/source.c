#include <iso646.h>

int puts(const char *str);
int printf(const char *restrict format, ...);

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

void imprime (celula *le)
{
	while (le and le->prox)
		printf("%d -> ", le->prox->dado),
		le = le->prox;
	puts("NULL");
}

void imprime_rec (celula *le)
{
	if (not le or not le->prox)
	{
		puts("NULL");
		return;
	}

	printf("%d -> ", le->prox->dado),
	imprime_rec(le->prox);
}
