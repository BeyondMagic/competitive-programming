#include "library.hpp"

using namespace std;

int h, w, i, j;
vector<string> grid;
set<pair<int, int>> visited;
string t;

int main ()
{
	cin >> h >> w >> i >> j;
	grid.resize(h);
	for (auto &row : grid)
		cin >> row;
	cin >> t;

	--i; --j;

	int houses = 0;

	for (auto &c : t)
	{
		//print << c << " from = (" << i + 1 << ", " << j + 1 << ") ";

		switch (c)
		{
			case 'U':
				if (i - 1 >= 0 and grid[i - 1][j] != '#')
					--i;
				break;
			case 'D':
				if (i + 1 < h and grid[i + 1][j] != '#')
					++i;
				break;
			case 'L':
				if (j - 1 >= 0 and grid[i][j - 1] != '#')
					--j;
				break;
			case 'R':
				if (j + 1 < w and grid[i][j + 1] != '#')
					++j;
				break;
		}

		if (grid[i][j] == '@' and not visited.contains(make_pair(i, j)))
		{
			//print << "++house ";
			++houses;
			visited.emplace(i, j);
		}


		//print << "to (" << i + 1 << ", " << j + 1 << ")" << endl;
	}

	print << i + 1 << space << j + 1 << space << houses << endl;
}
