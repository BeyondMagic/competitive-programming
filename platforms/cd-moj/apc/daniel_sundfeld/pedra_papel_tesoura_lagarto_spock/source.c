#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum JOGOS {
  PEDRA   = 0,
  PAPEL   = 1,
  TESOURA = 2,
  LAGARTO = 3,
  SPOCK   = 4,
};

/* calculation */
char solve (int a, int b)
{
  if (a == b)
    return '\0';

  if (  (a == PEDRA   && (b == TESOURA || b == LAGARTO))
     || (a == PAPEL   && (b == SPOCK   || b == PEDRA))
     || (a == TESOURA && (b == PAPEL   || b == LAGARTO))
     || (a == LAGARTO && (b == PAPEL   || b == SPOCK))
     || (a == SPOCK   && (b == TESOURA || b == PEDRA))
     )
    return 'A';

  return 'B';
}

int main (void)
{
  /* input */
  int a, b;
  scanf("%d %d", &a, &b);

  /* output */
  const char result = solve(a, b);
  if (!result)
    puts("empate");
  else
    printf("%c\n", result);
}
