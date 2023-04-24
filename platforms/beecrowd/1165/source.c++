#include <iostream>
#include <cmath>

using namespace std;

void solve(size_t a)
{
  cout << a << ' ';
  size_t b = (size_t) sqrt(a);
  for (size_t i = 2; i <= b; i++)
    if (!(a % i))
    {
      cout << "nao eh primo";
      return;
    }

  cout << "eh primo";
}

int main()
{
  size_t n;
  cin >> n;
  while (n--)
  {
    size_t a;
    cin >> a;
    solve(a);
    cout << '\n';
  }
}
