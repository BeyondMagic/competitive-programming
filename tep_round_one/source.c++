#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve (int a, int b)
{
  static vector<int> numbers {1, 2, 3};
  numbers.erase(remove(begin(numbers), end(numbers), a));
  numbers.erase(remove(begin(numbers), end(numbers), b));
  return numbers.front();
}

int main ()
{
  int a, b;
  cin >> a >> b;
  cout << solve(a,b) << '\n';
}
