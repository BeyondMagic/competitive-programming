#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define KEY 13

int main(void)
{
  /* input */
  size_t n;
  scanf("%zu ", &n);

  char c;
  while (scanf("%c", &c) != EOF)
    if (c >= 'A' && c <= 'Z' - KEY)
      putchar(c + KEY);
    else if (c >= 'A' + KEY && c <= 'Z')
      putchar(c - KEY);
    else
      putchar(c);
}
