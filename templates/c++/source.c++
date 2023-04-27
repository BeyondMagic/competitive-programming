#include <bits/stdc++.h>

using namespace std;

/* calculation */
int solve (int a)
{
  return a * 2;
}

int main()
{
  /* desynchronize C and C++ io */
  ios::sync_with_stdio(false);
  /* untie cin from cout */
  cin.tie(NULL);

  /* output rules */
  cout << fixed << setprecision(3);

  /* input */
  int a;
  cin >> a;

  /* output */
  cout << solve(a) << '\n';
}
