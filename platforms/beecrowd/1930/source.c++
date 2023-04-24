#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

auto solve (deque<size_t> a)
{
  auto biggest = a.front();
  a.pop_front();

  size_t sum = 0;

  while (!a.empty())
  {
    sum += a.front();
    a.pop_front();
    biggest--;
  }

  return sum + biggest;
}

int main()
{
  deque<size_t> a;

  size_t b;
  while (cin >> b)
    a.emplace_back(b);

  sort(a.rbegin(), a.rend());
  cout << solve(a) << '\n';
}
