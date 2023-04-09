#include <iostream>
#include <iomanip>

using namespace std;

const auto n = 3.14159;

void solve (double r)
{
  cout << n * r * r;
}

int main ()
{
  double r;
  cin >> r;
  cout << fixed << setprecision(4);
  cout << "A=";
  solve(r);
  cout << '\n';
}
