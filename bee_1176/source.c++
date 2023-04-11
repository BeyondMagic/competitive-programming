#include <iostream>
#include <array>
#include <map>

using namespace std;

#define size_lt unsigned long long

size_lt fibonacci (size_lt n)
{
  static map<size_lt, size_lt> cache{{0, 0}, {1, 1}};

  auto found = cache.find(n);
  if (found != end(cache))
    return found->second;

  cache[n] = fibonacci(n - 1) + fibonacci(n - 2);

  return cache[n];
}

inline auto solve (size_lt n)
{
    return fibonacci(n);
}

int main ()
{
    size_t n;
    cin >> n;
    while (n--)
    {
        size_lt a;
        cin >> a;
        cout << "Fib(" << a << ") = " << solve(a) << '\n';
    }   
}