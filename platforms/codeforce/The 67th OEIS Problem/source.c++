#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto n = read<int>();
		auto prev = 1;
		// n -= 2;
		// cout << 1 << space << 3 << (n ? space : endl);
		for (long long a = 1, b = 1, c = 1, i = 1; n; n--)
		{
			// x = (a / b) * c
			// (1 / 1) * 1 -> (1 / 1) * 3 -> (3 / 1) * 5 -> (15 / 3) * 7 ->  (35 / 5) * 9
			// 1 -> 3 -> 15 -> 35 -> 63
			debug(a, b, c);
			auto x = (a / b) * c;
			//cout << x << (n == 1 ? endl : space);
			a = x;
			c += 2;
			b = c - 2;
		}
	}
}
