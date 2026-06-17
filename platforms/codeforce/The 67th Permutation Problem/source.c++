#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto n = read<int>();
		auto k = n * 3;
		for (auto i = 1, j = k; i <= n; ++i, j -= 2)
			cout << i << space << j - 1 << space << j << (i == n ? endl : space);
	}
}
