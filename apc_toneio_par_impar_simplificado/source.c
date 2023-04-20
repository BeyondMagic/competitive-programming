#include <stdio.h>

int main() {
  int resultado;
  int E, A, B, C, D, J1, J2, vencedor1, vencedor2;
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  scanf("%d", &D);
  scanf("%d", &J1);
  scanf("%d", &J2);

  resultado = J1 + J2;
  if (E == 0 && resultado % 2 == 0) {
    printf("%d\n", A);
  } else if (E == 1 && resultado % 2 != 0) {
    printf("%d\n", B);
  }
  if (E == 0 && resultado % 2 == 0) {
    printf("%d\n", C);
  } else if (E == 1 && resultado % 2 != 0) {
    printf("%d\n", D);
  }

  if (vencedor1 == A && vencedor2 == C) {
    {
      if (E == 0, resultado % 2 == 0) {
        printf("A.\n");
      }
    }
    else if (E == 1, resultado % 2 != 0) {
      printf("C.\n");
    }
  }
