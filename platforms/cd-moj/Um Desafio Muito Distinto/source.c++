#include "library.hpp"

using namespace std;

inline auto summatory (long long x)
{
	return (x * x + x) / 2;
}

int main()
{
	fast_io();
	auto p = read<int>();
	while (p--)
	{
		auto [l, a, b] = read<long long, long long, long long>();

		auto k = -1ll, L = a, R = b, rh = l + summatory(a - 1);

		while (L <= R)
		{
			k = (L + R) / 2;
			
			if (
				summatory(k - 1) < rh and
				summatory(k) >= rh
			)
				break;
			else if (summatory(k) >= rh)
				R = k - 1;
			else
				L = k + 1;
		}

		cout << k - a + 1 << endl;
	}
}
