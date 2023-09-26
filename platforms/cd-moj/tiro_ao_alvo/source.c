#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

size_t C, T;

/* A recursive binary search function. It returns
	location of x in given array arr[l..r] is present,
	otherwise -1*/
long long search_binary(long long arr[], long long l, long long r, long long x)
{
	if (x > arr[C - 1])
		return 0;

	while (l < r)
	{
		long long m = (l + r) / 2;

		if (arr[m] >= x)
			r = m;
		else
			l = m + 1;
	}
	return (long long)C - r;
}

int main(void)
{
	scanf("%zu %zu", &C, &T);
	long long radius[C];
	for (size_t i = 0; i < C; ++i)
	{
		scanf("%lld", &radius[i]);
		radius[i] = radius[i] * radius[i];
	}

	long long xs[T], ys[T];
	for (size_t i = 0; i < T; ++i)
		scanf("%lld %lld", &xs[i], &ys[i]);

	long long p = 0;
	for (size_t i = 0; i < T; ++i)
		p += search_binary(radius, 0, (long long)(C - 1), xs[i] * xs[i] + ys[i] * ys[i]);
	printf("%lld\n", p);
}
