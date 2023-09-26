#include <stdio.h>
#include <limits.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int distance = INT_MAX, tril = 0;
	for (int j = 1; j <= N; ++j)
	{
		int M;
		scanf("%d", &M);
		int trial[M];
		for (int i = 0; i < M; ++i)
			scanf("%d", &trial[i]);

		// from left to right
		int current = 0;
		for (int i = 1; i < M; ++i)
			if (trial[i] > trial[i - 1])
				current += trial[i] - trial[i - 1];
		if (current < distance)
			distance = current, tril = j;

		// from right to left
		current = 0;
		for (int i = M - 1; i >= 1; --i)
			if (trial[i - 1] > trial[i])
				current += trial[i - 1] - trial[i];
		if (current < distance)
			distance = current, tril = j;
	}
	printf("%d\n", tril);
}
