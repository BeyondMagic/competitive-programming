#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<
#define even(x) (!((x) & 1))
#define odd(x) ((x) & 1)

int main (void)
{
	int a;
	scanf("%d", &a);

	printf("%d\n", a);
}
