#include <stdio.h>

int main (void)
{
  /* Entrada. */
  float p1, p2, p3,
        t,
        l1, l2, l3, l4, l5,
        ml,
        mf;
  scanf("%f %f %f", &p1, &p2, &p3);
  scanf("%f", &t);
  scanf("%f %f %f %f %f", &l1, &l2, &l3, &l4, &l5);

  /* Cálculo. */
  ml = (l1 + l2 + l3 + l4+ l5) / 10;
  mf = (p1 + 2*p2 + 3*p3 + 2*t) / 8 + ml;

  /* Saída. */
  printf("%.2f\n", mf);
}
