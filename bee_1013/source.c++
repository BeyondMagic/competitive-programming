#include <iostream>

using namespace std;

int main ()
{
  int n, maior;
  cin >> maior;
  while (cin >> n)
    if (n > maior)
      maior = n;
  cout << maior << " eh o maior\n";

}
