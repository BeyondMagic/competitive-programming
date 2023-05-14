#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MIN 1
#define MAX 1000 + MIN

int main(void)
{
  /* input */
  char word[MAX];
  scanf("%s", word);

  /* output */
  size_t i;
  for (i = 0; word[i]; ++i);
  for (int j = (int) i - 1; j >= 0; --j)
    putchar(word[(size_t)j]);
  putchar('\n');
}
