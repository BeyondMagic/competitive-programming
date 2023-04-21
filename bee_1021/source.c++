#include <iostream>
#include <iomanip>

using namespace std;

constexpr static auto nota_format  = " nota(s) de R$ ";
constexpr static auto moeda_format = " moeda(s) de R$ ";

double notas(double m)
{
  size_t money = (size_t) m;

  cout << money / 100 << nota_format << 100. << '\n';
  money %= 100;
  cout << money / 50 << nota_format << 50. << '\n';
  money %= 50;
  cout << money / 20 << nota_format << 20. << '\n';
  money %= 20;
  cout << money / 10 << nota_format << 10. << '\n';
  money %= 10;
  cout << money / 5 << nota_format << 5. << '\n';
  money %= 5;
  cout << money / 2 << nota_format << 2. << '\n';
  money %= 2;

  return (m - (double) ((size_t) m)) + (double) money;
}

void moedas(double m)
{
  size_t money = (size_t) (m * 100.);

  cout << money / 100 << moeda_format << 1. << '\n';
  money %= 100;
  cout << money / 50 << moeda_format << .5 << '\n';
  money %= 50;
  cout << money / 25 << moeda_format << .25 << '\n';
  money %= 25;
  cout << money / 10 << moeda_format << .1 << '\n';
  money %= 10;
  cout << money / 5 << moeda_format << .05 << '\n';
  money %= 5;
  cout << money / 1 << moeda_format << .01 << '\n';
  money %= 1;
}

void solve(double money)
{
  cout << "NOTAS:" << '\n';
  money = (double) notas(money);
  cout << "MOEDAS:" << '\n';
  moedas(money);
}

int main()
{
  double money;
  cin >> money;
  cout << fixed << setprecision(2);
  solve(money);
}
