#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula
{
	char matricula[10];
	double mediaAtividades;
	double mediaProvas;
	struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media)
{
	celula *temp = le;
	while (temp)
	{
		if (temp->mediaAtividades <= media)
		{
			memcpy(l1->matricula, temp->matricula, sizeof(char) * 10);
			l1->mediaProvas = temp->mediaProvas;
			l1->mediaAtividades = temp->mediaAtividades;

			l1->prox = malloc(sizeof(celula));
			l1 = l1->prox;
		} else {
			memcpy(l2->matricula, temp->matricula, sizeof(char) * 10);
			l2->mediaProvas = temp->mediaProvas;
			l2->mediaAtividades = temp->mediaAtividades;

			l2->prox = malloc(sizeof(celula));
			l2 = l2->prox;
		}
		temp = temp->prox;
	}
}

/*int main(void)
{
	celula le = { "140164006", 10, 8, NULL },
			l1,
			l2;

	celula n1 = { "160016169", 4, 2, NULL };
	le.prox = &n1;

	celula n2 = { "170062465", 9.5, 7.5, NULL };
	n1.prox = &n2;

	celula n3 = { "190262661", 5, 7, NULL };
	n2.prox = &n3;

	relatorioMediaAtividades(&le, &l1, &l2, 6);

	printf("%lf\n", l1.prox->mediaAtividades);
	printf("%lf\n", l2.prox->mediaAtividades);
}*/
