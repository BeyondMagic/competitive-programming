#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n, m, k;
	cin >> n >> m >> k;
	int grid[n][m];

	// set all grid to 0
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			grid[i][j] = 0;

	// get tasks;
	char l;
	for (size_t i = 0; i < n; ++i) // linha
		for (size_t j = 0; j < m; ++j) // coluna
		{
			cin >> l;
			// consider it in the map
			if (l == '*')
			{
				// take out a bomb
				if (k)
					--k;
				else
				{
					grid[i][j] = -100000; // place bomb
					if (j != 0) ++grid[i][j-1]; // left
					if (j != m - 1) ++grid[i][j+1]; // right
					if (i != 0) // if line above
					{
						++grid[i-1][j]; // above
						if (j != 0) ++grid[i-1][j-1]; // above left
						if (j != m - 1) ++grid[i-1][j+1]; // above right
					}
					if (i != n - 1) // if line bottom
					{
						++grid[i+1][j]; // below
						if (j != 0) ++grid[i+1][j-1]; // below left
						if (j != m - 1) ++grid[i+1][j+1]; // below right
					}
				}
			}
		}
	
	// print out grid
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)
		{
			if (grid[i][j] < 0)

				cout << "* ";
			else
				cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
}
