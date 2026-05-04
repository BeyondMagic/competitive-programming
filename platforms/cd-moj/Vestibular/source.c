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
	char A[n + 1], B[n + 1];
	scanf("%s", A);
	scanf("%s", B);
	int k = 0;
	for (int i = 0; i < n; ++i)
		if (A[i] == B[i])
			++k;
	printf("%d\n", k);
}
