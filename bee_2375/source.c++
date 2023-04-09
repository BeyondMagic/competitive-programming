#include <iostream>

using namespace std;

bool solve (int d, int a, int l, int p)
{
  if (d <= a and d <= l and d <= p)
    return true;
  else
    return false;
}

int main ()
{
  int n, a, l, p;
  cin >> n >> a >> l >> p;
  cout << (solve(n, a, l, p) ? 'S' : 'N') << '\n';
}
