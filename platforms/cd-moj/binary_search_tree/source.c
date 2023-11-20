#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} node;

node *create_node(int data)
{
	node *cell = malloc(sizeof(node));
	*cell = (node){ .data = data, .left = NULL, .right = NULL };
	return cell;
}

node *tree_binary_insert(node *root, int data)
{
	if (!root)
		return create_node(data);

	if (data < root->data)
		root->left = tree_binary_insert(root->left, data);

	else if (data > root->data)
		root->right = tree_binary_insert(root->right, data);

	return root;
}

node *tree_binary_find(node *root, int data)
{
	if (!root || root->data == data)
		return root;

	if (root->data < data)
		return tree_binary_find(root->right, data);

	return tree_binary_find(root->left, data);
}

/*
 * Fila de prioriridade
 */

typedef struct
{
	int *v;
	int k;
	int n;
} fp;

fp *heap_create(int k)
{
	fp *pq = malloc(sizeof(fp));
	pq->n = 0;
	pq->k = 1;
	for (int i = 0; i < k; ++i)
		pq->k *= 2;
	pq->v = malloc(sizeof(int) * (size_t)pq->k);
	return pq;
}

#define parent(i) (i - 1) / 2
#define right(i) 2 * i + 1
#define left(i) 2 * i + 2

inline void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap_down(int *v, int n, int i)
{
	int g = -1;
	if (left(i) < n)
	{
		g = left(i);
		if (right(i) < n && v[right(i)] > v[left(i)])
			g = right(i);
		if (v[i] < v[g])
			swap(v + i, v + g),
			heap_down(v, n, g);
	}

}

void heap_up(int *v, int i)
{
	if (!i || v[parent(i)] > v[i])
		return;
	swap(v + parent(i), v + i);
	heap_up(v, parent(i));
}

void heap_insert(fp *pq, int x)
{
	pq->v[pq->n++] = x;
	heap_up(pq->v, pq->n - 1);
}

int heap_remove(int *v, int n)
{
	swap(v + 0, v + n - 1);
	heap_down(v, n, 0);
	return v[n - 1];
}

void heap_sort(int *v, int n)
{
	for (int i = n/2; i >= 0; --i)
		heap_down(v, n, i);
	while (n)
		heap_remove(v, n--);
}

/*
 * LLRB
 */

typedef struct no
{
	int chave;
	enum { BLACK, RED } colour;
	struct no *esq, *dir;
} no;

no * llrb_remove_sucessor(no *root, int *ch)
{
	if (!root->esq)
		return *ch = root->chave, root->dir;
	return root->esq = llrb_remove_sucessor(root->esq, ch), root;
}

no *llrb_remove (no *root, int ch)
{
	if (!root)
		return root;
	if (ch < root->chave)
		root->esq = llrb_remove(root->esq, ch);
	else if (ch > root->chave)
		root->dir = llrb_remove(root->dir, ch);
	else
	{
		if (!root->esq)
			return root->dir;
		else if (!root->dir)
			return root->esq;
		else
		{
			int nova;
			root->dir = llrb_remove_sucessor(root->esq, &nova);
			root->chave = nova;
		}
	}
	return root;
}

no *llrb_rotate_left(no *root)
{
	no *x = root->dir;
	root->dir = x->esq;
	x->esq = root;
	x->colour = root->colour;
	root->colour = RED;
	return x;
}

no *llrb_rotate_right(no *root)
{
	no *x = root->esq;
	root->esq = x->dir;
	x->dir = root;
	x->colour = root->colour;
	root->colour = RED;
	return x;
}

void llrb_up_colour (no *root)
{
	root->colour = RED;
	root->esq->colour = root->dir->colour = BLACK;
}

no *llrb_fix(no *root)
{
	if (root->esq->colour == BLACK && root->dir->colour == RED)
		return llrb_rotate_left(root);

	if (root->esq->colour == RED && root->dir->colour == RED)
		return llrb_up_colour(root), root;

	if (root->esq->colour == RED && root->esq->esq->colour == RED)
	{
		root = llrb_rotate_right(root);
		return llrb_up_colour(root), root;
	}

	return root;
}

no *llrb_insert_rec(no *root, int ch)
{
	if (!root)
	{
		no *novo = malloc(sizeof(no));
		novo->esq = novo->dir = NULL;
		novo->chave = ch;
		novo->colour = RED;
		return novo;
	}

	if (ch < root->chave)
		root->esq = llrb_insert_rec(root->esq, ch);
	else
		root->dir = llrb_insert_rec(root->dir, ch);

	return llrb_fix(root);
}

no *llrb_insert(no *root, int ch)
{
	root = llrb_insert_rec(root, ch);
	return root->colour= BLACK, root;
}


int main(void)
{
	{ // BST
		node *root = tree_binary_insert(NULL, 50);
		tree_binary_insert(root, 30);
		tree_binary_insert(root, 20);
		tree_binary_insert(root, 40);
		tree_binary_insert(root, 70);
		tree_binary_insert(root, 60);
		tree_binary_insert(root, 80);

		assert(tree_binary_find(root, 60) != NULL);
		assert(tree_binary_find(root, 60)->data == 60);
		assert(tree_binary_find(root, 100) == NULL);
	}

	{ // Priority Heap
		
	}
}
