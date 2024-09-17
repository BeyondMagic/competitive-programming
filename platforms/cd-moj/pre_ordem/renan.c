#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct no {
  int dado;
  struct no *esq, *dir;
} no;
typedef struct pilha {
  no *dados;
  int N, topo;
} pilha;
int empilha (pilha *p, no x){
  if(p->topo == p->N) {
    p->N *= 2;
    p->dados = realloc(p->dados, p->N * sizeof(no));
  }
  if(p->dados == NULL) return 0;
  p->dados[p->topo++] = x;
  return 1;
}
int desempilha (pilha *p, no *y){
   if(p->topo == 0) return 0;
   *y = p->dados[--p->topo];
   return 1;
}
bool stackEmpty(pilha *stack) {
  return (stack->topo == 0); 
}
void pre_ordem (no *raiz) {
  if (!raiz) return;
  pilha *s = malloc(sizeof(pilha));
  s->N = 105;
  s->topo = 0;
  s->dados = malloc(s->N*sizeof(no));
  empilha(s, *raiz);
	no *current_node = malloc(sizeof(no));
  while(!stackEmpty(s)) {
    desempilha(s, current_node);
    printf("%d ", current_node->dado);
    if(current_node->esq) empilha(s, *current_node->dir);
    if(current_node->dir) empilha(s, *current_node->esq);
  }
	free(current_node);
  printf("\n");
  free(s->dados);
  free(s);
}

int main (void)
{
	//no *raiz = insere(2, insere(5, insere(3, NULL, NULL), insere(8, insere(4, NULL, NULL), NULL)), insere(7, insere(1, NULL, insere(9, NULL, NULL)), insere(6, NULL, NULL)));

	no p3 = { .dado = 3, .esq = NULL, .dir = NULL };
	no p4 = { .dado = 4, .esq = NULL, .dir = NULL };
	no p9 = { .dado = 9, .esq = NULL, .dir = NULL };
	no p6 = { .dado = 6, .esq = NULL, .dir = NULL };

	no p1 = { .dado = 1, .esq = NULL, .dir = &p9 };
	no p7 = { .dado = 1, .esq = &p9, .dir = &p6 };
	no p8 = { .dado = 8, .esq = &p4, .dir = NULL };
	no p5 = { .dado = 5, .esq = &p3, .dir = &p8 };
	no p2 = { .dado = 2, .esq = &p5, .dir = &p7 };

	puts("Pre-order  : 2 5 3 8 4 7 1 9 6");
	//printf("Recursive  : ");
	//pre_ordem_rec(raiz);
	//putchar('\n');

	printf("Iterative  : ");
	pre_ordem(&p2);
	putchar('\n');

	//puts("In-order   : 3 5 4 8 2 1 9 7 6");
	//printf("Recursive  : ");
	//em_ordem_rec(raiz);
	//putchar('\n');

	//printf("Iterative  : ");
	//em_ordem(raiz);
	//putchar('\n');

	//puts("Post-order : 3 4 8 5 9 1 6 7 2");
	//printf("Recursive  : ");
	//pos_ordem_rec(raiz);
	//putchar('\n');

	//printf("Iterative  : ");
	//pos_ordem(raiz);
	putchar('\n');
}
