#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define space ' '
#define endl '\n'
#define odd(a) (a & 1)
#define even(a) (!odd(a))

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
			if (b)
				putchar(space);
			else
				b = 1;
			printf("%d", A[i]);
		}
	}
	putchar(endl);

	for (int i = 0, b = 0; i < n; ++i)
	{
		if (odd(A[i]))
		{
			if (b)
				putchar(space);
			else
				b = 1;
			printf("%d", A[i]);
		}
	}

	putchar(endl);
}
