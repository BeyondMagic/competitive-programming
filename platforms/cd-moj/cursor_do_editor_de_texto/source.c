#include <stdio.h>

#define MAX 1000 + 1

size_t str_len(const char *str)
{
	size_t s = 0;
	while (str[s++]);
	return s - 1;
}

int main (void)
{
	size_t l;
	scanf("%zu\n", &l);
	char linhas[l][MAX];
	for (size_t i = 0; i < l; ++i)
		scanf(" %[^\n]s", linhas[i]);

	size_t i, j;
	scanf("%zu %zu\n", &i, &j);
	--i;
	--j;

	const size_t j_max = j;
	
	char c;
	while (scanf("%c\n", &c) != EOF)
	{
		if (c == 'j' && i != l - 1)
			++i;
		else if (c == 'k' && i)
			--i;

		const size_t s = str_len(linhas[i]) - 1;
		if (j > s)
			j = s;
		else if (j < s)
			j = j_max;

		printf("%zu %zu %c\n", i + 1, j + 1, linhas[i][j]);
	}

}
