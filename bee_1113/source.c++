#include <iostream>

using namespace std;

void solve (int a, int b)
{
  cout << (a > b ? "Decrescente" : "Crescente");
}

int main()
{
  int a, b;
  cin >> a >> b;
  while (a != b)
  {
    solve(a, b);
    cout << '\n';
    cin >> a >> b;
  }
}
