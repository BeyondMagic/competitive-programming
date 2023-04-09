#include <iostream>
#include <iomanip>

using namespace std;

const auto work = 12.; // km/L

double solve (double time, double speed)
{
  auto distance = time * speed;
  return distance / work;
}

int main ()
{
  double time, speed;
  cin >> time >> speed;
  cout << fixed << setprecision(3);
  cout << solve(time, speed) << '\n';
}
