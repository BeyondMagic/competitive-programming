#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define even(x) (!((x) & 1))
#define odd(x) ((x) & 1)

int main(void)
{
	int n;
	scanf("%d", &n);
	int A[n];
	for (int i = 0, b = 0; i < n; ++i)
	{
		scanf("%d", &A[i]);
		if (even(A[i]))
		{
			if (not b)
				b = 1;
			else
				putchar(' ');
			printf("%d", i);
		}
	}
	putchar('\n');

	for (int i = 0, b = 0; i < n; ++i)
		if (odd(A[i]))
		{
			if (not b)
				b = 1;
			else
				putchar(' ');
			printf("%d", i);
		}
	putchar('\n');
}
