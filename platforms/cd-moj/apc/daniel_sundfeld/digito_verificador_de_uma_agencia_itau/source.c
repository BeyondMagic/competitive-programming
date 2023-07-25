#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

int main (void)
{
	int number;
	scanf("%d", &number); // Four-digit number.

	int result = 0;
	{
		{
			int part;

			part = number % 10 * 2;
			result += (part >= 10) ? (part % 10) + 1 : part;
			number /= 10;

			result += number % 10;
			number /= 10;

			part = (number % 10) * 2;
			result += (part >= 10) ? (part % 10) + 1 : part;
			number /= 10;

			result += number % 10;
			number /= 10;
		}

		result %= 10;

		result = 10 - result;
	}

	printf("%hu\n", result);
}
