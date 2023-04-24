#include <iostream>

using namespace std;

char solve (int d, int a, int l, int p)
{
  if (d <= a and d <= l and d <= p)
    return 'S';
  else
    return 'N';
}

int main ()
{
  int n, a, l, p;
  cin >> n >> a >> l >> p;
  cout << solve(n, a, l, p) << '\n';
}
