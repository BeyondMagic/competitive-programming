#include <iostream>

using namespace std;

const auto multiple = 13;

int solve (int min, int max)
{
  int sum = 0;

  if (min > max)
    swap(min, max);

  for (auto i = min; i <= max; i++)
    if (i % multiple)
      sum += i;

  return sum;
}

int main ()
{
  int x, y;
  cin >> x >> y;
  cout << solve(x, y) << '\n';
}
