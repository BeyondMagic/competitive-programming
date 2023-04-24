#include <iostream>
#include <iomanip>

using namespace std;


double solve (double a)
{
  double average = 0;
  double n = 0;
  while (a >= 0)
  {
    average += a;
    n++;
    cin >> a;
  }
  return average / n;
}

int main ()
{
  double a;
  cin >> a;
  cout << fixed << setprecision(2);
  cout << solve(a) << '\n';
}
