#include "library.hpp"

using namespace std;

int main ()
{
	int n;
	cin >> n;
	map<int, int> g;

	for (int i = 1, a, b; i <= n - 1; ++i)
	{
		cin >> a >> b;
		g[a]++;
		g[b]++;
	}

	for (auto &[v, e] : g)
		if (e == n - 1)
			return cout << "Yes" << endl, 0;

	cout << "No" << endl;
}
