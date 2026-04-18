#include "library.hpp"

using namespace std;

int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		auto [a, b, n] = read<long long, long long, long long>();
		auto k = 0;
		long long c;

		do {
			c = min(a, b);
			auto d = max(a, b);

			c += d;
			a = c;
			b = d;
			++k;
		}
		while (c <= n);

		cout << k << endl;
	}
}
