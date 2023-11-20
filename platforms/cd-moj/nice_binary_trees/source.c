#include <stdio.h>
#include <stdlib.h>

#define MAX 10000 + 10

#define LEAF 'l'
#define NODE 'n'

int h = 0;

int max (int a, int b)
{
	return a > b ? a : b;
}

// we have to skip all leafs when traversing left or right
int pre_ordem_rec (char *raiz)
{
	if (*(raiz + h++) == LEAF)
		return 0;
	// get max height left side,
	// get max height right side,
	return max(pre_ordem_rec(raiz), pre_ordem_rec(raiz)) + 1;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	char *string = malloc(sizeof(char) * MAX);
	while (t--)
	{
		scanf("%s", string);
		h = 0;
		printf("%d\n", pre_ordem_rec(string));
	}
}
