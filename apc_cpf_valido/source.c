#include "stdio.h"

/* Uma "macro" em C para pegar o último valor do número. */
#define LAST_DIGIT(number) \
  number % 10;             \
  cpf /= 10

int main ()
{
  /* 'size_t' é equivalente a 'unsigned long long int' */
  size_t cpf,
         d1, d2, d3, d4, d5, d6, d7, d8, d9,
         v1, v2,
         fv1, fv2;

  scanf("%zu", &cpf);
  {
    v2 = LAST_DIGIT(cpf);
    v1 = LAST_DIGIT(cpf);

    d9 = LAST_DIGIT(cpf);
    d8 = LAST_DIGIT(cpf);
    d7 = LAST_DIGIT(cpf);
    d6 = LAST_DIGIT(cpf);
    d5 = LAST_DIGIT(cpf);
    d4 = LAST_DIGIT(cpf);
    d3 = LAST_DIGIT(cpf);
    d2 = LAST_DIGIT(cpf);
    d1 = LAST_DIGIT(cpf);
  }

  {
    fv1 = d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2;
    fv1 %= 11;
    fv1 = 11 - fv1;

    if (fv1 > 9)
      fv1 = 0;
  }

  {
    fv2 = d1 * 11 + d2 * 10 + d3 * 9 + d4 * 8 + d5 * 7 + d6 * 6 + d7 * 5 + d8 * 4 + d9 * 3 + fv1 * 2;
    fv2 %= 11;
    fv2 = 11 - fv2;

    if (fv2 > 9)
      fv2 = 0;
  }

  if (v1 == fv1 && v2 == fv2)
    puts("valido");
  else
    puts("invalido");
}
