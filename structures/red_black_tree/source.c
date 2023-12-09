#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
	int id;
} Data;

typedef struct Node {
	Data info;
	enum { RED, BLACK } color;
	struct Node *left, *right, *parent;
} Node;

Node raiz = { .info.id = 10, .color = RED, .left = NULL, .right = NULL, .parent = NULL };

int main(void)
{
	raiz.color = BLACK;
	printf("%d\n", raiz.color == RED ? 1 : 0);
}
