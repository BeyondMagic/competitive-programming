#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<
#define even(x) (!((x) & 1))
#define odd(x) ((x) & 1)

#define u64 uint64_t
#define u64_f "%" SCNu64

/*
 * Data Strucuture: Node
 * */

typedef struct Node {
	u64 data;
	struct Node *next;
} Node;

u64 _node_sum (Node *head, u64 acc)
{
	if (not head)
		return acc;
	return _node_sum(head->next, acc + head->data);
}

u64 node_sum (Node *head)
{
	return _node_sum(head, 0);
}

void _node_debug (Node *head)
{
	assert(head);
	printf(u64_f, head->data);
	if (head->next)
	{
		printf(", ");
		_node_debug(head->next);
	}
}

void node_debug (Node *head)
{
	if (not head)
	{
		puts("Node: NULL");
		return;
	}

	printf("Node: [ ");
	_node_debug(head);
	printf(" ] \n");
}

/*
 * Data Strucuture: Stack
 * */

typedef struct Stack {
	struct Node *head;
} Stack;

void stack_add (Stack *S, u64 data)
{
	assert(S != NULL);
	Node *new = malloc(sizeof(Node));
	assert(new != NULL);
	new->data = data;
	new->next = S->head;
	S->head = new;
}

void stack_pop (Stack *S)
{
	assert(S != NULL);
	Node *old = S->head;
	assert(old != NULL);
	S->head = old->next;
	free(old);
}

void stack_free (Stack *S)
{
	assert(S != NULL);
	Node *head = S->head;
	while (head)
	{
		head = head->next;
		free(S->head);
		S->head = head;
	}
}

int main(void)
{
	u64 a;
	scanf(u64_f, &a);
	printf(u64_f "\n", a);
}
