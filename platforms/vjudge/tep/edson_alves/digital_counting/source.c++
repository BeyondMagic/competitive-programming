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
auto solve (const size_t a)
{
  static map<const char, int> b;
  b['0'] = 0;
  b['1'] = 0;
  b['2'] = 0;
  b['3'] = 0;
  b['4'] = 0;
  b['5'] = 0;
  b['6'] = 0;
  b['7'] = 0;
  b['8'] = 0;
  b['9'] = 0;
  for (size_t i = 1; i <= a; i++)
    for (const auto c : to_string(i))
      ++b[c];
  for (const auto i : b)
  {
    cout << i.second;
    if (i.first != '9')
      cout << ' ';
  }
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
  while (a--)
  {
    size_t b;
    cin >> b;
    solve(b);
    cout << endl;
  }
}
