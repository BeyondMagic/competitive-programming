#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define MAX 50 + 10

int main(void)
{
	int h, n;
	scanf("%d", &h);
	scanf("%d", &n);

	int k = 0, l = 0, m;
	for (char S[MAX]; n and scanf("%s", S) != EOF; n--, l++)
		for (int i = 0; S[i]; ++i)
		{
			if (S[i] >= 'a' and S[i] <= 'z')
				m = 'a';
			else
				m = 'A';

			k += (S[i] - m + l + i);
		}

	puts(k == h ? "Integridade do arquivo confirmada." : "Alerta: Integridade comprometida!");
}
