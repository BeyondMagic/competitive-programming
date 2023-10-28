/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'

#define MARK '#'

size_t h, w;

#define MIN 10
#define MAX 100 + MIN

bool visited[MAX][MAX] = {false};

// size_t depth (vector<string> &grid, long x, long y, long dx, long dy)
// {
// 	size_t xs = 0;
// 	// visited[x][y] = true;
// 
// 	while (x > 0 and y > 0)
// 	{
// 		x += dx;
// 		y += dy;
// 
// 		if (y == w or x == h or visited[x][y])
// 			break;
// 
// 		visited[x][y] = true;
// 
// 		if (grid[x][y] == MARK)
// 			++xs;
// 	}
// 	return xs;
// }
// 
// // WA: should not count/revisit calculated crosses.
// int solve()
// {
// 	cin >> h >> w;
// 	vector<string> grid(h);
// 	for (auto &line : grid)
// 		cin >> line;
// 
// 	vector<size_t> sizes(min(h, w), 0);
// 
// 	for (size_t i = 0; i < h; ++i)
// 	{
// 		// first and last line
// 		if (not i or i + 1 == h)
// 			continue;
// 
// 		for (size_t j = 0; j < w; ++j)
// 		{
// 			if (visited[i][j])
// 				continue;
// 
// 			// first and last column
// 			if (not j or j + 1 == w)
// 				continue;
// 
// 			// is not an #
// 			if (grid[i][j] != MARK)
// 				continue;
// 
// 			// upper left is not an #
// 			if (grid[i - 1][j - 1] != MARK)
// 				continue;
// 
// 			// upper right is not an #
// 			if (grid[i - 1][j + 1] != MARK)
// 				continue;
// 
// 			// lower left is not an #
// 			if (grid[i + 1][j - 1] != MARK)
// 				continue;
// 
// 			// lower right is not an #
// 			if (grid[i + 1][j + 1] != MARK)
// 				continue;
// 
// 			size_t ul = depth(grid, i, j, -1, -1);
// 			size_t ur = depth(grid, i, j, -1, +1);
// 			size_t ll = depth(grid, i, j, +1, -1);
// 			size_t lr = depth(grid, i, j, +1, +1);
// 			size_t min_size = min({ul, ur, ll, lr});
// 			// debug(min_size, ul, ur, ll, lr);
// 
// 			if (not min_size)
// 				continue;
// 
// 			++sizes[min_size - 1];
// 		}
// 	}
// 
// 	// print out all sizes.
// 	for (size_t i = 0; i < min(w, h); ++i)
// 		cout << sizes[i] << (i + 1 == min(w, h) ? endl : ' ');
// 
// 	return 0;
// }

void depth_first_search(vector<string> &grid, long &itt, long x, long y)
{
	if (x < 0 or y < 0 or x == h or y == w)
		return;

	if (grid[x][y] != MARK or visited[x][y])
		return;

	visited[x][y] = true;
	++itt;

	depth_first_search(grid, itt, x + 1, y + 1);
	depth_first_search(grid, itt, x + 1, y - 1);
	depth_first_search(grid, itt, x - 1, y - 1);
	depth_first_search(grid, itt, x - 1, y + 1);
}

int solve ()
{
	cin >> h >> w;
	vector<string> grid(h);
	for (auto &line : grid)
		cin >> line;

	size_t N = min(h, w);

	vector<size_t> sizes(N, 0);
	long itt;
	for (size_t i = 0; i < h; ++i)
		for (size_t j = 0; j < w; ++j)
			if (grid[i][j] == MARK && not visited[i][j])
			{
				itt = 0;
				depth_first_search(grid, itt, i, j),
				++sizes[(itt - 5) / 4];
			}

	// print out all sizes.
	for (size_t i = 0; i < N; ++i)
		cout << sizes[i] << (i + 1 == N ? endl : ' ');

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	// cin >> t;
	while (t--)
		solve();
}
