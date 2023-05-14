#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define MIN 1
#define MAX 42

int main(void)
{
  /* input */
  size_t n;
  scanf("%zu", &n);

  /* output */
  while (n--)
  {
    char word[MAX + MIN];
    scanf("%s", word);

    char ordered = 'O';

    for (size_t i = 1; word[i]; i++)
      if (tolower(word[i - 1]) >= tolower(word[i]))
      {
        ordered = 'N';
        break;
      }

    printf("%s: %c\n", word, ordered);

  }
}
