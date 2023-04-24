#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum RETANGULO {
  ALTURA  = 70,
  LARGURA = 160,
  AREA    = ALTURA * LARGURA,
};

enum JOGADORES {
  NINGUEM = 0,
  EDUARDO = 1,
  DAIANE  = 2,
};


/* calculation */
int solve (int a, int b)
{
  int area;
  /* Rectangle. */
  if (a == b)
    area = a * ALTURA;
  else
    area = ((a + b) * ALTURA) / 2;

  if (area == AREA / 2)
    return NINGUEM;

  else if (area > AREA / 2)
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
