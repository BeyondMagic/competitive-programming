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
	int k;
	scanf("%d", &k);
	for (int i = 0; i < n; ++i)
		if (A[i] == k)
		{
			puts("pertence");
			return 0;
		}

	puts("nao pertence");
}
