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
  /* output rules */
  char a;
  string str;

  while (cin >> a)
    if (a == '0' or a == '1')
      str.push_back(a);
    else if (!str.empty())
      str.pop_back();

  cout << str << '\n';
}
