#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN 1
#define MAX 100000
// create grid with default values as zero.
bool rows[MAX + MIN], cols[MAX + MIN];

void solve (size_t n, size_t m)
{
	// deixar todos os items falsos.
	for (size_t i = 0; i < n; ++i)
		rows[i] = cols[i] = false;

	// run this loop m times
	while (m--)
	{
		size_t r, // row
			   c; // column
		scanf("%zu %zu", &r, &c); // receives as position

		// transforms into index
		--r;
		--c;

		// fill all row and column
		for (size_t i = 0; i < n; ++i)
			cols[c] = rows[r] = true;

		size_t sum = 0; // sum of trues
		// count all trues in the grid
		for (size_t i = 0; i < n; ++i)
			// if true in either i-th column or i-th row add to sum
			for (size_t j = 0; j < n; ++j)
				if (rows[j] && cols[j])
					++sum;

		// print out complement of sum
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
