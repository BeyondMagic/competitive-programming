#include <stdio.h>
#include <stdbool.h>

bool partida (const int escolha, const int primeiro, const int segundo)
{
  const int resultado = (primeiro + segundo) % 2;

  if ((!resultado && !escolha) || (resultado && escolha))
    return true;
  else
    return false;
}

int main (void)
{
  int e, j1, j2;

  scanf("%d %d %d", &e, &j1, &j2);
  const char v1 = partida(e, j1, j2) ? 'A' : 'B';

  scanf("%d %d %d", &e, &j1, &j2);
  const char v2 = partida(e, j1, j2) ? 'C' : 'D';

  scanf("%d %d %d", &e, &j1, &j2);
  const char v3 = partida(e, j1, j2) ? v1 : v2;

  printf("%c\n", v3);
}
