#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MIN 1
#define MAX 1000 + 1

int main(void)
{
  /* input */
  char word[MAX];
  scanf("%s", word);

  size_t i;
  for (i = 0; word[i]; ++i);

  /* output */
  printf("%zu\n", i);
}
