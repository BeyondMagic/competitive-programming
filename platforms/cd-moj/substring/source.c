#include <stdio.h>
#include <string.h>

#define NOT_FOUND -1

int start = NOT_FOUND,
	end   = NOT_FOUND;

int i = -1;

size_t sub_size = 0;
const char *sub;

void findsub (char *string)
{
	if (!*string)
		return;

	if (!strncmp(string, sub, (size_t)sub_size))
	{
		if (start == NOT_FOUND)
			start = (int)*i;
		else
			end = (int)*i;

		*i += sub_size - 1;
		string += sub_size - 1;
	}

	++*i;
	findsub(++string, sub, i, sub_size, start, end);
}

#define MIN 10
#define MAX 100 + MIN

int main ()
{
	char sg[MAX],
		 sub[MAX];

	scanf("%s", sg);
	scanf("%*c"); // ler \n
	scanf("%s", sub);

	size_t i = 0;                       // posição
	int start = NOT_FOUND,              // posição do primeiro match
		end   = NOT_FOUND;                // posição do último match
	const size_t sub_len = strlen(sub); // tamanho da substring

	findsub(sg, sub, &i, sub_len, &start, &end);
	// printf("start [%d] and end [%d]\n", start, end);
	// se houver apenas um match (uma substring), imprimir o tamanho da substring, senão normal
	if (start == NOT_FOUND)
		return puts("0"), 0;

	printf("%d\n", end == NOT_FOUND ? (int)sub_len : end + (int)sub_len - start);
}
