#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

static const size_t MAX = 27;
typedef char * Data;

struct Node
{
	char *data;
	struct Node* next;
};

struct Queue
{
	size_t quantity;
	struct Node *front, *back;
};

struct Queue *queue_create ()
{
	struct Queue *queue = malloc(sizeof(struct Queue));

	queue->quantity = 0;
	queue->front = queue->back = NULL;

	return queue;
}

bool queue_is_empty (struct Queue* queue)
{
	return queue->front == NULL;
}

void queue_push_back (struct Queue *queue, Data data)
{
	struct Node *node = malloc(sizeof(struct Node));

	node->data = malloc(sizeof(char) * MAX);
	strcpy(node->data, data);
	node->next = NULL;

	if (queue_is_empty(queue))
	{
		queue->front = queue->back = node;
		return;
	}

	queue->back->next = node;
	queue->back = node;
}

inline bool check(struct Node *node)
{
	return node->next && tolower(node->data[strlen(node->data) - 1]) == tolower(node->next->data[0]);
}

// send next node of this to the last position
void list_node_to_end(struct Queue *queue, struct Node *node)
{
	// ja ta no final
	if (!node || !node->next || !node->next->next)
		return;

	struct Node *last = node->next;
	// move the next one of the one we delete left
	node->next = node->next->next;
	last->next = NULL;
	queue->back->next = last;
	queue->back = last;
}

int main(void)
{
	// read
	char current[MAX];
	struct Queue *queue = queue_create();
	while (scanf("%s", current) != EOF)
		queue_push_back(queue, current);

	/// solve
	struct Node *node = queue->front;
	while (node)
	{
		puts(node->data);
		if (check(node))
			list_node_to_end(queue, node);
		node = node->next;
	}
}
