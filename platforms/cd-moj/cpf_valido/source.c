#include "stdio.h"

int main (void)
{
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11,
      dv1, dv2;

  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11);

  {
    dv1 = d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2;
    dv1 %= 11;
    dv1 = 11 - dv1;

    if (dv1 > 9)
      dv1 = 0;
  }

  {
    dv2 = d1 * 11 + d2 * 10 + d3 * 9 + d4 * 8 + d5 * 7 + d6 * 6 + d7 * 5 + d8 * 4 + d9 * 3 + dv1 * 2;
    dv2 %= 11;
    dv2 = 11 - dv2;

    if (dv2 > 9)
      dv2 = 0;
  }

  if (d10 == dv1 && d11 == dv2)
    puts("valido");
  else
    puts("invalido");
}
