#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3)
{
	// first node
	if (l1->dado <= l2->dado)
	{
		l3->dado = l1->dado;
		l1 = l1->prox;
	} else {
		l3->dado = l2->dado;
		l2 = l2->prox;
	}

	// rest
	// while (l1 || l2)
	// {
	// 	// both l1 and l2
	// 	if (l1 && ( !l2 || (l2 && l1->dado <= l2->dado)))
	// 	{
	// 		l3->prox = l1;
	// 		l3 = l1 = l1->prox;
	// 	} else {
	// 		l3->prox = l1;
	// 		l3 = l1 = l1->prox;
	// 	}
	// }
}

celula * init(const int dado) {
	celula *l = malloc(sizeof(celula));

	l->dado = dado;
	l->prox = NULL;

	return l;
}

bool push (celula *l, const int dado)
{
	l->prox = malloc(sizeof(celula));
	if (!l->prox)
		return false;

	l = l->prox;
	l->dado = dado;
	l->prox = NULL;

	return true;
}

void destroy(celula * l)
{
	celula *temp;
	while (l->prox)
	{
		temp = l;
		l = l->prox;
		free(temp);
	}
	free(l);
}

int main(void)
{
	celula *l1 = init(1);
	push(l1, 7);
	push(l1, 9);
	push(l1, 10);

	celula *l2 = init(2);
	push(l2, 3);
	push(l2, 8);

	celula l3;
	mescla_listas(l1, l2, &l3);

	destroy(l1);
	destroy(l2);
}
