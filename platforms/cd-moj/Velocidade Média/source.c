#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int main(void)
{
	double d, t;
	scanf("%lf", &d);
	scanf("%lf", &t);
	printf("%.2lf\n", d / t);
}
