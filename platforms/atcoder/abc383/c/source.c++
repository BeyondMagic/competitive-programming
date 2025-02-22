#include "library.hpp"

using namespace std;

vector<string> grid;

//  3  4
int h, w, d;

int k = 0;

void dfs (int i, int j, int f = 0)
{
	if (f > d or i < 0 or i > h or j < 0 or j >= w or grid[i][j] == '#')
		return;

	debug(i, j);

	if (grid[i][j] != 'H' and grid[i][j] != ';')
		++k;
	grid[i][j] = ';';

	// up
	dfs(i + 1, j, f + 1);
	// down
	dfs(i - 1, j, f + 1);
	// right
	dfs(i, j + 1, f + 1);
	// left
	dfs(i, j - 1, f + 1);
}

int main ()
{
	cin >> h >> w >> d;
	debug(h, w, d);

	grid.resize(h);
	for (auto &r : grid)
		cin >> r;

	int ans = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (grid[i][j] == 'H')
			{
				k = 0;
				dfs(i, j, 0);

				for (auto &r : grid)
					print << r << endl;

				ans += k;
			}

	print << ans << endl;
}
