/**
	*	author: beyondmagic
**/
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <iso646.h>
#include <signal.h>

#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

// procedure: block signals.
void block (int s)
{
	s = 0;
}

int main (void)
{
	signal(SIGUSR1, block);
	signal(SIGUSR2, block);
	pause();
	if (not fork())
		exit(0);
	pause();
	wait(0);
	pause();
}
