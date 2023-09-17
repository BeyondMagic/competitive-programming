#include <bits/stdc++.h>

/* https://stackoverflow.com/a/18429250 */
#define INF 0x3f3f3f3f

/* Since the STL-implemented std::endl is not usually what we want:
 * flush and then print out a newline;
 * we just want to print the newline */
//constexpr static auto endl = '\n';
#define endl '\n'

using namespace std;

int main()
{
  /* desynchronize C and C++ io */
  ios::sync_with_stdio(false);

  /* untie cin from cout */
  cin.tie(NULL);

  long long x = 0;

  int n, k;
  cin >> n >> k;

  vector<int> as(n);

  for (int i = 0; i < n; ++i)
    cin >> as[i];

  for (int i = 60; i >= 0; --i)
  {
    auto mask = 1 << i;
    int z = 0, o = 0;

    for (auto a : as)
      a & mask ? ++o : ++z;

    if (z > 0 and (x | mask) <= k)
      x |= mask;

  }

  cout << x << endl;
}
