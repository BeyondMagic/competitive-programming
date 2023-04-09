#include <iostream>

using namespace std;

void solve (double pa, double pb, double g1, double g2)
{
  size_t anos = 0;

  double pa_initial = pa,
         pb_initial = pb;

  while (pb > pa and anos <= 100)
  {
    pa = pa_initial + pa_initial * g1 / 100;
    pb = pb_initial + pb_initial * g2 / 100;
    pa_initial = pa;
    pb_initial = pb;
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
