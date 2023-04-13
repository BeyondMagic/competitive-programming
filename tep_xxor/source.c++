#include <iostream>
#include <vector>

using namespace std;

/* Formula for XOR sum: https://stackoverflow.com/a/3932461 */
inline size_t xor_summation (size_t &n)
{
  if (n % 2)
    return (n % 4 == 1) ? 1 : 0;
  else
    return (n % 4 == 0) ? n : n + 1;
}

size_t solve_slow (size_t &k, vector<size_t> &numbers)
{
  size_t max = 0;
  for (size_t second = 0; second <= k; second++)
  {
    size_t total = 0;

    for (size_t i : numbers)
      total = second ^ i;

    if (total > max)
      swap(total, max);
  }
  return max;
}

size_t solve (size_t &k, vector<size_t> &numbers)
{
  size_t max = 0;
  for (size_t i : numbers)
    max ^= i;
  max *= 2;
  return max;
}

int main()
{
  size_t n, k;
  cin >> n >> k;
  vector<size_t> numbers;
  while (n--)
  {
    size_t a;
    cin >> a;
    numbers.emplace_back(a);
  }
  cout << solve(k, numbers) << '\n';
}
