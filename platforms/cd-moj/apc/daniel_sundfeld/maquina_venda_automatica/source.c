#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
void solve (int money)
{
  printf("%d\n", money / 500);
  money %= 500;
  
  printf("%d\n", money / 100);
  money %= 100;

  printf("%d\n", money / 50);
  money %= 50;

  printf("%d\n", money / 10);
  money %= 10;

  printf("%d\n", money / 5);
  money %= 5;

  printf("%d\n", money / 1);
  money %= 1;
}

int main(void)
{
  /* input */
  int a, b;
  scanf("%d %d", &a, &b);

  /* output */
  solve(b - a);
}
