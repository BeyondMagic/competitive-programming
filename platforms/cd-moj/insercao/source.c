#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

// void imprime (celula *le)
// {
// 	while (le && le->prox)
// 		printf("%d -> ", le->prox->dado), le = le->prox;
// 	puts("NULL");
// }
// 
// void imprime_rec (celula *le)
// {
// 	if (!le || !le->prox)
// 	{
// 		puts("NULL");
// 		return;
// 	}
// 
// 	printf("%d -> ", le->prox->dado), imprime_rec(le->prox);
// }

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

/*int main(void)
{
	celula c = { 4, NULL };
	celula b = { 2, &c };
	celula a = { 1, &b };
	celula head = { -1000, &a };
	imprime_rec(&head);

	insere_inicio(&head, 0);
	insere_antes(&head, -1, 0); // inicio
	insere_antes(&head, 3, 4); // antes do 4 insiro o tres
	insere_antes(&head, 5, 5); // inserir no final ja que nao tem 5

	imprime_rec(&head);
}*/
