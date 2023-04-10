#include <iostream>
#include <set>

using namespace std;

size_t solve (set<size_t> a)
{
  size_t n = 0;
  n = *a.begin();

  return n;
}

int main()
{
  set<size_t> a;
  size_t b;
  cin >> b;
  a.emplace(b);
  cout << solve(a) << '\n';
}
