#include <stdio.h>

int main() {

  int jogA, Anum2, Anum3;
  int jogB, Bnum2, Bnum3;
  int jogC, Cnum2, Cnum3;

  scanf("%d %d %d\n", &jogA, &Anum2, &Anum3);
  scanf("%d %d %d\n", &jogB, &Bnum2, &Bnum3);
  scanf("%d %d %d\n", &jogC, &Cnum2, &Cnum3);

  int somA = Anum2 + Anum3;
  char camp1;

  if ((somA % 2 == 0 && jogA == 0) || (somA % 2 != 0 && jogB == 1)) {
    camp1 = 'A';
  }

  else

  {
    camp1 = 'B';
  }

  int somB = Bnum2 + Bnum3;
  char camp2;

  if ((somB % 2 == 0 && jogB == 0) || (somB % 2 != 0 && jogB == 1))

  {
    camp2 = 'C';
  }

  else

  {
    camp2 = 'D';
  }

  int somC = Cnum2 + Cnum3;
  char camp;

  if ((somC % 2 == 0 && jogC == 0) || (somC % 2 != 0 && jogC == 1))

  {
    camp = camp1;
  }

  else

  {
    camp = camp2;
  }

  printf("%c\n", camp);

  return 0;
}
