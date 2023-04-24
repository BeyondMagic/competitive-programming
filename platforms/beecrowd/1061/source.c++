#include <iostream>

using namespace std;

struct Info
{
  int day;
  int hour,
      minute,
      second;
};

auto solve(Info start, Info end)
{
  Info spent{
    end.day - start.day,
    end.hour - start.hour,
    end.minute - start.minute,
    end.second - start.second,
  };

  if (spent.second < 0)
  {
    spent.second += 60;
    spent.minute--;
  }

  if (spent.minute < 0)
  {
    spent.minute += 60;
    spent.hour--;
  }

  if (spent.hour < 0)
  {
    spent.hour += 24;
    spent.day--;
  }

  if (spent.day < 0)
    spent.day = 0;

  return spent;
}

int main ()
{
  string _;
  char __;
  Info a, b;
  cin >> _ >> a.day;
  cin >> a.hour >> __ >> a.minute >> __ >> a.second;
  cin >> _ >> b.day;
  cin >> b.hour >> __ >> b.minute >> __ >> b.second;
  auto result = solve(a, b);
  cout << result.day << " dia(s)\n";
  cout << result.hour << " hora(s)\n";
  cout << result.minute << " minuto(s)\n";
  cout << result.second << " segundo(s)\n";
}
