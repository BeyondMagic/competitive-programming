#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	vector<size_t> fs(n + 1);
	size_t b;
	for (size_t i = 1; i <= n; ++i)
	{
		cin >> b;
		fs[b] = i;
	}
	for (size_t i = 1; i <= n; ++i)
		cout << fs[i] << (i == n ? endl : ' ');
}
