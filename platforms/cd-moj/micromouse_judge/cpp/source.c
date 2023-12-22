/**
	*	author:		beyondmagic
**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// ------------------------------------------
// Logic
// ------------------------------------------
#define and &&
#define or ||
#define not !

// ------------------------------------------
// Commands
// ------------------------------------------
#define ROTATE_LEFT 'l'
#define ROTATE_RIGHT 'r'
#define WALK 'w'
#define RUN_MIN 'j'
#define RUN_NORMAL 'R'
#define RUN_MAX 's'
#define SENSOR_WALL 'c'
#define SENSOR_MARK 'd'
#define FOUND_CHEESE 2

// ------------------------------------------
// Grid and player positions and style.
// ------------------------------------------
#define MARK 'X'
#define C_LEFT '<'
#define C_RIGHT '>'
#define C_UP '^'
#define C_DOWN '_'
#define C_UNKNOWN '?'
#define BLANK ' '
#define WALL '#'
#define CHEESE 'X'
#define START 'o'

enum node_state {
	blank,
	wall,
	cheese,
	visited,
	unknown,
	_free,
};

typedef struct node {
	enum node_state state;
	struct node *up,
		 *rightt,
		 *down,
		 *leftt;
	int x,
		y;
} node;

enum entity_state {
	up,
	rightt,
	down,
	leftt,
	unknownn,
};

typedef struct {
	int x;
	int y;
	enum entity_state state;
} entity;

typedef struct {
	int max_x, min_x;
	int max_y, min_y;
} limit;

entity player = {
	.x = 0,
	.y = 0,
	.state = up,
};

limit grid_limit = {
	.max_x = 0,
	.min_x = 0,
	.max_y = 0,
	.min_y = 0,
};

typedef struct position {
	int x;
	int y;
} position;

typedef struct pair_char_entity {
	char c;
	enum entity_state es;
} pair_char_entity;

// ------------------------------------------
// Stack implementation for pair_char_entity.
// ------------------------------------------
struct Node_PCE {
	pair_char_entity data;
	struct Node_PCE *link;
};

struct Stack_PCE {
	struct Node_PCE *top;
};

struct Stack_PCE *stack_pce_initialise()
{
	struct Stack_PCE *S = malloc(sizeof(struct Stack_PCE));
	S->top = NULL;
	return S;
}

bool stack_pce_is_empty(struct Stack_PCE *S)
{
	return S->top == NULL;
}

pair_char_entity stack_pce_top(struct Stack_PCE *S)
{
	if (!S->top)
		return (pair_char_entity){.c = '\0', .es = unknownn};
	return S->top->data;
}

bool stack_pce_push(struct Stack_PCE *S, const pair_char_entity data)
{
	struct Node_PCE *temp = malloc(sizeof(struct Node_PCE));

	if (not temp)
		return false;

	temp->data.c = data.c;
	temp->data.es = data.es;
	temp->link = S->top;
	S->top = temp;

	return true;
}

bool stack_pce_pop(struct Stack_PCE *S)
{
	if (not S->top)
		return false;

	struct Node_PCE *temp = S->top;
	S->top = S->top->link;

	return free(temp), true;
}

void stack_pce_destroy(struct Stack_PCE *S)
{
	while (not stack_pce_is_empty(S))
		stack_pce_pop(S);
	free(S);
}

struct Stack_PCE *S, *F;
// stack<pair<char, entity_state>> S, F;

// ------------------------------------------
// Queue implementation for pair_char_entity.
// ------------------------------------------
struct Queue_PCE {
	struct Node_PCE *front, *back;
};

struct Queue_PCE *queue_pce_initialize()
{
	struct Queue_PCE *Q = malloc(sizeof(struct Queue_PCE));

	Q->front = Q->back = NULL;

	return Q;
}

bool queue_pce_is_empty(struct Queue_PCE *Q)
{
	return Q->front == NULL;
}

void queue_pce_push (struct Queue_PCE *Q, const pair_char_entity data)
{
	struct Node_PCE *N = malloc(sizeof(struct Node_PCE));

	N->data = data;
	N->link = NULL;

	if (queue_pce_is_empty(Q))
	{
		Q->front = Q->back = N;
		return;
	}

	Q->back->link = N;
	Q->back = N;
}

pair_char_entity queue_pce_front (struct Queue_PCE *Q)
{
	if (not Q->front)
		return (pair_char_entity){.c = '\0', .es = unknownn};
	return Q->front->data;
}

void queue_pce_pop (struct Queue_PCE *Q)
{
	struct Node_PCE *front = Q->front;
	Q->front = Q->front->link;
	free(front);
}

void queue_pce_destroy (struct Queue_PCE *Q)
{
	while (not queue_pce_is_empty(Q))
		queue_pce_pop(Q);
	free(Q);
}

struct Queue_PCE *C;
// queue<pair<char, entity_state>> C;

// ------------------------------------------
// Queue implementation for node *.
// ------------------------------------------
struct Node_Q_Node {
	node *data;
	struct Node_Q_Node *link;
};

struct Queue_Node {
	struct Node_Q_Node *front, *back;
};

struct Queue_Node *queue_node_initialize()
{
	struct Queue_Node *Q = malloc(sizeof(struct Queue_Node));

	Q->front = Q->back = NULL;

	return Q;
}

bool queue_node_is_empty(struct Queue_Node *Q)
{
	return Q->front == NULL;
}

void queue_node_push (struct Queue_Node *Q, node *data)
{
	struct Node_Q_Node *N = malloc(sizeof(struct Node_Q_Node));

	N->data = data;
	N->link = NULL;

	if (queue_node_is_empty(Q))
	{
		Q->front = Q->back = N;
		return;
	}

	Q->back->link = N;
	Q->back = N;
}

node *queue_node_front (struct Queue_Node *Q)
{
	if (not Q->front)
		return NULL;
	return Q->front->data;
}

void queue_node_pop (struct Queue_Node *Q)
{
	struct Node_Q_Node *front = Q->front;
	Q->front = Q->front->link;
	free(front);
}

void queue_node_destroy (struct Queue_Node *Q)
{
	while (not queue_node_is_empty(Q))
		queue_node_pop(Q);
	free(Q);
}

// ------------------------------------------
// List implementation.
// ------------------------------------------
struct Node_List {
	position data;
	struct Node_List *prev, *next;
};

struct List {
	struct Node_List *front, *back;
};

struct List *list_initialize()
{
	struct List *L = malloc(sizeof(struct List));
	L->front = L->back = NULL;
	return L;
}

bool list_is_empty (struct List *L)
{
	return L->front == NULL;
}

struct Node_List *list_find (struct List *L, position P)
{
	struct Node_List *N = L->front;

	while (N)
	{
		if (N->data.x == P.x and N->data.y == P.y)
			break;

		N = N->next;
	}

	return N;
}

void list_push_front (struct List *L, position P)
{
	if (list_find(L, P))
		return;

	struct Node_List *N = malloc(sizeof(struct Node_List));

	N->data.x = P.x;
	N->data.y = P.y;

	N->next = L->front;
	N->prev = NULL;

	if (L->front)
		L->front->prev = N;

	L->front = N;
}

struct Node_List *list_find_ignore_first (struct List *L, position P)
{
	struct Node_List *N = L->front ? L->front->next : NULL;

	while (N and N->data.x != P.x and N->data.y != P.y)
		N = N->next;

	return N;
}

bool found_possible_cheese = false;

void print_list (struct List *L)
{
	struct Node_List *N = L->front;
	while (N)
		fprintf(stderr, "\t[debug: print_list] (%d, %d)\n", N->data.x, N->data.y),
		N = N->next;
}

void list_pop_front (struct List *L)
{
	struct Node_List *N = L->front;

	if (not N)
		return;

	L->front = N->next;

	if (N->next)
		N->next->prev = N->prev;

	if (N->prev)
		N->prev->next = N->next;

	free(N);
}

void clear_list (struct List *L)
{
	struct Node_List *N = L->front, *T;
	while (N)
	{
		T = N;
		N = T->next;
		free(T);
	}
	L->front = NULL;
	L->back = NULL;
}

void destroy_list (struct List *L)
{
	struct Node_List *N = L->front, *T;
	while (N)
	{
		T = N;
		N = T->next;
		free(T);
	}
	free(L);
}


struct List *positions_passed, *possible_cheese;
// vector<pair<int, int>> positions_passed;
// list<position> possible_cheese;

// If this was a possible place for a cheese, remove it.
//void remove_possible_cheese(position P)
//{
//	list_erase(possible_cheese, P);
//}

// ------------------------------------------
// Relevant code about the algorithm down.
// ------------------------------------------


#define send_command(c) \
	printf("%c\n", c); \
	fflush(stdout); \
	scanf("%d", &result); \
	fflush(stdin)

void destroy_grid (node *grid)
{
	struct Queue_Node *Q = queue_node_initialize();
	// queue<node *> q;

	queue_node_push(Q, grid);
	// q.push(grid);

	while (not queue_node_is_empty(Q))
	// while (not q.empty())
	{
		node *u = queue_node_front(Q);
		// node *u = q.front();

		queue_node_pop(Q);
		// q.pop();

		if (u->state == _free)
			continue;

		// fprintf(stderr, "to free -> (%d, %d)\n", u->x, u->y);

		if (u->up)
			u->up->down = NULL,
			queue_node_push(Q, u->up);
			// q.push(u->up);

		if (u->rightt)
			u->rightt->leftt = NULL,
			queue_node_push(Q, u->rightt);
			// q.push(u->rightt);

		if (u->down)
			u->down->up = NULL,
			queue_node_push(Q, u->down);
			// q.push(u->down);

		if (u->leftt)
			u->leftt->rightt = NULL,
			queue_node_push(Q, u->leftt);
			// q.push(u->leftt);

		u->state = _free;
		free(u);
	}

	queue_node_destroy(Q);
}

// void destroy_grid(node *row)
// {
// 	// 1. Go left and up all the way.
// 	while (row->leftt)
// 		row = row->leftt;
// 	while (row->up)
// 		row = row->up;
// 
// 	// 2. Now save this row.
// 	while (row)
// 	{
// 		node *block = row;
// 		row = row->down;
// 		node *temp;
// 		while (block)
// 		{
// 			temp = block;
// 			block = block->rightt;
// 			free(temp);
// 		}
// 	}
// }

node *create_node(enum node_state state, node *up, node *rightt, node *down, node *leftt, int x, int y)
{
	node *block = malloc(sizeof(node));

	block->state = state;
	block->up = up;
	block->rightt = rightt;
	block->down = down;
	block->leftt = leftt;
	block->x = x;
	block->y = y;

	return block;
}

void print_line_width(char c)
{
	const int width = abs(grid_limit.min_x) + abs(grid_limit.max_x);
	for (int i = 0; i < width; ++i)
		fprintf(stderr, "%c", c);
	fprintf(stderr, "\n");
}

void print_grid(node *row)
{
	print_line_width('_');

	// 1. Go left and up all the way.
	while (row->leftt)
		row = row->leftt;
	while (row->up)
		row = row->up;

	// fprintf(stderr, "row initial: %d, %d\n", row->x, row->y);

	// 2. Now save this row.
	while (row)
	{
		node *block = row;
		for (char c = '$'; block; block = block->rightt)
		{
			if (not block->x and not block->y and (player.y or player.x))
				c = 'C';
			else if (block->x == player.x and block->y == player.y)
				switch (player.state)
				{
					case up:
						c = '^';
						break;
					case rightt:
						c = '>';
						break;
					case down:
						c = '_';
						break;
					case leftt:
						c = '<';
						break;
					case unknownn:
						fprintf(stderr, "[ERROR] Weird it is unknownn!");
						break;
				}
			else
				switch (block->state)
				{
					case visited:
						c = '.';
						break;
					case blank:
						c = ' ';
						break;
					case wall:
						c = '#';
						break;
					case unknown:
						c = '?';
						break;
					// case sensored:
					// 	c = '~';
					// 	break;
					default:
						break;
				}
			fprintf(stderr, "%c", c);
			// fprintf(stderr, "%c (%d,%d)", c, block->x, block->y);
		}
		fprintf(stderr, "\n");
		row = row->down;
	}
	print_line_width('-');
}

// Fix the grid by creating a new row or column.
//void fix(node *block, enum entity_state direction)
//{
//	return;
	// node *aux, *aux2;
	// switch (direction)
	// {
	// 	case up:
	// 		// 1. Go all the way left.
	// 		while (block->leftt)
	// 			block = block->leftt;
	// 		while (block->up)
	// 			block = block->up;

	// 		/// assert(block->x == grid_limit.min_x and block->y == grid_limit.max_y);
	// 		// 2. Create up the node.
	// 		aux = create_node(unknown, NULL, NULL, block, NULL, block->x, block->y + 1);
	// 		block->up = aux;
	// 		while (aux->x != grid_limit.max_x)
	// 		{
	// 			block = block->rightt;
	// 			aux2 = create_node(unknown, NULL, NULL, block, aux, aux->x + 1, aux->y);
	// 			block->up = aux2;
	// 			aux->rightt = aux2;
	// 			aux = aux2;
	// 		}
	// 		// debug("up");
	// 		break;
	// 	case rightt:
	// 		// 1. Go all the way down.
	// 		while (block->down)
	// 			block = block->down;
	// 		while (block->rightt)
	// 			block = block->rightt;
	// 	
	// 		// assert(block->x == grid_limit.max_x and block->y == grid_limit.min_y);
	// 		// 2. Create right the node.
	// 		aux = create_node(unknown, NULL, NULL, NULL, block, block->x + 1, block->y);
	// 		block->rightt = aux;
	// 		while (aux->y != grid_limit.max_y)
	// 		{
	// 			block = block->up;
	// 			aux2 = create_node(unknown, NULL, NULL, aux, block, aux->x, aux->y + 1);
	// 			block->rightt = aux2;
	// 			aux->up = aux2;
	// 			aux = aux2;
	// 		}
	// 		// debug("right");
	// 		break;
	// 	case down:
	// 		// 1. Go all the way left.
	// 		while (block->leftt)
	// 			block = block->leftt;
	// 		while (block->down)
	// 			block = block->down;

	// 		// assert(block->x == grid_limit.min_x and block->y == grid_limit.min_y);
	// 		// 2. Create down the node.
	// 		aux = create_node(unknown, block, NULL, NULL, NULL, block->x, block->y - 1);
	// 		block->down = aux;
	// 		while (aux->x != grid_limit.max_x)
	// 		{
	// 			block = block->rightt;
	// 			aux2 = create_node(unknown, block, NULL, NULL, aux, aux->x + 1, aux->y);
	// 			block->down = aux2;
	// 			aux->rightt = aux2;
	// 			aux = aux2;
	// 		}
	// 		// debug("down");
	// 		break;
	// 	case leftt:
	// 		while (block->leftt)
	// 			block = block->leftt;
	// 		// 1. Go all the way down.
	// 		while (block->down)
	// 			block = block->down;
	// 		// assert(block->x == grid_limit.min_x and block->y == grid_limit.min_y);
	// 		// 2. Create left the node.
	// 		aux = create_node(unknown, NULL, block, NULL, NULL, block->x - 1, block->y);
	// 		block->leftt = aux;
	// 		while (aux->y != grid_limit.max_y)
	// 		{
	// 			block = block->up;
	// 			aux2 = create_node(unknown, NULL, block, aux, NULL, aux->x, aux->y + 1);
	// 			block->leftt = aux2;
	// 			aux->up = aux2;
	// 			aux = aux2;
	// 		}
	// 		// puts("fix: end leftt");
	// 		break;
	// }
// }

void change_direction(enum entity_state direction)
{
	if (player.state == direction)
		return;

	int result;

	// Opposite side.
	if (
			(player.state == down and direction == up) or
			(player.state == up and direction == down) or
			(player.state == leftt and direction == rightt) or
			(player.state == rightt and direction == leftt)
		)
	{
		send_command(ROTATE_RIGHT);
		send_command(ROTATE_RIGHT);
	}

	if (
		(player.state == up and direction == leftt) or
		(player.state == leftt and direction == down) or
		(player.state == rightt and direction == up) or
		(player.state == down and direction == rightt)
		)
	{
		send_command(ROTATE_LEFT);
	}

	if (
		(player.state == up and direction == rightt) or
		(player.state == rightt and direction == down) or
		(player.state == down and direction == leftt) or
		(player.state == leftt and direction == up)
		)
	{
		send_command(ROTATE_RIGHT);
	}

	player.state = direction;
}

void possible_cheese_add_positions (struct List *list, int dist, entity play)
{
	position P;
	// ++dist;

	for (int x = play.x + dist, y = play.y;; --x, ++y)
	{
		P.x = x;
		P.y = y;
		if (list_find(possible_cheese, P))
			list_push_front(list, P);

		if (x == play.x)
			break;
	}

	print_list(list);

	for (int x = play.x - dist, y = play.y;; ++x, ++y)
	{
		P.x = x;
		P.y = y;
		if (list_find(possible_cheese, P))
			list_push_front(list, P);

		if (x == play.x)
			break;
	}

	print_list(list);

	for (int x = play.x - dist, y = play.y;; ++x, --y)
	{
		P.x = x;
		P.y = y;
		if (list_find(possible_cheese, P))
			list_push_front(list, P);

		if (x == play.x)
			break;
	}
	print_list(list);

	for (int x = play.x + dist, y = play.y;; --x, --y)
	{
		P.x = x;
		P.y = y;
		if (list_find(possible_cheese, P))
			list_push_front(list, P);

		if (x == play.x)
			break;
	}
	print_list(list);
}

void list_erase (struct List *L, position P)
{
	struct Node_List *N = list_find(L, P);

	// if (not N or (N and (N->data.x != P.x or N->data.y != P.y)))
	if (not N)
		return;

	// Encontrei uma possível posição do queijo, N.
	if (not found_possible_cheese)
	{
		found_possible_cheese = true;

		int result, distance_orig, distance;
		send_command(SENSOR_MARK);
		distance_orig = result;

		entity player_new = player;

		// Agora com a distância, descobrimos.
		enum entity_state direction_orig = stack_pce_top(S).es, direction = unknownn;
		switch (direction_orig)
		{
			case up: direction = down; --player_new.y; break;
			case rightt: direction = leftt; --player_new.x; break;
			case down: direction = up; ++player_new.y; break;
			case leftt: direction = rightt; ++player_new.x; break;
			case unknownn: direction = unknownn; break;
		}
		change_direction(direction);
		send_command(WALK);

		send_command(SENSOR_MARK);
		distance = result;
		
		change_direction(direction_orig);
		send_command(WALK);

		struct List *list = list_initialize();
		fprintf(stderr, "[debug] first list being added\n");
		possible_cheese_add_positions(list, distance_orig, player);

		struct List *list_2 = list_initialize();
		fprintf(stderr, "[debug] second list being added\n");
		possible_cheese_add_positions(list_2, distance, player_new);

		fprintf(stderr, "clearing my list\n");
		clear_list(possible_cheese);
		fprintf(stderr, "before acessing looping list\n");
		struct Node_List *A = list->front;
		while (A)
		{
			fprintf(stderr, "searching in second list for N->data\n");
			if (list_find(list_2, A->data))
			{
				fprintf(stderr, "found possible cheese\n");
				list_push_front(possible_cheese, A->data);
			}
			fprintf(stderr, "continue to next (%d, %d)\n", A->data.x, A->data.y);
			A = A->next;
			fprintf(stderr, "before while\n");
		}
		fprintf(stderr, "queijo agora com certeza está\n");
		print_list(possible_cheese);

		return;
	}

	if (N->next)
		N->next->prev = N->prev;

	if (N->prev)
		N->prev->next = N->next;

	free(N);
}

// Read sensor given the player direction.
void read_sensor(enum entity_state direction, node *block, int result)
{
	if (block->x - 1 < grid_limit.min_x)
		--grid_limit.min_x;
		// fix(block, leftt);

	if (block->x + 1 > grid_limit.max_x)
		++grid_limit.max_x;
		// fix(block, rightt);

	if (block->y - 1 < grid_limit.min_y)
		--grid_limit.min_y;
		//fix(block, down);

	if (block->y + 1 > grid_limit.max_y)
		++grid_limit.max_y;
		// fix(block, up);

	if (not block->up)
	{
		block->up = create_node(unknown, NULL, NULL, block, NULL, block->x, block->y + 1);
		// fprintf(stderr, "sensor: grid->up created with (%d, %d)\n", block->up->x, block->up->y);
	}
	if (not block->rightt)
	{
		block->rightt = create_node(unknown, NULL, NULL, NULL, block, block->x + 1, block->y);
		// fprintf(stderr, "sensor: grid->rightt created with (%d, %d)\n", block->rightt->x, block->rightt->y);
	}
	if (not block->down)
	{
		block->down = create_node(unknown, block, NULL, NULL, NULL, block->x, block->y - 1);
		// fprintf(stderr, "sensor: grid->down created with (%d, %d)\n", block->down->x, block->down->y);
	}
	if (not block->leftt)
	{
		block->leftt = create_node(unknown, NULL, block, NULL, NULL, block->x - 1, block->y);
		// fprintf(stderr, "sensor: grid->leftt created with (%d, %d)\n", block->leftt->x, block->leftt->y);
	}

	switch (direction)
	{
		case up:
			if (block->up->state == unknown)
			{
				block->up->state     = result & 1 ? blank : wall;
				if (block->up->state == blank and list_find(possible_cheese, (position){.x = block->up->x, .y = block->up->y}))
					change_direction(up);
			}
			if (block->rightt->state == unknown)
			{
				block->rightt->state = result & 2 ? blank : wall;
				if (block->rightt->state == blank and list_find(possible_cheese, (position){.x = block->rightt->x, .y = block->rightt->y}))
					change_direction(rightt);
			}
			if (block->down->state == unknown)
			{
				block->down->state   = result & 4 ? blank : wall;
				if (block->down->state == blank and list_find(possible_cheese, (position){.x = block->down->x, .y = block->down->y}))
					change_direction(down);
			}
			if (block->leftt->state == unknown)
			{
				block->leftt->state  = result & 8 ? blank : wall;
				if (block->leftt->state == blank and list_find(possible_cheese, (position){.x = block->leftt->x, .y = block->leftt->y}))
					change_direction(leftt);
			}
			break;
		case rightt:
			if (block->rightt->state == unknown)
			{
				block->rightt->state = result & 1 ? blank : wall;
				if (block->rightt->state == blank and list_find(possible_cheese, (position){.x = block->rightt->x, .y = block->rightt->y}))
					change_direction(rightt);
			}

			if (block->down->state == unknown)
			{
				block->down->state   = result & 2 ? blank : wall;
				if (block->down->state == blank and list_find(possible_cheese, (position){.x = block->down->x, .y = block->down->y}))
					change_direction(down);
			}

			if (block->leftt->state == unknown)
			{
				block->leftt->state  = result & 4 ? blank : wall;
				if (block->leftt->state == blank and list_find(possible_cheese, (position){.x = block->leftt->x, .y = block->leftt->y}))
					change_direction(leftt);
			}

			if (block->up->state == unknown)
			{
				block->up->state     = result & 8 ? blank : wall;
				if (block->up->state == blank and list_find(possible_cheese, (position){.x = block->up->x, .y = block->up->y}))
					change_direction(up);
			}

			break;
		case down:
			if (block->down->state == unknown)
			{
				block->down->state   = result & 1 ? blank : wall;
				if (block->down->state == blank and list_find(possible_cheese, (position){.x = block->down->x, .y = block->down->y}))
					change_direction(down);
			}

			if (block->leftt->state == unknown)
			{
				block->leftt->state  = result & 2 ? blank : wall;
				if (block->leftt->state == blank and list_find(possible_cheese, (position){.x = block->leftt->x, .y = block->leftt->y}))
					change_direction(leftt);
			}

			if (block->up->state == unknown)
			{
				block->up->state     = result & 4 ? blank : wall;
				if (block->up->state == blank and list_find(possible_cheese, (position){.x = block->up->x, .y = block->up->y}))
					change_direction(up);
			}

			if (block->rightt->state == unknown)
			{
				block->rightt->state = result & 8 ? blank : wall;
				if (block->rightt->state == blank and list_find(possible_cheese, (position){.x = block->rightt->x, .y = block->rightt->y}))
					change_direction(rightt);
			}

			break;
		case leftt:
			if (block->leftt->state == unknown)
			{
				block->leftt->state  = result & 1 ? blank : wall;
				if (block->leftt->state == blank and list_find(possible_cheese, (position){.x = block->leftt->x, .y = block->leftt->y}))
					change_direction(leftt);
			}

			if (block->up->state == unknown)
			{
				block->up->state     = result & 2 ? blank : wall;
				if (block->up->state == blank and list_find(possible_cheese, (position){.x = block->up->x, .y = block->up->y}))
					change_direction(up);
			}

			if (block->rightt->state == unknown)
			{
				block->rightt->state = result & 4 ? blank : wall;
				if (block->rightt->state == blank and list_find(possible_cheese, (position){.x = block->rightt->x, .y = block->rightt->y}))
					change_direction(rightt);
			}

			if (block->down->state == unknown)
			{
				block->down->state   = result & 8 ? blank : wall;
				if (block->down->state == blank and list_find(possible_cheese, (position){.x = block->down->x, .y = block->down->y}))
					change_direction(down);
			}

			break;
		case unknownn:
			// fprintf(stderr, "[ERROR] Weid coming here, isnt?");
			break;
	}
}

struct Walk_Result {
	node *first;
	int second;
};

bool is_detecting_now = false;

struct Walk_Result walk (node *grid, enum entity_state direction)
{
	node *orig = grid;
	int x = player.x,
		y = player.y;

	change_direction(direction);

	switch (player.state)
	{
		case up:
			++player.y;
			// puts("walk: up");
			if (player.y > grid_limit.max_y)
				grid_limit.max_y = player.y;
				// fix(grid, up);
			if (not grid->up)
			{
				grid->up = create_node(unknown, NULL, NULL, grid, NULL, player.x, player.y);
				// fprintf(stderr, "grid->up created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->up;
			break;

		case rightt:
			++player.x;

			// debug("walk: rightt");
			if (player.x > grid_limit.max_x)
				grid_limit.max_x = player.x;
				// fix(grid, rightt);
			if (not grid->rightt)
			{
				grid->rightt = create_node(unknown, NULL, NULL, NULL, grid, player.x, player.y);
				// fprintf(stderr, "grid->rightt created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->rightt;
			break;

		case down:
			--player.y;

			// debug("walk: down");
			if (player.y < grid_limit.min_y)
				grid_limit.min_y = player.y;
				// fix(grid, down);
			if (not grid->down)
			{
				grid->down = create_node(unknown, grid, NULL, NULL, NULL, player.x, player.y);
				// fprintf(stderr, "grid->down created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->down;
			break;

		case leftt:
			--player.x;

			if (player.x < grid_limit.min_x)
				grid_limit.min_x = player.x;
				// fix(grid, leftt);
			if (not grid->leftt)
			{
				grid->leftt = create_node(unknown, NULL, grid, NULL, NULL, player.x, player.y);
				// fprintf(stderr, "grid->leftt created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->leftt;
			break;

		case unknownn:
			fprintf(stderr, "[ERROR] Why u here??????");
			break;
	}

	// Leave.
	int result;
	send_command(WALK);

	// Remove pitfall.
	if (result == FOUND_CHEESE)
		grid->state = cheese;

	// Hit the wall.
	else if (not result)
	{
		grid->state = wall;
		grid = orig;
		player.x = x;
		player.y = y;
	} else {
		if (not is_detecting_now)
		{
			position P = {.x = grid->x, .y = grid->y};
			// fprintf(stderr, "[debug] before list adding (%d, %d)\n", P.x, P.y);
			list_push_front(positions_passed, P);
			// fprintf(stderr, "[debug] after list\n");
			// positions_passed.emplace_back(grid->x, grid->y);
		}
	}

	struct Walk_Result wr = {.first = grid, .second = result};
	return wr;
}

#define count_zeroes() \
	zeroes = 0; \
	for (int i = 0; i < 4; ++i) \
		zeroes += (result & (1 << i))

#define all_sensor() \
	send_command(SENSOR_WALL); \
	read_sensor(player.state, grid, result); \
	grid->state = visited; \
	count_zeroes()

// print_grid(grid)


node *walker(node *grid)
{
	int result, zeroes;
	all_sensor();

	pair_char_entity pce;

	// S.push(make_pair(SENSOR_WALL, player.state));

	// Base case: we don't have our two-way, three-way, or three-way.
	while ((zeroes == 1) or 
		   (grid->up->state != wall and grid->down->state != wall and grid->leftt->state == wall and grid->rightt->state == wall) or
		   (grid->leftt->state != wall and grid->rightt->state != wall and grid->up->state == wall and grid->down->state == wall)
		)
	{
		if (grid->up->state == blank)
		{
			// fprintf(stderr, "[debug] before walk\n");
			grid = walk(grid, up).first;
			// fprintf(stderr, "[debug] after walk\n");
			pce.c = WALK;
			pce.es = player.state;
			stack_pce_push(S, pce);
			// S.push(make_pair(WALK, player.state));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else if (grid->rightt->state == blank)
		{
			grid = walk(grid, rightt).first;
			pce.c = WALK;
			pce.es = rightt;
			stack_pce_push(S, pce);
			// S.push(make_pair(WALK, rightt));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else if (grid->down->state == blank)
		{
			grid = walk(grid, down).first;
			pce.c = WALK;
			pce.es = down;
			stack_pce_push(S, pce);
			// S.push(make_pair(WALK, down));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else if (grid->leftt->state == blank)
		{
			grid = walk(grid, leftt).first;
			pce.c = WALK;
			pce.es = leftt;
			stack_pce_push(S, pce);
			// S.push(make_pair(WALK, leftt));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else {
			// Go back.
			pce = stack_pce_top(S);
			enum entity_state direction = pce.es;
			// auto [command, direction] = S.top();
			stack_pce_pop(S);
			// S.pop();

			switch (direction)
			{
				case up: change_direction(down); break;
				case rightt: change_direction(leftt); break;
				case down: change_direction(up); break;
				case leftt: change_direction(rightt); break;
				case unknownn: fprintf(stderr, "[ERROR] Do not enter!\n"); break;
			}
			grid = walk(grid, player.state).first;
			if (grid->state == cheese)
				return grid;
		}
	}
	fprintf(stderr, "[debug] leaving walker\n");
	// debug(grid->x, grid->y);

	return grid;
}

#define sense_up() \
		grid = walk(grid, up).first; \
		if (grid->state == cheese) \
			return grid; \
		send_command(SENSOR_MARK); \
\
		if (result < distance) \
			cheese_q.y = true; \
		else \
			cheese_q.y = false


#define sense_rightt() \
		grid = walk(grid, rightt).first; \
		if (grid->state == cheese) \
			return grid; \
		send_command(SENSOR_MARK); \
\
		if (result < distance) \
			cheese_q.x = true; \
		else \
			cheese_q.x = false


#define sense_down() \
		grid = walk(grid, down).first; \
		if (grid->state == cheese) \
			return grid; \
		send_command(SENSOR_MARK); \
\
		if (result < distance) \
			cheese_q.y = false; \
		else \
			cheese_q.y = true


#define sense_leftt() \
		grid = walk(grid, leftt).first; \
		if (grid->state == cheese) \
			return grid; \
		send_command(SENSOR_MARK); \
\
		if (result < distance) \
			cheese_q.x = false; \
		else \
			cheese_q.x = true

// FIXIT: Estou assumindo que toda vez que o de cima for visitado, terá pelo menos um pra direita ou pra esquerda.
// FIXIT: Se caso sairmos em uma distância não favorável, deveriamos ir no caminho oposto se for possível.
node *detector(node *grid)
{
	int result;
	send_command(SENSOR_MARK);
	int distance = result;

	// quadrant of cheese
	position cheese_q = {.x = 0, .y = 0};
	position orig = {.x = player.x, .y = player.y};

	// cima
	if (grid->up->state == visited)
	{
		sense_up();
		grid = walk(grid,down).first;

		// esquerda
		if (grid->leftt->state != wall)
		{
			// S.push(make_pair(WALK, leftt));
			sense_leftt();
			grid = walk(grid, rightt).first;
		// direita
		} else {
			// S.push(make_pair(WALK, rightt));
			sense_rightt();
			grid = walk(grid, leftt).first;
		}

	// direita
	} else if (grid->rightt->state == visited)
	{
		sense_rightt();
		grid = walk(grid, leftt).first;

		// em cima
		if (grid->up->state != wall)
		{
			// S.push(make_pair(WALK, up));
			sense_up();
			grid = walk(grid, down).first;
		// em baixo
		} else {
			// S.push(make_pair(WALK, down));
			sense_down();
			grid = walk(grid, up).first;
		}


	// em baixo
	} else if (grid->down->state == visited) {
		sense_down();
		grid = walk(grid, up).first;

		// esquerda
		if (grid->leftt->state != wall)
		{
			// S.push(make_pair(WALK, leftt));
			sense_leftt();
			grid = walk(grid, rightt).first;
		// direita
		} else {
			// S.push(make_pair(WALK, rightt));
			sense_rightt();
			grid = walk(grid, leftt).first;
		}

	// esquerda
	} else if (grid->leftt->state == visited) {
		sense_leftt();
		grid = walk(grid, rightt).first;

		// em cima
		if (grid->up->state != wall)
		{
			// S.push(make_pair(WALK, up));
			sense_up();
			grid = walk(grid, down).first;
		// em baixo
		} else {
			// S.push(make_pair(WALK, down));
			sense_down();
			grid = walk(grid, up).first;
		}

	// não visited nada
	} else {

		// Eu obrigatoriamente caí em algum desses aqui em baixo.
		// Onde eu usei o sensor.
		// E eu volto para onde eu tava, marcando aquele lá como visitado.
		// Agora que eu já fui em um deles vou prá um dos lados que não seja ele, obviamente.
		if (grid->up->state != wall) {
			sense_up();
			grid = walk(grid, down).first;

			if (grid->rightt->state != wall) {
				// S.push(make_pair(WALK, rightt));
				sense_rightt();
				grid = walk(grid, leftt).first;
			} else if (grid->down->state != wall) {
				// S.push(make_pair(WALK, down));
				sense_down();
				grid = walk(grid, up).first;
			} else if (grid->leftt->state != wall) {
				// S.push(make_pair(WALK, leftt));
				sense_leftt();
				grid = walk(grid, rightt).first;
			}


		} else if (grid->rightt->state != wall) {
			sense_rightt();
			grid = walk(grid, leftt).first;

			if (grid->up->state != wall) {
				// S.push(make_pair(WALK, up));
				sense_up();
				grid = walk(grid, down).first;
			} else if (grid->down->state != wall) {
				// S.push(make_pair(WALK, down));
				sense_down();
				grid = walk(grid, up).first;
			} else if (grid->leftt->state != wall) {
				// S.push(make_pair(WALK, leftt));
				sense_leftt();
				grid = walk(grid, rightt).first;
			}

		} else if (grid->down->state != wall) {
			sense_down();
			grid = walk(grid, up).first;

			if (grid->up->state != wall) {
				// S.push(make_pair(WALK, up));
				sense_up();
				grid = walk(grid, down).first;
			} else if (grid->rightt->state != wall) {
				// S.push(make_pair(WALK, rightt));
				sense_rightt();
				grid = walk(grid, leftt).first;
			} else if (grid->leftt->state != wall) {
				// S.push(make_pair(WALK, leftt));
				sense_leftt();
				grid = walk(grid, rightt).first;
			}
		} else if (grid->leftt->state != wall) {
			sense_leftt();
			grid = walk(grid, rightt).first;

			if (grid->up->state != wall) {
				// S.push(make_pair(WALK, up));
				sense_up();
				grid = walk(grid, down).first;
			} else if (grid->rightt->state != wall) {
				// S.push(make_pair(WALK, rightt));
				sense_rightt();
				grid = walk(grid, leftt).first;
			} else if (grid->down->state != wall) {
				// S.push(make_pair(WALK, down));
				sense_down();
				grid = walk(grid, up).first;
			}
		}

	}

	// fprintf(stderr, "cheese quadrant: %d and %d\n", cheese_q.x, cheese_q.y);
	position P;
	// ++distance;
	for (int x = orig.x + distance, y = orig.y; ;--x, ++y)
	{
		P.x = x * (cheese_q.x ? 1 : -1);
		P.y = y * (cheese_q.y ? 1 : -1);
		list_push_front(possible_cheese, P);
		// fprintf(stderr, "\t[debug] Possible cheese at (%d, %d)\n", P.x, P.y);

		// possible_cheese.push_back({.x = x * (cheese_q.x ? 1 : -1), .y = y * (cheese_q.y ? 1 : -1)});
		if (x == orig.x)
			break;
	}
	print_list(possible_cheese);

	return grid;
}

// If |x| > |y| or (x != 0 and y == 0), x has priority.
// If |y| > |x| or (y != 0 and x == 0), y has priority.
// If x is negative, go right, else left.
// If y is negative, go up, else down;
// If x == 0 and y == 0, does not matter.
position bias_calculator()
{
	position bias = {.x = 0, .y = 0};

	struct Node_List *P = possible_cheese->front;
	while (P)
	{
		bias.x += player.x - P->data.x;
		bias.y += player.y - P->data.y;
		// fprintf(stderr, "\t[debug] Bias is growing (%d, %d)\n", bias.x, bias.y);
		P = P->next;
	}

	// for (auto [x, y] : possible_cheese)
	// 	bias.x -= x,
	// 	bias.y -= y;

	return bias;
}

bool bias_direction(node *block, position bias)
{
	// X has priority
	if (abs(bias.x) > abs(bias.y) or (bias.x and not bias.y)) {
		// go right
		if (bias.x < 0) {
			if (block->rightt->state == blank) {
				change_direction(rightt);
				return true;
			} else {
				// go up
				if (bias.y <= 0) {
					if (block->up->state == blank) {
						change_direction(up);
						return true;
					} else if (block->leftt->state == blank) {
						change_direction(leftt);
						return true;
					} else if (block->down->state == blank) {
						change_direction(down);
						return true;
					}
				// go down
				} else if (bias.y > 0) {
					if (block->down->state == blank) {
						change_direction(down);
						return true;
					} else if (block->leftt->state == blank) {
						change_direction(leftt);
						return true;
					} else if (block->up->state == blank) {
						change_direction(up);
						return true;
					}
				}
			}
		// go leftt
		} else {
			if (block->leftt->state == blank) {
				change_direction(leftt);
				return true;
			} else {
				// go up
				if (bias.y <= 0) {
					if (block->up->state == blank) {
						change_direction(up);
						return true;
					} else if (block->rightt->state == blank) {
						change_direction(rightt);
						return true;
					} else if (block->down->state == blank) {
						change_direction(down);
						return true;
					}
				// go down
				} else if (bias.y > 0) {
					if (block->down->state == blank) {
						change_direction(down);
						return true;
					} else if (block->rightt->state == blank) {
						change_direction(rightt);
						return true;
					} else if (block->up->state == blank) {
						change_direction(up);
						return true;
					}
				}
			}
		}
	// Y has priority
	} else if (abs(bias.y) > abs(bias.x) or (bias.y and not bias.x)) {
		// go up
		if (bias.y < 0) {
			if (block->up->state == blank) {
				change_direction(up);
				return true;
			} else {
				// go right
				if (bias.x <= 0) {
					if (block->rightt->state == blank) {
						change_direction(rightt);
						return true;
					} else if (block->down->state == blank) {
						change_direction(down);
						return true;
					} else if (block->leftt->state == blank) {
						change_direction(leftt);
						return true;
					}
				// go left
				} else if (bias.x > 0) {
					if (block->leftt->state == blank) {
						change_direction(leftt);
						return true;
					} else if (block->down->state == blank) {
						change_direction(down);
						return true;
					} else if (block->rightt->state == blank) {
						change_direction(rightt);
						return true;
					}
				// does not matter
				}
			}
		// go down
		} else {
			if (block->down->state == blank) {
				change_direction(down);
				return true;
			} else {
				// go right
				if (bias.x <= 0) {
					if (block->rightt->state == blank) {
						change_direction(rightt);
						return true;
					} else if (block->up->state == blank) {
						change_direction(up);
						return true;
					} else if (block->leftt->state == blank) {
						change_direction(leftt);
						return true;
					}
				// go left
				} else if (bias.x > 0) {
					if (block->leftt->state == blank) {
						change_direction(leftt);
						return true;
					} else if (block->up->state == blank) {
						change_direction(up);
						return true;
					} else if (block->rightt->state == blank) {
						change_direction(rightt);
						return true;
					}
				}
			}
		}

	// Y is negative or positive.
	} else if (bias.y != 0) {
		// go up
		if (bias.y < 0)
		{
			if (block->up->state == blank)
			{
				change_direction(up);
				return true;
			// go right
			} else if (bias.x < 0) {
				if (block->rightt->state == blank)
				{
					change_direction(rightt);
					return true;
				} else if (block->leftt->state == blank)
				{
					change_direction(leftt);
					return true;
				} else if (block->down->state == blank)
				{
					change_direction(down);
					return true;
				}
			// go left
			} else {
				if (block->leftt->state == blank)
				{
					change_direction(leftt);
					return true;
				} else if (block->rightt->state == blank)
				{
					change_direction(rightt);
					return true;
				} else if (block->down->state == blank)
				{
					change_direction(down);
					return true;
				}
			}
		// go down
		} else {
			if (block->down->state == blank)
			{
				change_direction(down);
				return true;
			// go right
			} else if (bias.x < 0) {
				if (block->rightt->state == blank)
				{
					change_direction(rightt);
					return true;
				} else if (block->leftt->state == blank)
				{
					change_direction(leftt);
					return true;
				} else if (block->up->state == blank)
				{
					change_direction(up);
					return true;
				}
			// go left
			} else {
				if (block->leftt->state == blank)
				{
					change_direction(leftt);
					return true;
				} else if (block->rightt->state == blank)
				{
					change_direction(rightt);
					return true;
				} else if (block->up->state == blank)
				{
					change_direction(up);
					return true;
				}
			}
		}

	// Y == X and X == 0, does not matter which way
	} else {
		if (block->up->state == blank) {
			change_direction(up);
			return true;
		} else if (block->rightt->state == blank) {
			change_direction(rightt);
			return true;
		} else if (block->down->state == blank) {
			change_direction(down);
			return true;
		} else if (block->leftt->state == blank) {
			change_direction(leftt);
			return true;
		}
	}
	return false;
}

void print_queue()
{
	struct Node_PCE *t = C->front;
	// queue<pair<char, entity_state>> Q = C;

	pair_char_entity pce;
	fprintf(stderr, "Queue C = {\n");

	// while (not Q.empty())
	while (t)
	{
		pce = t->data;

		char dir;
		switch (pce.es)
		{
			case up: dir = '^'; break;
			case leftt: dir = '<'; break;
			case down: dir = 'v'; break;
			case rightt: dir = '>'; break;
			case unknownn: default: dir = '?'; break;
		}
		fprintf(stderr, "\t( %c, %c )\n", pce.c, dir);

		t = t->link;
	}
	fprintf(stderr, "}\n");
}

void print_stack(struct Stack_PCE *S)
{
	struct Node_PCE *t = S->top;
	pair_char_entity pce;

	fprintf(stderr, "Stack = {\n");
	while (t)
	{
		pce = t->data;

		char dir;
		switch (pce.es)
		{
			case up: dir = '^'; break;
			case leftt: dir = '<'; break;
			case down: dir = 'v'; break;
			case rightt: dir = '>'; break;
			case unknownn: default: dir = '?'; break;
		}
		fprintf(stderr, "\t( %c, %c )\n", pce.c, dir);

		t = t->link;
	}
	fprintf(stderr, "}\n");
}

node *misser_hitter(node *block)
{
	int result = 1;
	node *aux = block;
	struct Walk_Result pc;
	struct pair_char_entity pce;

	position P;

	while (true)
	{
		// Process, visit.
		block->state = visited;

		bool found_same = false;
		
		// 1. Walk while I can.
		while (true)
		{
			// -----------------------------------------------
			// VERIFY if this way is going to be on the list.
			// -----------------------------------------------
			switch (player.state)
			{
				case up:
					P.y = block->y + 1;
					P.x = block->x;
					break;
				case rightt:
					P.y = block->y;
					P.x = block->x + 1;
					break;
				case down:
					P.y = block->y - 1;
					P.x = block->x;
					break;
				default:
				case leftt:
					P.y = block->y;
					P.x = block->x - 1;
					break;
			}
			// fprintf(stderr, "[debug:print_list] to search (%d, %d)\n", P.x, P.y);
			struct Node_List *N = list_find(positions_passed, P);
			// -----------------------------------------------

			// fprintf(stderr, "[debug:print_list] before walk\n");
			// print_list(positions_passed);
			pc = walk(block, player.state);
			// fprintf(stderr, "[debug:print_list] after walk\n");
			// print_list(positions_passed);
			// auto pc = walk(block, player.state);
			aux = pc.first;

			// fprintf(stderr, "Tried to walk in, I am in block (%d, %d)\n", aux->x, aux->y);

			// If hit, leave.
			if (not pc.second or aux == block)
			{
				block = aux;
				break;
			}
			 else if (aux->x or aux->y) {

				// When it is not the last, to adjust to the prev above and below.
				if (N)
				// if (f_it != prev(end(positions_passed)))
				{
					if (aux->state != cheese)
						list_erase(possible_cheese, P);

					fprintf(stderr, "Found the same position: (%d, %d)\n", aux->x, aux->y);
					block = aux;
					block->state = visited;
					// Save the last dumb walk.
					pce.c = WALK;
					pce.es = player.state;
					stack_pce_push(S, pce);
					// S.push(make_pair(WALK, player.state));
					// print_stack(S);
					found_same = true;
					break;
				}

			 	// auto f_it = find(begin(positions_passed), prev(end(positions_passed)), make_pair(aux->x, aux->y));

			 }

			// If we went back to the start, clean the stack.
			if (not aux->x and not aux->y)
			{
				found_same = true;
				block = aux;
				block->state = visited;

				pce.c = WALK;
				pce.es = player.state;
				stack_pce_push(S, pce);

				// S.push(make_pair(WALK, player.state));

				break;
			}
			else {
				// Save all the walks and its directions.
				pce.c = WALK;
				pce.es = player.state;

				stack_pce_push(S, pce);

				// S.push(make_pair(WALK, player.state));
			}

			// print_stack();

			if (aux->state == cheese)
			{
				// fprintf(stderr, "cheese found: %d, %d\n", aux->x, aux->y);
				return aux;
			}

			block = aux;
			block->state = visited;
			list_erase(possible_cheese, (position){.x = block->x, .y = block->y});
			// remove_possible_cheese(block);
			// print_grid(block);

			// Is it good to verify the way?
			if (not block->up or not block->rightt or not block->down or not block->leftt or not block->up or 
				(block->up and block->up->state == unknown) or
				(block->rightt and block->rightt->state == unknown) or
				(block->down and block->down->state == unknown) or
				(block->leftt and block->leftt->state == unknown)
				)
			{
				send_command(SENSOR_WALL);
				read_sensor(player.state, block, result);
			}

			// if (player.state == up and block->up->state == blank) continue;
			// else if (player.state == rightt and block->rightt->state == blank) continue;
			// else if (player.state == down and block->down->state == blank) continue;
			// else if (player.state == leftt and block->leftt->state == blank) continue;

			if (bias_direction(block, bias_calculator()))
				continue;

		}

		position bias;

		// We just hit our head. Sensor around.
		if (not found_same)
		{
			if (not block->up or not block->rightt or not block->down or not block->leftt or not block->up or 
				(block->up and block->up->state == unknown) or
				(block->rightt and block->rightt->state == unknown) or
				(block->down and block->down->state == unknown) or
				(block->leftt and block->leftt->state == unknown)
				)
			{
				send_command(SENSOR_WALL);
				read_sensor(player.state, block, result);
				// print_grid(block);
				// count_zeroes();
			}

			// Bias treatment.
			bias = bias_calculator();
			// fprintf(stderr, "\t1. Bias: (%d, %d)\n", bias.x, bias.y);
			
			if (bias_direction(block, bias))
				continue;
		}

		// Base case: we need to go back, this way is useless.
		// Algorithm: we go back one by one, sensoring around.
		// TODO: optimise the way back.

		// while (not S.empty())	
		while (not stack_pce_is_empty(S))
		{
			pce = stack_pce_top(S);
			// char command = pce.c;
			enum entity_state direction = pce.es;
			// auto [command, direction] = S.top();

			stack_pce_pop(S);
			// S.pop();
			
			// print_stack(S);

			switch (direction)
			{
				case up: direction = down; break;
				case rightt: direction = leftt; break;
				case down: direction = up; break;
				case leftt: direction = rightt; break;
				case unknownn: direction = unknownn; break;
			}
			block = walk(block, direction).first;
			if (block->state == cheese)
				return block;

			// print_list(possible_cheese);
			list_erase(possible_cheese, (position){.x = block->x, .y = block->y});
			// remove_possible_cheese(block);
			// print_list(possible_cheese);

			// Already sensored.
			// FIXIT: We don't continue...
			if (block->up and block->rightt and block->down and block->leftt and block->up->state != unknown and block->rightt->state != unknown and block->down->state != unknown and block->leftt->state != unknown)
			{
				bias = bias_calculator();
				// fprintf(stderr, "\t2. Bias: (%d, %d)\n", bias.x, bias.y);
				if (bias_direction(block, bias))
					break;
				else
					continue;
			}
			// else {
			// 	fprintf(stderr, "This block was not sensored? (%d, %d)\n", block->x, block->y);
			// 	if (not block->up) fprintf(stderr, "\tblock->up not existent!\n");
			// 	if (not block->rightt) fprintf(stderr, "\tblock->rightt not existent!\n");
			// 	if (not block->down) fprintf(stderr, "\tblock->down not existent!\n");
			// 	if (not block->leftt) fprintf(stderr, "\tblock->leftt not existent!\n");
			// }

			// Sensor around.
			send_command(SENSOR_WALL);
			read_sensor(player.state, block, result);
			// print_grid(block);
			bias = bias_calculator();
			// fprintf(stderr, "\t3. Bias: (%d, %d)\n", bias.x, bias.y);
			if (bias_direction(block, bias))
			{
				break;
			}
		}
	}
	return block;
}

pair_char_entity better_walk(enum entity_state direction, int k, bool reverse)
{
	// pair<char, entity_state> b;
	pair_char_entity b;

	if (reverse)
		switch (direction)
		{
			case up: b.es = down; break;
			case rightt: b.es = leftt; break;
			case down: b.es = up; break;
			case leftt: b.es = rightt; break;
			case unknownn: b.es = unknownn; break;
		}
	else
		b.es = direction;

	switch (k)
	{
		case 4:
			b.c = RUN_MAX;
			break;
		case 3:
			b.c = RUN_NORMAL;
			break;
		case 2:
			b.c = RUN_MIN;
			break;
		case 1:
			b.c = WALK;
			break;
		default:
			fprintf(stderr, "better_walk: SHOULD NOT ENTER HERE");
			exit(1);
	}

	return b;
}

void compress_flier ()
{
	enum entity_state direction = unknownn;
	int k = 0;

	pair_char_entity P;

	while (not stack_pce_is_empty(S))
	{
		P = stack_pce_top(S);
		stack_pce_pop(S);
		// auto command = S.top();
		// S.pop();

		// First iteration:
		if (not k)
		{
			direction = P.es;
			// direction = P.second,
			++k;

			if (stack_pce_is_empty(S))
				queue_pce_push(C, better_walk(direction, k, true)),
				stack_pce_push(F, better_walk(direction, k, false));

			continue;
		}

		// When it is different, we stop.
		// Or when we already have our limit, four walks.
		// if (command.second != direction or k == 4)
		if (P.es != direction or k == 4)
		{
			queue_pce_push(C, better_walk(direction, k, true));
			stack_pce_push(F, better_walk(direction, k, false));

			// Reset.
			direction = P.es;
			// direction = command.second;
			k = 1;

			// if (empty())
			if (stack_pce_is_empty(S))
				queue_pce_push(C, better_walk(direction, k, true)),
				stack_pce_push(F, better_walk(direction, k, false));

		} else
		{
			++k;

			// if (S.empty())
			if (stack_pce_is_empty(S))
				queue_pce_push(C, better_walk(direction, k, true)),
				stack_pce_push(F, better_walk(direction, k, false));

		}
	}
}

void fly_back()
{
	int result;
	pair_char_entity pce;
	char command;
	enum entity_state direction;

	while (not queue_pce_is_empty(C))
	{
		pce = queue_pce_front(C);
		command = pce.c;
		direction = pce.es;
		// auto [command, direction] = C.front();

		queue_pce_pop(C);
		// C.pop();

		change_direction(direction);
		send_command(command);

		int d = 0;

		switch (command)
		{
			case RUN_MAX: d = 4; break;
			case RUN_NORMAL: d = 3; break;
			case RUN_MIN: d = 2; break;
			case WALK: d = 1; break;
			default:
				fprintf(stderr, "[ERROR] Should not be here!");
		}

		switch (direction)
		{
			case up: player.y += d; break;
			case rightt: player.x += d; break;
			case down: player.y -= d; break;
			case leftt: player.x -= d; break;
			case unknownn: break;
		}
	}

	fprintf(stderr, "[SOL] The player is at (%d, %d)\n", player.x, player.y);
}

void fly_to_cheese()
{
	int result;
	pair_char_entity pce;
	char command;
	enum entity_state direction;

	while (not stack_pce_is_empty(F))
	{
		pce = stack_pce_top(F);
		command = pce.c;
		direction = pce.es;
		// auto [command, direction] = F.top();

		stack_pce_pop(F);
		//F.pop();

		change_direction(direction);
		send_command(command);

		int d = 0;
		switch (command)
		{
			case RUN_MAX: d = 4; break;
			case RUN_NORMAL: d = 3; break;
			case RUN_MIN: d = 2; break;
			case WALK: d = 1; break;
			default:
				d = 0;
				fprintf(stderr, "[ERROR] Should not be here!");
				break;
		}

		switch (direction)
		{
			case up: player.y += d; break;
			case rightt: player.x += d; break;
			case down: player.y -= d; break;
			case leftt: player.x -= d; break;
			case unknownn: break;
		}
	}

	fprintf(stderr, "[SOL] The player is at (%d, %d)\n", player.x, player.y);
}

node *explore(node *grid)
{
	// Algorithm: walker.
	// Purpose: find a two-way node.
	grid = walker(grid);
	if (grid->state != cheese)
	{
		// print_stack();

		// Algorith: detecter.
		// Needs: player to be in two-way node.
		// Purpose: minimise area of where cheese is.
		// Pitfall: Can still be too large, perhaps running it multiple times is better.
		// vector<pair<int, int>> B = positions_passed;
		is_detecting_now = true;
		fprintf(stderr, "[debug] before detector\n");
		grid = detector(grid);
		fprintf(stderr, "[debug] after detector\n");
		is_detecting_now = false;
		grid->state = visited;
		fprintf(stderr, "[debug] before bias direction\n");
		bias_direction(grid, bias_calculator());
		fprintf(stderr, "[debug] after bias direction\n");

		// positions_passed = B;
		// B.clear();

		if (grid->state != cheese)
		{
			// positions_passed.clear();

			// print_stack();

			// auto bias = bias_calculator();
			// fprintf(stderr, "bias : %d, %d\n", bias.x, bias.y);

			// while (not possible_cheese.empty())
			// {
			// 	position pc = possible_cheese.back();
			// 	possible_cheese.pop_back();
			// 	fprintf(stderr, "(%d, %d)\n", pc.x, pc.y);
			// }

			// Algorithm: misser and hitter.
			// Needs: area to hit and walk missing around until back to area.
			// Bias: possible positions of chese.
			// Purpose: find the cheese.
			// Pitfall: may miss too much until back to area.
			// print_grid(grid);
			grid = misser_hitter(grid);
			fprintf(stderr, "[SOL] The goal is at (%d, %d)\n", grid->x, grid->y);
			print_stack(S);
		}
	}

	// Algorithm: searcher.
	// We can sensor wall it and verify for another way?
	//if ((grid->up and grid->up->state == unknown) or
	//	(grid->rightt and grid->rightt->state == unknown) or
	//	(grid->down and grid->down->state == unknown) or
	//	(grid->leftt and grid->leftt->state == unknown))
	//{
	//}
	
	// Algorithm: make flier.
	// Objective: Given a path, compress it to run as fast as it can.
	print_stack(S);
	compress_flier();
	print_queue();

	// Alogorithm: flier.
	// Objective: run as fast as it can given a path.
	fly_back();

	fly_to_cheese();
	print_queue();

	return grid;
}

#define add_stack(d, n) for (int i = 1; i <= n; ++i) stack_pce_push(S, (pair_char_entity){.c = WALK, .es = d})

int main (void)
{
	S = stack_pce_initialise();
	F = stack_pce_initialise();
	C = queue_pce_initialize();
	possible_cheese = list_initialize();
	positions_passed = list_initialize();

	node *grid = create_node(visited, NULL, NULL, NULL, NULL, 0, 0);

	explore(grid);

	// CASE: last run is not getting added.
	// add_stack(up, 7);
	// add_stack(leftt, 2);
	// add_stack(down, 1);
	// add_stack(leftt, 2);
	// add_stack(up, 1);
	// add_stack(rightt, 1);
	// add_stack(up, 2);
	// add_stack(leftt, 2);
	// add_stack(down, 3);
	// add_stack(leftt, 1);
	// add_stack(up, 1);
	// add_stack(leftt, 1);
	// add_stack(up, 2);
	// add_stack(leftt, 2);
	// add_stack(down, 2);

	// print_stack(S);
	// compress_flier();
	// print_queue();
	// print_stack(F);

	stack_pce_destroy(S);
	stack_pce_destroy(F);

	queue_pce_destroy(C);

	// destroy_list(possible_cheese);
	// destroy_list(positions_passed);

	destroy_grid(grid);
}
