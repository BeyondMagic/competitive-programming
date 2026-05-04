#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int m = 1000000 + 10;
	int p = -1;
	for (int i = 0, k; i < n; ++i)
	{
		scanf("%d", &k);
		if (k < m)
		{
			m = k;
			p = i;
		}
	}
	printf("%d\n", p);
}
