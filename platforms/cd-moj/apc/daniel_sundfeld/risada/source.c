#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MIN 1
#define MAX 60 + MIN

int main(void)
{
  /* input */
  char word[MAX];
  scanf("%s", word);

  size_t j = 0;
  char vogals[MAX];
  for (size_t i = 0; word[i]; i++)
    switch (word[i])
    {
      case 'a': case 'e': case 'i': case 'o': case 'u':
        vogals[j++] = word[i];
      break;
    }

  if (!j)
  {
    puts("Valor invalido!");
    return EXIT_SUCCESS;
  }

  for (size_t i = 0, k = j - 1; i < j; ++i, --k)
    if (vogals[i] != vogals[k])
    {
      puts("N");
      return EXIT_SUCCESS;
    }

  puts("S");
}
