#include <iostream>
#include <set>

using namespace std;

void solve (int a, int b, int c)
{
  set numbers{a, b, c};
  for (const auto n : numbers)
    cout << n << '\n';
}

int main ()
{
  int a, b, c;
  cin >> a >> b >> c;
  solve(a, b, c);
  cout << '\n' << a << '\n' << b << '\n' << c << '\n';
}
