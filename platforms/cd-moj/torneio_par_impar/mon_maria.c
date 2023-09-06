#include <stdio.h>

int main (void)
{
  int e, j1, j2;
  int resto;

  scanf("%d %d %d", &e, &j1, &j2);
  resto = (j1 + j2) % 2;
  char vencedor1, vencedor2, vencedor3;

  if ((!e && !resto) || (e && resto))
    vencedor1 = 'A';
  else
    vencedor1 = 'B';

  scanf("%d %d %d", &e, &j1, &j2);
  resto = (j1 + j2) % 2;

  if ((!e && !resto) || (e && resto))
    vencedor2 = 'C';
  else
    vencedor2 = 'D';

  scanf("%d %d %d", &e, &j1, &j2);
  resto = (j1 + j2) % 2;

  if ((!e && !resto) || (e && resto))
    vencedor3 = vencedor1;
  else
    vencedor3 = vencedor2;

  printf("%c\n", vencedor3);
}
