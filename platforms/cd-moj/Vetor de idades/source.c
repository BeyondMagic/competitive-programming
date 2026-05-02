#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int main(void)
{
	int n,
		s = 0,
		k = 0;
	int m = -1, // max
		p = -1; // pos
	while (scanf("%d", &n) != EOF and n != -1)
	{
		s += n;
		++k;
		if (n > m)
			m = n, p = k;
	}
	if (not k)
		printf("0\n0 0\n");
	else
		printf("%d\n%d %d\n", s / k, m, p - 1);
}
