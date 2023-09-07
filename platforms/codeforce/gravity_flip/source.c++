#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	vector<int> bs(n);
	for (auto &b : bs)
		cin >> b;
	sort(begin(bs), end(bs));
	for (size_t i = 0; i < n; ++i)
		cout << bs[i] << ' ';
	putchar('\n');
}
