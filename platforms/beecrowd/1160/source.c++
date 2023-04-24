#include <iostream>

using namespace std;

void solve (double pa, double pb, double g1, double g2)
{
  size_t anos = 0;

  while (pa <= pb and anos < 101)
  {
    pa += (double) (size_t)(pa * g1 / 100);
    pb += (double) (size_t)(pb * g2 / 100);
    anos++;
  }
  if (anos > 100)
    cout << "Mais de 1 seculo.";
  else
    cout << anos << " anos.";
}

int main ()
{
  size_t t;
  cin >> t;
  while (t--)
  {
    double pa, pb, g1, g2;
    cin >> pa >> pb >> g1 >> g2;
    solve(pa, pb, g1, g2);
    cout << '\n';
  }
}
