#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int n;

bool equal (const int *A, const int *B)
{
	for (int i = 0; i < n; ++i)
		if (A[i] != B[i])
			return false;
	return true;
}

int main(void)
{
	scanf("%d", &n);
	int A[n], B[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &B[i]);
	puts(equal(A, B) ? "sim" : "nao");
}
