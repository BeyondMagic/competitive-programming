// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <limits.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

/*
void imprime (celula *le)
{
	while (le && le->prox)
		printf("%d -> ", le->prox->dado), le = le->prox;
	puts("NULL");
}

void imprime_rec (celula *le)
{
	if (!le || !le->prox)
	{
		puts("NULL");
		return;
	}

	printf("%d -> ", le->prox->dado), imprime_rec(le->prox);
}

void insere_inicio (celula *le, int x)
{
	celula *nova = malloc(sizeof(celula));
	nova->dado = x;
	nova->prox = le->prox;
	le->prox = nova;
}

void insere_antes (celula *le, int x, int y)
{
	while (le && le->prox && le->prox->dado != y)
		le = le->prox;

	insere_inicio(le, x);
}

int remove_depois (celula *p)
{
	if (!p || !p->prox)
		return 1;
	celula *after = p->prox;
	int after_data = after->dado;

	if (p->prox->prox)
		p->prox = p->prox->prox;
	else
		p->prox = NULL;

	return free(after), after_data;
}

void remove_elemento (celula *le, int x)
{
	while (le && le->prox && le->prox->dado != x)
		le = le->prox;
	remove_depois(le);
}

void remove_todos_elementos (celula *le, int x)
{
	while (le && le->prox)
		if (le->prox->dado == x)
			remove_depois(le);
		else
			le = le->prox;
}

celula *busca (celula *le, int x)
{
	while (le && le->dado != x)
		le = le->prox;
	return le;
}

celula *busca_rec (celula *le, int x)
{
	if (!le || le->dado == x)
		return le;
	return busca_rec(le->prox, x);
}*/

void mescla_listas (celula *l1, celula *l2, celula *l3)
{
	l1 = l1->prox;
	l2 = l2->prox;

	while (l1 && l2)
		if (l1 && (!l2 || (l2 && l1->dado <= l2->dado)))
		{
			l3->prox = l1;
			l3 = l3->prox;
			l1 = l1->prox;
		} else {
			l3->prox = l2;
			l3 = l3->prox;
			l2 = l2->prox;
		}
}

/*
int main(void)
{
	puts("! Criacao !");

	celula c = { 4, NULL };
	celula b = { 2, &c };
	celula a = { 1, &b };
	celula head = { INT_MIN, &a };

	puts("! Insercao !");

	// insere_inicio(&head, 4);
	// insere_inicio(&head, 2);
	// insere_inicio(&head, 1);
	insere_inicio(&head, 0);
	insere_antes(&head, -1, 0); // inicio
	insere_antes(&head, 3, 4); // antes do 4 insiro o tres
	insere_antes(&head, 5, 5); // inserir no final ja que nao tem 5
	insere_antes(&head, 5, 5); // inserir no final ja que nao tem 5
	insere_antes(&head, 5, 5); // inserir no final ja que nao tem 5

	imprime_rec(&head);

	puts("! Remocao !");

	int oq = remove_depois(&c); // inserir no final ja que nao tem 5
	printf("Foi removido um %d.\n", oq);
	remove_elemento(&head, 3);
	puts("Foi removido um 3.");

	remove_todos_elementos(&head, 5);
	puts("Foi removido todos 5s.");
	imprime_rec(&head);

	puts("! Busca !");

	{
		celula *elemento = busca(&head, 1);
		printf("Achado elemento %d.\n", elemento->dado);
		celula *nao_achado = busca(&head, 5);
		if (!nao_achado)
			puts("Nao achou elemento 5");
		else
			puts("Achou elemento que não deveria ter achado.");
	}
	{
		celula *elemento = busca_rec(&head, 1);
		printf("Achado elemento %d.\n", elemento->dado);
		celula *nao_achado = busca_rec(&head, 5);
		if (!nao_achado)
			puts("Nao achou elemento 5");
		else
			puts("Achou elemento que não deveria ter achado.");
	}
	
	puts("! Mesclar !");
	{
		celula head1 = { INT_MIN, NULL };
		celula head2 = { INT_MIN, NULL };
		celula head3 = { INT_MIN, NULL };

		insere_inicio(&head1, 10);
		insere_inicio(&head1, 9);
		insere_inicio(&head1, 7);
		insere_inicio(&head1, 1);
		printf("head1 = ");
		imprime(&head1);

		insere_inicio(&head2, 8);
		insere_inicio(&head2, 3);
		insere_inicio(&head2, 2);
		printf("head2 = ");
		imprime(&head2);

		mescla_listas(&head1, &head2, &head3);

		printf("head3 = ");
		imprime(&head3);
		
	}
}*/
