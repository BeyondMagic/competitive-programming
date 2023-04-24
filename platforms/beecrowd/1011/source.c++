#include <iostream>
#include <iomanip>

using namespace std;

const auto pi = 3.14159;

double solve (double r)
{
  return 4./3. * pi * r * r * r;
}

int main ()
{
  double r;
  cin >> r;
  cout << fixed << setprecision(3);
  cout << "VOLUME = ";
  cout << solve(r);
  cout << '\n';
}
