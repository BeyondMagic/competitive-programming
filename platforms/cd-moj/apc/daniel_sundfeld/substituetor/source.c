#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* O \0 no final da string. */
#define MIN 1
#define MAX_FRASE 10000 + MIN
#define MAX_PALAVRA 40 + MIN

int main (void)
{
  char frase[MAX_FRASE];
  fgets(frase, MAX_FRASE, stdin);

  char achar[MAX_PALAVRA], trocar[MAX_PALAVRA];
  scanf("%s\n%s", achar, trocar);

  // Ler a frase do inicio ao fim.
  for (int i = 0; frase[i]; ++i)
  {
    int j = 0;

    for (; frase[i+j] && achar[j]; ++j)
      if (frase[i+j] != achar[j])
      {
        j = -1;
        break;
      }

    if (j < 0)
      putchar(frase[i]); // printf("%c", frase[i]);

    else {
      i += j - 1;
      printf("%s", trocar);
    }
  }
}
