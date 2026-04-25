#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b and b == c)
		puts("empate");
	else if (a == b)
		puts("C");
	else if (a == c)
		puts("B");
	else
		puts("A");
}
