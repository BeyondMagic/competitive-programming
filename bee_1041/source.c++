#include <iostream>

using namespace std;

string solve (double x, double y)
{
  if (x == 0.0)
  {
    if (y == 0.0)
      return "Origem";
    else
      return "Eixo Y";
  }
  else if (y == 0.0)
    return "Eixo X";
  else if (x > 0.0)
  {
    if (y > 0.0)
      return "Q1";
    else
      return "Q4";
  }
  else
  {
    if (y > 0.0)
      return "Q2";
    else
      return "Q3";
  }
}

int main ()
{
  double x, y;
  cin >> x >> y;
  cout << solve(x, y) << '\n';
}
