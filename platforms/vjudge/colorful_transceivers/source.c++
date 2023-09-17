#include <iostream>
#include <string_view>

using namespace std;

bool solve (int a, int b, int c, int meters)
{
  if (max(a, c) - min(a, c) <= meters)
    return true;
  if (max(a, b) - min(a, b) <= meters and max(b, c) - min(b, c) <= meters)
    return true;
  return false;
}

int main ()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (solve(a,b,c,d) ? "Yes" : "No") << '\n';
}
