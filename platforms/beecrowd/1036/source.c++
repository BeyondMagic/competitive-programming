#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void solve (double a, double b, double c)
{
  auto delta = b*b - 4. * a * c;
  if (a == 0.0 or delta < 0.0)
  {
    cout << "Impossivel calcular";
    return;
  }
  cout << "R1 = " << (-b + sqrt(delta))/(2. * a);
  cout << '\n';
  cout << "R2 = " << (-b - sqrt(delta))/(2. * a);
}

int main()
{
  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(5);
  solve(a, b, c);
  cout << '\n';
}
