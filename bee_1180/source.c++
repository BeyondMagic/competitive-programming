#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &a)
{
  auto e = min_element(a.begin(), a.end());
  cout << "Menor valor: " << *e << '\n';
  cout << "Posicao: " << distance(a.begin(), e) << '\n';
}

int main()
{
  size_t n;
  cin >> n;
  vector<int> a;
  while (n--)
  {
    int x;
    cin >> x;
    a.emplace_back(x);
  }
  solve(a);
}
