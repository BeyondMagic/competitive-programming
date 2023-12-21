/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

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

using node = struct node {
	enum node_state state;
	node *up,
		 *rightt,
		 *down,
		 *leftt;
	int x,
		y;
};

enum entity_state {
	up,
	rightt,
	down,
	leftt,
};

using entity = struct {
	int x;
	int y;
	enum entity_state state;
};

using limit = struct {
	int max_x, min_x;
	int max_y, min_y;
};

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

using position = struct position {
	int x;
	int y;
};


stack<pair<char, entity_state>> S, F;
queue<pair<char, entity_state>> C;

vector<pair<int, int>> positions_passed;

#define send_command(c) \
	printf("%c\n", c); \
	fflush(stdout); \
	scanf("%d", &result); \
	fflush(stdin)

void destroy_grid (node *grid)
{
	queue<node *> q;
	q.push(grid);

	while (not q.empty())
	{
		node *u = q.front();
		q.pop();

		if (u->state == _free)
			continue;

		// fprintf(stderr, "to free -> (%d, %d)\n", u->x, u->y);

		if (u->up)
			u->up->down = NULL,
			q.push(u->up);

		if (u->rightt)
			u->rightt->leftt = NULL,
			q.push(u->rightt);

		if (u->down)
			u->down->up = NULL,
			q.push(u->down);

		if (u->leftt)
			u->leftt->rightt = NULL,
			q.push(u->leftt);

		u->state = _free;
		free(u);
	}
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

node *create_node(node_state state, node *up, node *rightt, node *down, node *leftt, int x, int y)
{
	node *block = (node *)malloc(sizeof(node));

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
		for (char c; block; block = block->rightt)
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
void fix(node *block, entity_state direction)
{
	return;
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
}

// Read sensor given the player direction.
void read_sensor(entity_state direction, node *block, int result)
{
	if (block->x - 1 < grid_limit.min_x)
		--grid_limit.min_x,
		fix(block, leftt);

	if (block->x + 1 > grid_limit.max_x)
		++grid_limit.max_x,
		fix(block, rightt);

	if (block->y - 1 < grid_limit.min_y)
		--grid_limit.min_y,
		fix(block, down);

	if (block->y + 1 > grid_limit.max_y)
		++grid_limit.max_y,
		fix(block, up);

	if (not block->up)
	{
		block->up = create_node(unknown, NULL, NULL, block, NULL, block->x, block->y + 1);
		fprintf(stderr, "sensor: grid->up created with (%d, %d)\n", block->up->x, block->up->y);
	}
	if (not block->rightt)
	{
		block->rightt = create_node(unknown, NULL, NULL, NULL, block, block->x + 1, block->y);
		fprintf(stderr, "sensor: grid->rightt created with (%d, %d)\n", block->rightt->x, block->rightt->y);
	}
	if (not block->down)
	{
		block->down = create_node(unknown, block, NULL, NULL, NULL, block->x, block->y - 1);
		fprintf(stderr, "sensor: grid->down created with (%d, %d)\n", block->down->x, block->down->y);
	}
	if (not block->leftt)
	{
		block->leftt = create_node(unknown, NULL, block, NULL, NULL, block->x - 1, block->y);
		fprintf(stderr, "sensor: grid->leftt created with (%d, %d)\n", block->leftt->x, block->leftt->y);
	}

	switch (direction)
	{
		case up:
			if (block->up->state == unknown)
				block->up->state     = result & 1 ? blank : wall;
			if (block->rightt->state == unknown)
				block->rightt->state = result & 2 ? blank : wall;
			if (block->down->state == unknown)
				block->down->state   = result & 4 ? blank : wall;
			if (block->leftt->state == unknown)
				block->leftt->state  = result & 8 ? blank : wall;
			break;
		case rightt:
			if (block->rightt->state == unknown)
				block->rightt->state = result & 1 ? blank : wall;
			if (block->down->state == unknown)
				block->down->state   = result & 2 ? blank : wall;
			if (block->leftt->state == unknown)
				block->leftt->state  = result & 4 ? blank : wall;
			if (block->up->state == unknown)
				block->up->state     = result & 8 ? blank : wall;
			break;
		case down:
			if (block->down->state == unknown)
				block->down->state   = result & 1 ? blank : wall;
			if (block->leftt->state == unknown)
				block->leftt->state  = result & 2 ? blank : wall;
			if (block->up->state == unknown)
				block->up->state     = result & 4 ? blank : wall;
			if (block->rightt->state == unknown)
				block->rightt->state = result & 8 ? blank : wall;
			break;
		case leftt:
			if (block->leftt->state == unknown)
				block->leftt->state  = result & 1 ? blank : wall;
			if (block->up->state == unknown)
				block->up->state     = result & 2 ? blank : wall;
			if (block->rightt->state == unknown)
				block->rightt->state = result & 4 ? blank : wall;
			if (block->down->state == unknown)
				block->down->state   = result & 8 ? blank : wall;
			break;
	}
}

void change_direction(entity_state direction)
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

pair<node *, int> walk (node *grid, entity_state direction)
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
				grid_limit.max_y = player.y,
				fix(grid, up);
			if (not grid->up)
			{
				grid->up = create_node(unknown, NULL, NULL, grid, NULL, player.x, player.y);
				fprintf(stderr, "grid->up created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->up;
			break;

		case rightt:
			++player.x;

			// debug("walk: rightt");
			if (player.x > grid_limit.max_x)
				grid_limit.max_x = player.x,
				fix(grid, rightt);
			if (not grid->rightt)
			{
				grid->rightt = create_node(unknown, NULL, NULL, NULL, grid, player.x, player.y);
				fprintf(stderr, "grid->rightt created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->rightt;
			break;

		case down:
			--player.y;

			// debug("walk: down");
			if (player.y < grid_limit.min_y)
				grid_limit.min_y = player.y,
				fix(grid, down);
			if (not grid->down)
			{
				grid->down = create_node(unknown, grid, NULL, NULL, NULL, player.x, player.y);
				fprintf(stderr, "grid->down created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->down;
			break;

		case leftt:
			--player.x;

			if (player.x < grid_limit.min_x)
				grid_limit.min_x = player.x,
				fix(grid, leftt);
			if (not grid->leftt)
			{
				grid->leftt = create_node(unknown, NULL, grid, NULL, NULL, player.x, player.y);
				fprintf(stderr, "grid->leftt created with (%d, %d)\n", player.x, player.y);
			}
			grid = grid->leftt;
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
	} else
		positions_passed.emplace_back(grid->x, grid->y);

	return make_pair(grid, result);
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

	// S.push(make_pair(SENSOR_WALL, player.state));

	// Base case: we don't have our two-way, three-way, or three-way.
	while ((zeroes == 1) or 
		   (grid->up->state != wall and grid->down->state != wall and grid->leftt->state == wall and grid->rightt->state == wall) or
		   (grid->leftt->state != wall and grid->rightt->state != wall and grid->up->state == wall and grid->down->state == wall)
		)
	{
		if (grid->up->state == blank)
		{
			grid = walk(grid, up).first;
			S.push(make_pair(WALK, player.state));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else if (grid->rightt->state == blank)
		{
			grid = walk(grid, rightt).first;
			S.push(make_pair(WALK, rightt));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else if (grid->down->state == blank)
		{
			grid = walk(grid, down).first;
			S.push(make_pair(WALK, down));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else if (grid->leftt->state == blank)
		{
			grid = walk(grid, leftt).first;
			S.push(make_pair(WALK, leftt));
			if (grid->state == cheese)
				return grid;
			all_sensor();
		}
		else {
			// Go back.
			auto [command, direction] = S.top();
			S.pop();

			switch (direction)
			{
				case up: change_direction(down); break;
				case rightt: change_direction(leftt); break;
				case down: change_direction(up); break;
				case leftt: change_direction(rightt); break;
			}
			grid = walk(grid, player.state).first;
			if (grid->state == cheese)
				return grid;
		}
	}
	// debug(grid->x, grid->y);

	return grid;
}

list<position> possible_cheese;

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
	position cheese_q;
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
	for (int x = orig.x + distance, y = orig.y; ;--x, ++y)
	{
		possible_cheese.push_back({.x = x * (cheese_q.x ? 1 : -1), .y = y * (cheese_q.y ? 1 : -1)});
		if (x == orig.x)
			break;
	}

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
	for (auto [x, y] : possible_cheese)
		bias.x -= x,
		bias.y -= y;
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

	// X is negative or positive.
	} else if (bias.x != 0) {
		// go right
		if (bias.x < 0)
		{
			if (block->rightt->state == blank)
			{
				change_direction(rightt);
				return true;
			// go up
			} else if (bias.y < 0) {
				if (block->up->state == blank)
				{
					change_direction(up);
					return true;
				} else if (block->down->state == blank)
				{
					change_direction(down);
					return true;
				} else if (block->leftt->state == blank)
				{
					change_direction(leftt);
					return true;
				}
			// go down
			} else {
				if (block->down->state == blank)
				{
					change_direction(down);
					return true;
				} else if (block->up->state == blank)
				{
					change_direction(up);
					return true;
				} else if (block->leftt->state == blank)
				{
					change_direction(leftt);
					return true;
				}
			}
		// go left
		} else {
			if (block->leftt->state == blank)
			{
				change_direction(leftt);
				return true;
			// go up
			} else if (bias.y < 0) {
				if (block->up->state == blank)
				{
					change_direction(up);
					return true;
				} else if (block->down->state == blank)
				{
					change_direction(down);
					return true;
				} else if (block->rightt->state == blank)
				{
					change_direction(rightt);
					return true;
				}
			// go down
			} else {
				if (block->down->state == blank)
				{
					change_direction(down);
					return true;
				} else if (block->up->state == blank)
				{
					change_direction(up);
					return true;
				} else if (block->rightt->state == blank)
				{
					change_direction(rightt);
					return true;
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
				} else if (block->leftt->state == blank)
				{
					change_direction(leftt);
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
				} else if (block->leftt->state == blank)
				{
					change_direction(leftt);
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
	queue<pair<char, entity_state>> Q = C;
	// fprintf(stderr, "C = {\n");
	while (not Q.empty())
	{
		auto pc = Q.front();
		Q.pop();

		string dir;
		switch (pc.second)
		{
			case up: dir = "up"; break;
			case leftt: dir = "left"; break;
			case down: dir = "down"; break;
			case rightt: dir = "right"; break;
		}
		fprintf(stderr, "( %c, %s )\n", pc.first, dir.c_str());
	}
	fprintf(stderr, "}\n");
}

void print_stack(stack<pair<char, entity_state>> &D)
{
	stack<pair<char, entity_state>> BS = D;

	// fprintf(stderr, "S = {\n");
	while (not BS.empty())
	{
		auto pc = BS.top();
		BS.pop();

		string dir;
		switch (pc.second)
		{
			case up: dir = "up"; break;
			case leftt: dir = "left"; break;
			case down: dir = "down"; break;
			case rightt: dir = "right"; break;
		}
		fprintf(stderr, "( %c, %s )\n", pc.first, dir.c_str());
	}
	fprintf(stderr, "}\n");
}

node *misser_hitter(node *block)
{
	int result = 1;
	node *aux;
	while (true)
	{
		// Process, visit.
		block->state = visited;

		bool found_same = false;
		
		// 1. Walk while I can.
		while (true)
		{
			auto pc = walk(block, player.state);
			aux = pc.first;

			fprintf(stderr, "Tried to walk in, I am in block (%d, %d)\n", aux->x, aux->y);

			// If hit, leave.
			if (not pc.second or aux == block)
			{
				block = aux;
				break;
			} else if (aux->x or aux->y) {
				auto f_it = find(begin(positions_passed), prev(end(positions_passed)), make_pair(aux->x, aux->y));
				if (f_it != prev(end(positions_passed)))
				{
					fprintf(stderr, "Found the same position: (%d, %d)\n", aux->x, aux->y);
					block = aux;
					block->state = visited;
					// Save the last dumb walk.
					S.push(make_pair(WALK, player.state));
					// print_stack(S);
					found_same = true;
					break;
				}
			}

			// If we went back to the start, clean the stack.
			if (not aux->x and not aux->y)
			{
				found_same = true;
				block = aux;
				block->state = visited;
				S.push(make_pair(WALK, player.state));
				break;
			}
			else
				// Save all the walks and its directions.
				S.push(make_pair(WALK, player.state));

			// print_stack();

			if (aux->state == cheese)
			{
				// fprintf(stderr, "cheese found: %d, %d\n", aux->x, aux->y);
				return aux;
			}

			block = aux;
			block->state = visited;
			// print_grid(block);
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
			fprintf(stderr, "\tBias: (%d, %d)\n", bias.x, bias.y);
			
			if (bias_direction(block, bias))
				continue;
		}

		// Base case: we need to go back, this way is useless.
		// Algorithm: we go back one by one, sensoring around.
		// TODO: optimise the way back.
		while (not S.empty())
		{
			auto [command, direction] = S.top();
			S.pop();
			// print_stack(S);

			switch (direction)
			{
				case up: direction = down; break;
				case rightt: direction = leftt; break;
				case down: direction = up; break;
				case leftt: direction = rightt; break;
			}
			block = walk(block, direction).first;
			if (block->state == cheese)
				return block;

			// If this was a possible place for a cheese, remove it.
			for (auto it = begin(possible_cheese); it != end(possible_cheese); ++it)
			{
				position pc = *it;
				if (block->x == pc.x and block->y == pc.y)
				{
					possible_cheese.erase(it);
					break;
				}
			}

			// Already sensored.
			// FIXIT: We don't continue...
			if (block->up and block->rightt and block->down and block->leftt and block->up->state != unknown and block->rightt->state != unknown and block->down->state != unknown and block->leftt->state != unknown)
			{
				bias = bias_calculator();
				fprintf(stderr, "\tBias: (%d, %d)\n", bias.x, bias.y);
				if (bias_direction(block, bias))
					break;
				else
					continue;
			}
			else {
				fprintf(stderr, "This block was not sensored? (%d, %d)\n", block->x, block->y);
				if (not block->up) fprintf(stderr, "\tblock->up not existent!\n");
				if (not block->rightt) fprintf(stderr, "\tblock->rightt not existent!\n");
				if (not block->down) fprintf(stderr, "\tblock->down not existent!\n");
				if (not block->leftt) fprintf(stderr, "\tblock->leftt not existent!\n");
			}

			// Sensor around.
			send_command(SENSOR_WALL);
			read_sensor(player.state, block, result);
			// print_grid(block);
			bias = bias_calculator();
			fprintf(stderr, "\tBias: (%d, %d)\n", bias.x, bias.y);
			if (bias_direction(block, bias))
			{
				break;
			}
		}
	}
	return block;
}

pair<char, entity_state> better_walk(entity_state direction, int k, bool reverse)
{
	pair<char, entity_state> b;

	if (reverse)
		switch (direction)
		{
			case up: b.second = down; break;
			case rightt: b.second = leftt; break;
			case down: b.second = up; break;
			case leftt: b.second = rightt; break;
		}
	else
		b.second = direction;

	switch (k)
	{
		case 4:
			b.first = RUN_MAX;
			break;
		case 3:
			b.first = RUN_NORMAL;
			break;
		case 2:
			b.first = RUN_MIN;
			break;
		case 1:
			b.first = WALK;
			break;
		default:
			fprintf(stderr, "better_walk: SHOULD NOT ENTER HERE");
			exit(1);
	}

	return b;
}

void compress_flier ()
{
	entity_state direction;
	int k = 0;

	while (not S.empty())
	{
		auto command = S.top();
		S.pop();

		// First iteration:
		if (not k)
		{
			direction = command.second,
			++k;
			continue;
		}

		// When it is different, we stop.
		// Or when we already have our limit, four walks.
		if (command.second != direction or k == 4)
		{
			C.push(better_walk(direction, k, true));
			F.push(better_walk(direction, k, false));

			// Reset.
			direction = command.second;
			k = 1;

			if (S.empty())
				C.push(better_walk(direction, k, true)),
				F.push(better_walk(direction, k, false));

		} else
		{
			++k;

			if (S.empty())
				C.push(better_walk(direction, k, true)),
				F.push(better_walk(direction, k, false));

		}
	}
}

void fly_back()
{
	int result;
	while (not C.empty())
	{
		auto [command, direction] = C.front();
		C.pop();

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
		}
	}

	fprintf(stderr, "[SOL] The player is at (%d, %d)\n", player.x, player.y);
}

void fly_to_cheese()
{
	int result;
	while (not F.empty())
	{
		auto [command, direction] = F.top();
		F.pop();

		change_direction(direction);
		send_command(command);

		int d;
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
	 	return grid;
		// print_stack();

		// Algorith: detecter.
		// Needs: player to be in two-way node.
		// Purpose: minimise area of where cheese is.
		// Pitfall: Can still be too large, perhaps running it multiple times is better.
		vector<pair<int, int>> B = positions_passed;
		grid = detector(grid);
		grid->state = visited;
		bias_direction(grid, bias_calculator());

		if (grid->state != cheese)
		{
			positions_passed = B;
			B.clear();

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
	compress_flier();
	print_queue();

	// Alogorithm: flier.
	// Objective: run as fast as it can given a path.
	fly_back();

	fly_to_cheese();
	print_queue();

	return grid;
}

#define add_stack(d, n) for (int i = 1; i <= n; ++i) S.emplace(WALK, d)

int main (void)
{
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

	destroy_grid(grid);
}
