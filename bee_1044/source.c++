#include <iostream>

using namespace std;

bool solve (int a, int b)
{
  if (b > a)
    return b % a == 0;
  else 
    return a % b == 0;
}

int main ()
{
  int a, b;
  cin >> a >> b;
  cout << (solve(a, b) ? "Sao Multiplos" : "Nao sao Multiplos") << '\n';
}
