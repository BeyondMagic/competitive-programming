#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<long long>();
	while (t--)
	{
		auto [a, b, r] = read<long long, long long, long long>();
		auto k = 0ll;
		auto j = r;
		for (auto i = 1ll; i <= r; ++i)
		{
			while (j * j + i * i > r * r)
				--j;
			k += j;
		}
		cout << 4 * r + 4 * k << endl;
	}
}
