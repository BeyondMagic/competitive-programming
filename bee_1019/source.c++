#include <iomanip>
#include <iostream>

using namespace std;

const auto HOURS = 60 * 60 * 1;
const auto MINUTES = 60 * 1;

void solve (int seconds)
{
  auto hours = seconds / HOURS;
  auto minutes = (seconds % HOURS) / MINUTES;
  seconds %= MINUTES;

  cout << hours << ':' << minutes << ':' << seconds;
}

int main (void)
{
  int seconds;
  cin >> seconds;
  solve(seconds);
  cout << '\n';
}
