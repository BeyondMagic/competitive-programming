/**
	*	author:		beyondmagic
**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>

#define debug(fmt, args...) fprintf(stderr, "\t[debug:%s:%d] " fmt "\n", __func__, __LINE__, ##args)

// -------------------------------------------------------
// Judge defaults and rules.
// ------------------------------------------------------
enum Commands
{
	rotate_left,
	rotate_right,
	walk,
	run_min,
	run_normal,
	run_max,
	sensor_wall,
	sensor_mark
};

// -------------------------------------------------------
// Grid implementation.
// ------------------------------------------------------
struct Position
{
	int x,
		y;
};

enum Room_State
{
	wall,
	blank,
	cheese,
	visited,
};

typedef struct room
{
	enum Room_State state;
	struct room *adjacents;
	struct Position position;
} room;

// -------------------------------------------------------
// Player implementation
// ------------------------------------------------------
enum Entity_State
{
	up,
	right,
	down,
	left,
};

struct Entity
{
	struct Position position;
	enum Entity_State state;
};

struct Entity player = {
	.position = {
		.x = 0,
		.y = 0,
	},
	.state = up,
};

// -------------------------------------------------------
// Data strucutre fundamental (generalised).
// ------------------------------------------------------
struct Node
{
	void *data;
	struct Node *next, *prev;
};

// -------------------------------------------------------
// Stack implementation.
// ------------------------------------------------------
struct Stack
{
	int size;
	struct Node *top;
};

struct Stack *stack_initialise()
{
	return calloc(1, sizeof(struct Stack));
}

bool stack_empty(struct Stack *stack)
{
	assert(stack);
	return stack->size;
}

void *stack_top(struct Stack *stack)
{
	assert(stack);
	return stack->top->data;
}

void stack_push(struct Stack *stack, void *data)
{
	assert(stack and data);
	struct Node *temp = malloc(sizeof(struct Node));
	assert(temp);

	temp->data = data;
	temp->next = stack->top;

	stack->top->prev = temp->next;
	stack->top = temp;

	++stack->size;
}

void stack_pop(struct Stack *stack)
{
	assert(stack and stack->size);
	struct Node *temp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	free(temp);
	--stack->size;
}

void stack_free(struct Stack *stack)
{

	while (not stack_empty(stack))
		stack_pop(stack);
	free(stack);
}

// -------------------------------------------------------
// Queue implementation.
// ------------------------------------------------------
struct Queue
{
	int size;
	struct Node *front, *back;
};

struct Queue *queue_initialise()
{
	return calloc(1, sizeof(struct Queue));
}

bool queue_empty(struct Queue *queue)
{
	assert(queue);
	return queue->size;
}

void queue_push(struct Queue *queue, void *data)
{
	assert(queue and data);
	struct Node *temp = malloc(sizeof(struct Node));
	assert(temp);

	temp->data = data;

	temp->next = NULL;

	if (queue_empty(queue))
	{
		temp->prev = NULL;
		queue->front = queue->back = temp;
		return;
	}

	temp->prev = queue->back;
	queue->back->next = temp;

	queue->back = temp;

	++queue->size;
}

void *queue_front(struct Queue *queue)
{
	assert(queue and queue->front);
	return queue->front->data;
}

void queue_pop(struct Queue *queue)
{
	assert(queue and queue->front and queue->back);
	struct Node *temp = queue->front;
	queue->front = queue->front->next;
	queue->front->prev = NULL;
	free(temp);
}

void queue_free(struct Queue *queue)
{
	while (not queue_empty(queue))
		queue_pop(queue);
	free(queue);
}

// -------------------------------------------------------
// List implementation.
// ------------------------------------------------------
struct List
{
	int size;
	struct Node *front, *back;
};

struct List *list_initialise()
{
	return calloc(1, sizeof(struct List));
}

bool list_empty(struct List *list)
{
	return list->size;
}

// -------------------------------------------------------
int send_command(enum Commands id)
{
	char command;
	switch (id)
	{
		case rotate_left:
			command = 'l';
			break;
		case rotate_right:
			command = 'r';
			break;
		case walk:
			command = 'w';
			break;
		case run_min:
			command = 'j';
			break;
		case run_normal:
			command = 'R';
			break;
		case run_max:
			command = 's';
			break;
		case sensor_wall:
			command = 'c';
			break;
		case sensor_mark:
			command = 'd';
			break;
	}
	printf("%c\n", command);
	fflush(stdout);

	int result;
	scanf("%d", &result);
	fflush(stdin);

	return result;
};

int main (void)
{

}
