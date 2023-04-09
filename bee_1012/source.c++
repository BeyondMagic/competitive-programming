#include <iostream>
#include <iomanip>

using namespace std;

enum shapes
{
  TRIANGULO,
  CIRCULO,
  TRAPEZIO,
  QUADRADO,
  RETANGULO
};

const auto pi = 3.14159;

double solve (int shape, double a, double b, double c)
{
  double result = -1;
  switch (shape)
  {
    case TRIANGULO:
      result = a * c / 2.;
    break;
    case CIRCULO:
      result = pi * c * c;
    break;
    case TRAPEZIO:
      result = 1./2. * c * (a + b);
    break;
    case QUADRADO:
      result = b * b;
    break;
    case RETANGULO:
      result = a * b;
    break;
  }
  return result;
}

int main()
{
  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(3);
  cout << "TRIANGULO: " << solve(TRIANGULO, a, b, c) << '\n';
  cout << "CIRCULO: " << solve(CIRCULO, a, b, c) << '\n';
  cout << "TRAPEZIO: " << solve(TRAPEZIO, a, b, c) << '\n';
  cout << "QUADRADO: " << solve(QUADRADO, a, b, c) << '\n';
  cout << "RETANGULO: " << solve(RETANGULO, a, b, c) << '\n';
}
