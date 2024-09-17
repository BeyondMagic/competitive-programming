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
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

#define MAX_CHARS 256 + 10
#define NS_PER_SECOND 1e9

int main (void)
{
	float total = 0.0;

	{
		float final;
		struct timespec start, finish;

		int ret;
		char str[MAX_CHARS],
			 data[MAX_CHARS];
		char *arg[] = { str, data, NULL };

		while (scanf("%s %s", str, data) == 2)
		{
			fflush(stdout);
			// printf("[%s] [%s]\n", str, arg[1]);

			// read start time
			// timespec_get(&start, TIME_UTC);
			clock_gettime(CLOCK_REALTIME, &start);

			// child
			if (not fork())
			{
				execvp(str, arg);
				ret = errno;
				printf("> Erro: %s\n", strerror(ret));
				fclose(stdin);
				exit(ret);
			}

			// parent
			wait(&ret);

			// read closing time
			// timespec_get(&finish, TIME_UTC);
			clock_gettime(CLOCK_REALTIME, &finish);
			final = finish.tv_sec - start.tv_sec + (finish.tv_nsec - start.tv_nsec) / NS_PER_SECOND;
			total += final;

			printf("> Demorou %.1f segundos, retornou %d\n", final, WEXITSTATUS(ret));
		}
	}
	
	// > Demorou 0.0 segundos, retornou 2

	printf(">> O tempo total foi de %.1f segundos\n", total);
}
