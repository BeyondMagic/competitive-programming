#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

/*
 * Determines if main stack is growing up or down.
 * Returns: true if up, false if down
 */
bool upordown()
{
	volatile char first, second;
	return &first > &second;
}

int main(void)
{
	printf("The stack is growing %s.", upordown() ? "up" : "down");
}
