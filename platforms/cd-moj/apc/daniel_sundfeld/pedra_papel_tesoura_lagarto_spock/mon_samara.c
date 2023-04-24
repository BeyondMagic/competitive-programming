#include <stdio.h>

int main()
{
  int jogA, jogB;

  scanf("%d %d", &jogA, &jogB);

  if (jogA == jogB) {
    printf("empate\n");
  }
  
  if ((jogA == 0) && (jogB == 0 || jogB == 3)) {
    printf("A\n");
  } else {
    printf("B\n");
  }

  if ((jogA == 1) && (jogB == 4 || jogB == 0)) {
    printf("A\n");
  }
  else if ((jogA == 1) && (jogB == 3)) {
    printf("B\n");
  }

  if (jogA == 2 && (jogB == 3)) {
    printf("A\n");
  }

  else if ((jogA == 2) && (jogB == 4)) {
    printf("B\n");
  }

  if (jogA == 3 && (jogB == 4)) {
    printf("A\n");
  }

  else if ((jogA == 3) && (jogB == 2 || jogB == 0)) {
    printf("B\n");
  }

  if ((jogA == 4) && (jogB == 2 || jogB == 0)) {
    printf("A\n");
  }

  else if ((jogA == 4) && (jogB == 3 || jogB == 1)) {
    printf("B\n");
  }
}
