#include <iostream>
#include <iomanip>

using namespace std;

enum
{
  CACHORRO_QUENTE = 1,
  X_SALADA,
  X_BACON,
  TORRADA_SIMPLES,
  REFRIGERANTE,
};

double solve (int code, int quantity)
{
  double cost = -1.;
  double many = quantity;
  switch (code)
  {
    case CACHORRO_QUENTE:
      cost = 4. * many;
      break;
    case X_SALADA:
      cost = 4.5 * many;
      break;
    case X_BACON:
      cost = 5. * many;
      break;
    case TORRADA_SIMPLES:
      cost = 2. * many;
      break;
    case REFRIGERANTE:
      cost = 1.5 * many;
      break;
  }
  return cost;
}

int main ()
{
  int x, y;
  cin >> x >> y;
  cout << fixed << setprecision(2);
  cout << "Total: R$ ";
  cout << solve(x, y) << '\n';
}
