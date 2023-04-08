#include <iostream>

using namespace std;

void solve (int a, int b)
{
  auto SOMA = a + b;
  cout << "SOMA = " << SOMA << '\n';
}

int main ()
{
  int a, b;
  cin >> a >> b;
  solve(a, b);
}
