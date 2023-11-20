#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Tree.
typedef struct no
{
	int dado;
	struct no *esq, *dir;
} no;

// Stack.
typedef struct node
{
	no *data;
	struct node *next;
} node;

typedef struct
{
	int n;
	node *head;
} stack;

/*
 * Stack.
 */
stack *stack_create(void)
{
	stack *pile = malloc(sizeof(stack));
	*pile = (stack){ .n = 0, .head = NULL };
	return pile;
}

inline bool stack_empty(stack *pile)
{
	return pile->n == 0;
}

void stack_insert(stack *pile, no *data)
{
	if (!data)
		return;
	node *front = malloc(sizeof(node));
	*front = (node){.data = data, .next = pile->head };
	pile->head = front;
	++pile->n;
}

no *stack_peek_remove(stack *pile)
{
	assert(stack_empty(pile) == false);
	node *temp = pile->head;
	no *data = temp->data;
	pile->head = temp->next;
	--pile->n;
	return free(temp), data;
}

void stack_destroy(stack *pile)
{
	while (!stack_empty(pile))
		stack_peek_remove(pile);
	free(pile);
}

/*
 * Trees.
 */

//no *insere(int dado, no *esq, no *dir)
//{
//	no *novo = malloc(sizeof(no));
//	*novo = (no){.dado = dado, .esq = esq, .dir = dir };
//	return novo;
//}

void pre_ordem_rec (no *raiz)
{
	if (!raiz)
		return;
	printf("%d ", raiz->dado);
	pre_ordem_rec(raiz->esq);
	pre_ordem_rec(raiz->dir);
}

void pre_ordem (no *raiz)
{
	stack *pile = stack_create();
	stack_insert(pile, raiz);

	while (!stack_empty(pile))
	{
		no *current = stack_peek_remove(pile);
		printf("%d ", current->dado);
		stack_insert(pile, current->dir);
		stack_insert(pile, current->esq);
	}
	putchar('\n');

	stack_destroy(pile);
}

void em_ordem_rec (no *raiz)
{
	if (!raiz)
		return;
	em_ordem_rec(raiz->esq);
	printf("%d ", raiz->dado);
	em_ordem_rec(raiz->dir);
}

void em_ordem (no *raiz)
{
	stack *parents = stack_create();
	no *left = raiz;

	while (left || !stack_empty(parents))
	{
		while (left)
			stack_insert(parents, left),
			left = left->esq;

		left = stack_peek_remove(parents);
		printf("%d ", left->dado);
		
		left = left->dir;
	}

	putchar('\n');
	stack_destroy(parents);
}

void pos_ordem_rec (no *raiz)
{
	if (!raiz)
		return;
	pos_ordem_rec(raiz->esq);
	pos_ordem_rec(raiz->dir);
	printf("%d ", raiz->dado);
}

void pos_ordem (no *raiz)
{
	stack *pile = stack_create();
	stack_insert(pile, raiz);

	stack *back = stack_create();

	while (!stack_empty(pile))
	{
		no *current = stack_peek_remove(pile);
		stack_insert(back, current);
		stack_insert(pile, current->esq);
		stack_insert(pile, current->dir);
	}

	stack_destroy(pile);

	while (!stack_empty(back))
		printf("%d ", stack_peek_remove(back)->dado);

	putchar('\n');
	stack_destroy(back);
}

// Frees all tree.
//void tree_destroy (no *raiz)
//{
//}

//int main (void)
//{
//	no *raiz = insere(2, insere(5, insere(3, NULL, NULL), insere(8, insere(4, NULL, NULL), NULL)), insere(7, insere(1, NULL, insere(9, NULL, NULL)), insere(6, NULL, NULL)));
//
//	puts("Pre-order  : 2 5 3 8 4 7 1 9 6");
//	printf("Recursive  : ");
//	pre_ordem_rec(raiz);
//	putchar('\n');
//
//	printf("Iterative  : ");
//	pre_ordem(raiz);
//	putchar('\n');
//
//	puts("In-order   : 3 5 4 8 2 1 9 7 6");
//	printf("Recursive  : ");
//	em_ordem_rec(raiz);
//	putchar('\n');
//
//	printf("Iterative  : ");
//	em_ordem(raiz);
//	putchar('\n');
//
//	puts("Post-order : 3 4 8 5 9 1 6 7 2");
//	printf("Recursive  : ");
//	pos_ordem_rec(raiz);
//	putchar('\n');
//
//	printf("Iterative  : ");
//	pos_ordem(raiz);
//	putchar('\n');
//}
