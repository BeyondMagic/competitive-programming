#include <iostream>

using namespace std;

static size_t memoir[46] = { 1, 1 };

size_t solve(size_t n)
{
  if (!n)
    return 0;

  if (!memoir[n-1])
    memoir[n-1] = memoir[n-2] + memoir[n-3];

  return memoir[n-1];
}

int main ()
{
  size_t n;
  cin >> n;
  for (size_t i = 0; i < n; i++)
    cout << solve(i) << ' ';
  cout << '\n';
}
