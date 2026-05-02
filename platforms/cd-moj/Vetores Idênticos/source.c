#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <pthread.h>

#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<
#define even(x) (!((x) & 1))
#define odd(x) ((x) & 1)

int n;

int comp (const void *A, const void *B)
{
	const int a = *(int *)A;
	const int b = *(int *)B;
	return a - b;
}

void* procedure(void* arg)
{
	int *V = (int *)arg;

	qsort(V, n, sizeof(int), comp);

	return NULL;
}

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

	pthread_t t1, t2;
	pthread_create(&t1, NULL, procedure, A);
	pthread_create(&t2, NULL, procedure, B);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	if (equal(A, B))
		puts("Mesmos elementos");
	else
		puts("Diferentes");


}
