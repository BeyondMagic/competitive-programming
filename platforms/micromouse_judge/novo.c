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
	unknown,
};

typedef struct Room
{
	enum Room_State state;
	struct Room **adjacents;
	struct Position position;
} Room;

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

enum General_Direction
{
	horizontal,
	vertical
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
	free(temp->data);
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
	if (queue->front)
		queue->front->prev = NULL;
	else
		queue->back = NULL;
	free(temp->data);
	free(temp);
	--queue->size;
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

void list_insert_front(struct List *list, void *data)
{
	assert(list and data);
	struct Node *temp = malloc(sizeof(struct Node));

	temp->data = data;
	temp->prev = NULL;
	temp->next = list->front;

	if (list->front)
		list->front->prev = temp;

	list->front = temp;

	if (not list->back)
		list->back = temp;

	++list->size;
}

void list_insert_back(struct List *list, void *data)
{
	assert(list and data);
	struct Node *temp = malloc(sizeof(struct Node));

	temp->data = data;
	temp->prev = list->back;
	temp->next = NULL;

	if (list->back)
		list->back->next = temp;

	list->back = temp;

	if (not list->front)
		list->front = temp;

	++list->size;
}

void list_pop_front(struct List *list)
{
	assert(list and list->front and list->back);
	struct Node *temp = list->front;
	list->front = list->front->next;
	list->front->prev = NULL;
	free(temp->data);
	free(temp);
}

void list_pop_back(struct List *list)
{
	assert(list and list->front and list->back);
	struct Node *temp = list->back;
	list->back = list->back->prev;
	list->back->next = NULL;
	free(temp->data);
	free(temp);
}

bool list_find(struct List *list, bool (*compare) (void *, void *), void *x)
{
	assert(list);
	struct Node *N = list->front;
	while (N)
	{
		if (compare(N->data, x))
			return true;
		N = N->next;
	}
	return false;
}

struct List *positions_passed, *possible_cheese;

// --------------------------
// Debug functions.
// --------------------------

char *room_state_string(enum Room_State state)
{
	static char *s_wall = "wall",
				*s_cheese = "cheese",
				*s_blank = "blank",
				*s_visited = "visited",
				*s_unknown = "unknown";

	switch (state)
	{
		case wall:
			return s_wall;
		case cheese:
			return s_cheese;
		case blank:
			return s_blank;
		case visited:
			return s_visited;
		case unknown:
			return s_unknown;
	}
}

void print_room_situation(Room *u)
{
	debug("This room u at (%d, %d)", u->position.x, u->position.y);
	debug("Its children are:");
	if (u->adjacents[up])
		debug("\t\tu->adjacents[up]->state: %s", room_state_string(u->adjacents[up]->state));
	if (u->adjacents[right])
		debug("\t\tu->adjacents[right]->state: %s", room_state_string(u->adjacents[right]->state));
	if (u->adjacents[down])
		debug("\t\tu->adjacents[down]->state: %s", room_state_string(u->adjacents[down]->state));
	if (u->adjacents[left])
		debug("\t\tu->adjacents[left]->state: %s", room_state_string(u->adjacents[left]->state));
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

void destroy_grid(Room *u)
{
	struct Queue *Q = queue_initialise();
	queue_push(Q, u);

	while (not queue_empty(Q))
	{
		u = queue_front(Q);
		queue_pop(Q);

		for (enum Entity_State direction = up;;)
		{
			if (u->adjacents[direction])
				u->adjacents[direction]->adjacents[(direction + 2) % 4] = NULL,
				queue_push(Q, u->adjacents[direction]);

			if (++direction == up)
				break;
		}

		free(u);
	}

	queue_free(Q);
}

Room *create_room(enum Room_State state, Room *r_up, Room *r_right, Room *r_down, Room *r_left, int x, int y)
{
	Room *u = malloc(sizeof(Room));

	u->state = state;
	u->adjacents = malloc(sizeof(Room *) * 4);
	u->adjacents[up] = r_up;
	u->adjacents[right] = r_right;
	u->adjacents[down] = r_down;
	u->adjacents[left] = r_left;
	u->position.x = x;
	u->position.y = y;

	return u;
}

void read_sensor(Room *u, int result)
{
	if (not u->adjacents[up])
		u->adjacents[up] = create_room(unknown, NULL, NULL, u, NULL, u->position.x, u->position.y + 1);

	if (not u->adjacents[right])
		u->adjacents[right] = create_room(unknown, NULL, NULL, NULL, u, u->position.x + 1, u->position.y);

	if (not u->adjacents[down])
		u->adjacents[down] = create_room(unknown, u, NULL, NULL, NULL, u->position.x, u->position.y - 1);

	if (not u->adjacents[left])
		u->adjacents[left] = create_room(unknown, NULL, u, NULL, NULL, u->position.x - 1, u->position.y);

	int i = 1;
	enum Entity_State orig = player.state;
	do {
		if (u->adjacents[player.state]->state == unknown)
			u->adjacents[player.state]->state = result & i ? blank : wall;
		i <<= 1;
	} while (++player.state != orig);
	player.state = orig;
}

Room *create_adjacent_room(Room *u, enum Entity_State direction)
{
	switch (direction)
	{
		case up:
			if (not u->adjacents[up])
				u->adjacents[up] = create_room(unknown, NULL, NULL, u, NULL, player.position.x, player.position.y + 1);
			return u->adjacents[up];
		case right:
			if (not u->adjacents[right])
				u->adjacents[right] = create_room(unknown, NULL, NULL, NULL, u, player.position.x + 1, player.position.y);
			return u->adjacents[right];
		case down:
			if (not u->adjacents[down])
				u->adjacents[down] = create_room(unknown, u, NULL, NULL, NULL, player.position.x, player.position.y - 1);
			return u->adjacents[down];
		case left:
			if (not u->adjacents[left])
				u->adjacents[left] = create_room(unknown, u, NULL, NULL, NULL, player.position.x - 1, player.position.y);
			return u->adjacents[left];
	}
}

void Change_direction(enum Entity_State direction)
{
	if (player.state == direction)
		return;

	if (
			(player.state == down and direction == up) or
			(player.state == up and direction == down) or
			(player.state == left and direction == right) or
			(player.state == right and direction == left)
		)
		send_command(rotate_right),
		send_command(rotate_right);

	else if (
		(player.state == up and direction == left) or
		(player.state == left and direction == down) or
		(player.state == right and direction == up) or
		(player.state == down and direction == right)
		)
		send_command(rotate_left);

	else if (
		(player.state == up and direction == right) or
		(player.state == right and direction == down) or
		(player.state == down and direction == left) or
		(player.state == left and direction == up)
		)
		send_command(rotate_right);

	player.state = direction;
}

void Walk(Room *u)
{
	u = create_adjacent_room(u, player.state);

	switch (player.state)
	{
		case up: ++player.position.y; break;
		case right: ++player.position.x; break;
		case down: --player.position.y; break;
		case left: --player.position.x; break;
	}

	switch (send_command(walk))
	{
		// Found cheese.
		case 2:
			u->state = cheese;
		case 1:
			u->state = blank;
			break;
		case 0:
			debug("Walked into wall, dumb!");
			assert(false);
			break;
	}

	print_room_situation(u);
}

struct Position bias_calculator()
{
	struct Position bias = {.x = 0, .y = 0};

	struct Position *d;
	struct Node *p = possible_cheese->front;
	while (p)
	{
		d = p->data;
		bias.x += player.position.x - d->x;
		bias.y += player.position.y - d->y;
		p = p->next;
	}

	return bias;
}

bool change_direction_bias(Room *u)
{
	struct Position bias = bias_calculator();
}

int main (void)
{
}
