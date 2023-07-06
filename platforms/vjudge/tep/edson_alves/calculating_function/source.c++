#include <bits/stdc++.h>

/* https://stackoverflow.com/a/18429250 */
#define INF 0x3f3f3f3f

/* Since the STL-implemented std::endl is not usually what we want:
 * flush and then print out a newline;
 * we just want to print the newline */
//constexpr static auto endl = '\n';
#define endl '\n'

using namespace std;

/* calculation */
long long solve (long long a)
{
  auto result = a - a/2;
  if (a % 2)
    return -1 * result;
  else 
    return result;
}

int main()
{
  /* desynchronize C and C++ io */
  ios::sync_with_stdio(false);

  /* untie cin from cout */
  cin.tie(NULL);

  /* output rules */
  //cout << fixed << setprecision(3);

  /* input */
  long long a;
  cin >> a;

  /* output */
  cout << solve(a) << endl;
}