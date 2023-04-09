#include <iostream>
#include <iomanip>

using namespace std;

void solve(double a, double b, double c)
{
  if (a + b > c and a + c > b and b + c > a)
    cout << "Perimetro = " << a + b + c;
  else
    cout << "Area = " << (a + b) * c/2.;
}

int main ()
{
  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(1);
  solve(a, b, c);
  cout << '\n';
}
