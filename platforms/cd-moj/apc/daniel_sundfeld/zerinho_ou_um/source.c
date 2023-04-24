#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
char solve (int a, int b, int c)
{
  if (b == c && a != b)
    return 'A';

  else if (a == c && b != a)
    return 'B';

  else if (a == b && c != a)
    return 'C';

  return '\0';
}

int main(void)
{
  /* input */
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  /* output */
  const char resultado = solve(a, b, c);
  if (!resultado)
    puts("empate");
  else
    printf("%c\n", resultado);
}
