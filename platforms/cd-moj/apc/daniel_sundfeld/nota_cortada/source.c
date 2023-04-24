#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum RETANGULO {
  ALTURA  = 70,
  LARGURA = 160,
  AREA    = ALTURA * LARGURA / 2,
};

enum JOGADORES {
  NINGUEM = 0,
  EDUARDO = 1,
  DAIANE  = 2,
};


/* calculation */
int solve (int b, int t)
{
  int area;
  /* Rectangle. */
  if (b == t)
    area = b * ALTURA;
  else
    area = ((b + t) * ALTURA) / 2;

  if (area == AREA)
    return NINGUEM;

  else if (area > AREA)
    return EDUARDO;
  else
    return DAIANE;
}

int main(void)
{
  /* input */
  int a, b;
  scanf("%d\n%d", &a, &b);

  /* output */
  printf("%d\n", solve(a, b));
}
