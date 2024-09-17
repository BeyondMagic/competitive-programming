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

#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

int count = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

struct thread_arg {
	int vezes;
};

void work(int);

void *thread_func(void *arg)
{
	// cast arg to thread_arg
	struct thread_arg *ta = arg;

	for (int i = 0; i < ta->vezes; ++i)
	{
		pthread_mutex_lock(&mut);
		int id = ++count;
		pthread_mutex_unlock(&mut);
		work(id);
	}

	pthread_exit(0);
}
