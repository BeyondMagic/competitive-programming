#include "library.hpp"

using namespace std;

int h, w;
vector<string> grid;

#define MIN 10
#define MAX 1000 + MIN

int t = -1, l = -1, r = MAX, d = -1;

int main ()
{
	cin >> h >> w;
	grid.resize(h);

	for (auto &row : grid)
		cin >> row;

	for (int i = 0; i <= h; ++i)
		for (int j = 0; j < w; ++j)
		{
			switch (grid[i][j])
			{
				case '#':
					// First black mark (defines top row);
					if (t == -1)
						t = i;
					// Last black mark (defines minimum bottom row):
					else
						d = max(d, i);
					break;

				case '?':
					// Max left defines maximum rectangle size;
					l = max(l, j);

					// Min right defines maximum rectangle size:
					r = min(r, j);

					// Min 
					break;
			}
		}
	
}
