#include <iostream>

using namespace std;

size_t solve (size_t n)
{
  size_t in = 0;
  while (n--)
  {
    int a;
    cin >> a;
    if (a >= 10 and a <= 20)
      in++;
  }
  return in;
}

int main ()
{
  size_t n;
  cin >> n;
  size_t in = 0, out = 0;
  in = solve(n);
  out = n - in;
  cout << in << " in\n";
  cout << out << " out\n";
}
