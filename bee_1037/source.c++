#include <iostream>

using namespace std;

short unsigned solve (double n)
{
  if (n < 0.)
    return 0;
  if (n <= 25.)
    return 1;
  if (n <= 50.)
    return 2;
  if (n <= 75.)
    return 3;
  if (n <= 100.)
    return 4;
  else
    return 5;
}

int main ()
{
  double a;
  cin >> a;
  switch (solve(a))
  {
    case 0: case 5: cout << "Fora de intervalo"; break;
    case 1: cout << "Intervalo [0,25]"; break;
    case 2: cout << "Intervalo (25,50]"; break;
    case 3: cout << "Intervalo (50,75]"; break;
    case 4: cout << "Intervalo (75,100]"; break;
  }
  cout << '\n';
}
