#include "library.hpp"

using namespace std;

int ans = 0;

vector<string> grid;

int h, w, K;

void dfs (vector<vector<bool>> &mark, int i = 0, int j = 0, int k = 0)
{
	if (i < 0 or i == h or j < 0 or j == w or grid[i][j] == '#')
		return;

	if (mark[i][j])
	{
		//mark[i][j] = false;
		return;
	}

	if (k == K)
	{
		//print << i + 1 << space << j + 1 << endl;
		++ans;
		return;
	}

	mark[i][j] = true;

	//print << "to down from: " << i + 1 << space << j + 1 << endl;
	dfs(mark, i + 1, j, k + 1); // down
	//print << "to right from: " << i + 1 << space << j + 1 << endl;
	dfs(mark, i, j + 1, k + 1); // right
	//print << "to left from: " << i + 1 << space << j + 1 << endl;
	dfs(mark, i - 1, j, k + 1); // left
	//print << "to up from: " << i + 1 << space << j + 1 << endl;
	dfs(mark, i, j - 1, k + 1); // up

	mark[i][j] = false;
}

int main ()
{
	auto [H, W, Kk] = read<int, int, int>();
	h = H;
	w = W;
	K = Kk;

	grid.resize(h);

	for (int i = 0; i < h; ++i)
		grid[i] = read<string>();

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (grid[i][j] == '.')
			{
				//print << "starting a new: " << i + 1 << space << j + 1 << endl;
				vector<vector<bool>> mark(h, vector<bool>(w, false));
				dfs(mark, i, j);
			}
	cout << ans << endl;
}
