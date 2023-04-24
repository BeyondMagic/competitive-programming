#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double solve(double x1, double y1, double x2, double y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << fixed << setprecision(4);
  cout << solve(a, b, c, d) << '\n';
}
