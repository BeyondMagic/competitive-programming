#include <stdio.h>

int main (void)
{
	size_t n = 0;
	while (scanf("%*d") != EOF)
		++n;
	printf("%zu\n", n);
}
