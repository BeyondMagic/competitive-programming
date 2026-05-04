#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define MAX 1000000 + 10

int main(void)
{
	int n;
	scanf("%d", &n);
	int m1 = MAX,
		m2 = MAX,
		m3 = MAX;

	for (int i = 0, k, t; i < n; ++i)
	{
		scanf("%d", &k);
		if (k < m1)
		{
			m3 = m2;
			m2 = m1;
			m1 = k;
		} else if (k < m2)
		{
			m3 = m2;
			m2 = k;
		} else if (k < m3)
		{
			m3 = k;
		}
	}

	printf("%d\n%d\n", m2, m3);
}
