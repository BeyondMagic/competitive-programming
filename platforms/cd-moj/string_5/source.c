#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MIN 1
#define MAX 100 + MIN

int main(void)
{
  /* input */
  char word[MAX];
  size_t o_s = 0;
  while (scanf("%s", word) != EOF)
    for (size_t i = 0; word[i]; ++i)
      if (word[i] == 'o')
        ++o_s;

  /* output */
  printf("%zu\n", o_s);
}
