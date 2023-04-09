#include <iostream>
#include <iomanip>

using namespace std;

double solve (double a, double b, double c)
{
  return (2*a + 3*b + c*5) / (2 + 3 + 5);
}

int main ()
{
  double a, b, c;
  cin >> a >> b >> c;
  cout << "MEDIA = " << fixed << setprecision(1) << solve(a, b, c) << '\n';
}
