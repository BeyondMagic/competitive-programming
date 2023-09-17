#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN 1
#define MAX 100000
// create grid with default values as zero.
bool rows[MAX + MIN], cols[MAX + MIN];

void solve (size_t n, size_t m)
{
	// int (*name)[n] = new int[n][n];
	// std::memset(name, 0, sizeof(int) * n * n); //row major contiguous memory
	// name[0][0] = 1; //first element
	// name[n-1][n-1] = 1; //last element
	// delete[] name;

	// FIXIT: Muita dor com vector<bool> e principalmente com vector<vector<bool que eu não desejo a ninguém.
	// vector<vector<bool>> grid(n);
	// grid.resize(n);

	for (size_t i = 0; i < n; ++i)
		rows[i] = cols[i] = false;

	while (m--)
	{
		int x, // row y; // column
		scanf("%d %d", &x, &y);

		// transforms into index
		--x;
		--y;

		// fill all row
		for (size_t i = 0; i < n; ++i)
		{
			rows[i] = true;
			cols[i] = true;
		}
		//fill(begin(grid[x]), end(grid[x]), true);

		// fill all column
		// for (size_t i = 0; i < n; ++i)
		//	grid[i][y] = true;

		// count all trues in the grid
		size_t sum = 0;
		for (size_t i = 0; i < n; ++i)
			if (rows[i] || cols[i])
				++sum;
		printf("%zu", n*n - sum);
		if (m != 0)
			putchar(' ');
	}
	putchar('\n');
}

int main()
{
	/* input */
	size_t n, m;
	scanf("%zu %zu", &n, &m);

	/* output */
	solve(n, m);
}
