#include <iostream>

using namespace std;

void solve (size_t a)
{
  size_t sum = 0;
  for (size_t i = 1; i < a; i++)
    if (!(a % i))
      sum += i;

  cout << a << ' ';
  if (sum == a)
    cout << "eh perfeito";
  else
    cout << "nao eh perfeito";
}

int main ()
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
