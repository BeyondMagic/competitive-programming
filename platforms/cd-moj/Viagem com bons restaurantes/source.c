#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int main(void)
{
	int d = 1;

	int N;
	while (scanf("%d", &N) != EOF)
	{
		int R = -1, M = -1, r, m;
		printf("Dia %d\n", d++);

		while (N--)
		{
			scanf("%d %d", &r, &m);
			if ((m > M) or (m == M and r < R))
				R = r, M = m;
		}
		printf("%d\n\n", R);
	}
}
