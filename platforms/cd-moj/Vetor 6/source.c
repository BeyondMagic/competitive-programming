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
	int A[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	for (int i = 0, k; i < n; ++i)
	{
		scanf("%d", &k);
		printf("%d", A[i] + k);
		putchar(i + 1 == n ? '\n' : ' ');
	}
}
