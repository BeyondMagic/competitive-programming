#include <iostream>
#include <iomanip>

using namespace std;

double solve (double salary)
{
  double result = 0.;
  if (salary <= 2'000.)
    return result;
  else
  {
    //result += salary * 0.00;
    salary -= 2'000.;
  }

  if (salary <= 1'000.)
    return result + salary * 0.08;
  else
  {
    result += 1'000 * 0.08;
    salary -= 1'000.;
  }

  if (salary <= 1'500.)
    return result + salary * 0.18;
  else
  {
    result += 1'500 * 0.18;
    salary -= 1'500.;
  }

  return result + salary * 0.28;
}

int main ()
{
  double a;
  cin >> a;
  auto response = solve(a);
  cout << fixed << setprecision(2);
  if (response == 0.)
    cout << "Isento";
  else
    cout << "R$ " << response;
  cout << '\n';
}
