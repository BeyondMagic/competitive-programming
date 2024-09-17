/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

using pii = pair<int, int>;

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

enum {
	UNKNOWN = -1,
	LEFT    = 0,
	UP      = 1,
	RIGHT   = 2,
	DOWN    = 3,
};
string DIRECTIONS {{C_LEFT, C_UP, C_RIGHT, C_DOWN, C_UNKNOWN}};

// ------------------------------------------
// Status of the player
// ------------------------------------------
int Direction = UNKNOWN;
pii Player {-1, -1};
pii Mark {-1, -1};
enum {
	PHASE_1,
	PHASE_2,
	PHASE_3
} Phase;

vector<string> grid;
vector<string> grid_original;

inline void print_grid ()
{
	for (auto &line : grid)
		cout << line << endl;
}

inline int mod(int a, int m)
{
    return ((a % m) + m) % m;
}

inline void set_bit(int &n, int k)
{
	n |= 1 << k;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream read("tests/1.in");

	for (string line; getline(read, line); )
	{
		grid.emplace_back(line);
		grid_original.emplace_back(line);

		// Find the player.
		{
			auto pos = line.find_first_of(DIRECTIONS);
			if (pos != string::npos)
			{
				switch (line[pos])
				{
					case C_LEFT: Direction = LEFT; break;
					case C_RIGHT: Direction = RIGHT; break;
					case C_UP: Direction = UP; break;
					case C_DOWN: Direction = DOWN; break;
					default:
						cerr << "No Unknown character should have." << endl;
						exit(1);
						break;
				}
				Player = make_pair(int(grid.size()), int(pos) + 1);
				grid_original[Player.first - 1][Player.second - 1] = START;
			}
		}

		// Find the cross.
		{
			auto pos = line.find(MARK);
			if (pos != string::npos)
				Mark = make_pair(int(grid.size()), int(pos) + 1),
				grid_original[Mark.first - 1][Mark.second - 1] = CHEESE;
		}
	}
	cout << grid.size() << " rows read." << endl;
	cout << grid.front().length() << " columns read." << endl;

	read.close();
	debug(Mark);
	debug(Player);

	int cust = 0;

	for (char c; cin >> c; cin.clear(), print_grid(), cout << flush)
	{
		auto &grid_player = grid[Player.first - 1][Player.second - 1];
		int rcase = 0;
		pii player_backup;

		switch (c)
		{
			case SENSOR_WALL:
				rcase = rcase | *grid[Player.first - 2][Player.second - 1] == BLANK ? 1 : 0; // Up.
				cust += 3;
				break;
			
			case SENSOR_MARK:
				if (Phase == PHASE_3)
					rcase = -1;
				else
					rcase = abs(Mark.first - Player.first) + abs(Mark.second - Player.second);
				cust += 3;
				break;

			case ROTATE_LEFT:
				grid_player = DIRECTIONS[Direction = mod(Direction - 1, 4)];
				rcase = 0;
				break;

			case ROTATE_RIGHT:
				grid_player = DIRECTIONS[Direction = mod(Direction + 1, 4)];
				rcase = 0;
				break;

			case WALK:
				player_backup = Player;
				switch (Direction)
				{
					case LEFT:
						--Player.second;
						break;
					case RIGHT:
						++Player.second;
						break;
					case UP:
						--Player.first;
						break;
					case DOWN:
						++Player.first;
						break;
				}

				switch (grid[Player.first - 1][Player.second - 1])
				{
					case CHEESE:
						rcase = 2;
						grid[player_backup.first - 1][player_backup.second - 1] = grid_original[player_backup.first - 1][player_backup.second - 1];
						grid[Mark.first - 1][Mark.second - 1] = grid_original[Mark.first - 1][Mark.second - 1];
						grid[Player.first - 1][Player.second - 1] = DIRECTIONS[Direction];
						grid_player = BLANK;
						break;
					case BLANK:
						rcase = 0;
						grid[player_backup.first - 1][player_backup.second - 1] = grid_original[player_backup.first - 1][player_backup.second - 1];
						grid[Player.first - 1][Player.second - 1] = DIRECTIONS[Direction];
						grid_player = BLANK;
						grid[Mark.first - 1][Mark.second - 1] = grid_original[Mark.first - 1][Mark.second - 1];
						break;
					default:
						rcase = 1;
						Player = player_backup;
						break;
				}
				break;

			default:
				debug("Invalid command.");
				break;
		}
		cout << rcase << endl;
		debug("Command -> ", c);
	}

	cout << "Custo total: " << cust << endl;
}
