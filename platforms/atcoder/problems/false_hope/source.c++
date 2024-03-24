#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<pair<int, int>> movements = {
	{ 0, -1 }, // down
	{ 0, 1 }, // up

	{ -1, 0 }, // left
	{ 1, 0 }, // right

	{ 1, 1 }, // right up (diagonal)
	{ 1, -1 }, // right down (diagonal)
	{ -1, 1 }, // left up (diagonal)
	{ -1, -1 }, // left down (diagonal)
};

int main()
{
	cout << fixed << setprecision(12);


	int grid[4][4];
	for (size_t i = 1; i <= 3; ++i)
		for (size_t j = 1; j <= 3; ++j)
			cin >> grid[i][j];

	size_t d = 0;
	for (size_t i = 1; i <= 3; ++i)
		for (size_t j = 1; j <= 3; ++j)
		{
			bool dis = false;
			// right movement
			if (j == 1)
			{
				size_t c = 1;
				int l = grid[i][1];
				if (grid[i][2] == l)
					++c;
				if (grid[i][3] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// left movement
			if (j == 3)
			{
				size_t c = 1;
				int l = grid[i][3];
				if (grid[i][2] == l)
					++c;
				if (grid[i][1] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// down movement
			if (i == 1)
			{
				size_t c = 1;
				int l = grid[1][j];
				if (grid[2][j] == l)
					++c;
				else
					l = grid[2][j];
				if (grid[3][j] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// up movement
			if (i == 3)
			{
				size_t c = 1;
				int l = grid[3][j];
				if (grid[2][j] == l)
					++c;
				if (grid[1][j] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// diagonal down right
			if (i == 1 and j == 1)
			{
				size_t c = 1;
				int l = grid[1][1];
				if (grid[2][2] == l)
					++c;
				if (grid[3][3] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// diagonal down left
			if (i == 1 and j == 3)
			{
				size_t c = 1;
				int l = grid[1][3];
				if (grid[2][2] == l)
					++c;
				if (grid[3][1] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// diagonal up right
			if (i == 3 and j == 1)
			{
				size_t c = 1;
				int l = grid[3][1];
				if (grid[2][2] == l)
					++c;
				if (grid[1][3] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// diagonal up left
			if (i == 3 and j == 3)
			{
				size_t c = 1;
				int l = grid[3][3];
				if (grid[2][2] == l)
					++c;
				if (grid[1][1] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// middle horizontal left and right
			if (j == 2)
			{
				size_t c = 1;
				int l = grid[i][2];
				if (grid[i][1] == l)
					++c;
				if (grid[i][3] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			// middle vertical up and down
			if (i == 2)
			{
				size_t c = 1;
				int l = grid[2][j];
				if (grid[1][j] == l)
					++c;
				if (grid[3][j] == l)
					++c;
				if (c == 2)
					dis = true;
			}

			if (dis)
			{
				cout << "disappointed at i = " << i << " and j = " << j << endl;
				++d;
			}
		}

	cout << double(d) / 9.0 << endl;
}
