#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, r] = read<int, int>();
	for (auto i = 1; i <= n; ++i)
	{
		auto [d, a] = read<int, int>();
		if (d == 1) { // 1600 and 2799, inclusive
			if (r >= 1600 and r <= 2799)
				r += a;
		} else { // 1200 and 2399
			if (r >= 1200 and r <= 2399)
				r += a;
		}
	}
	print << r << endl;
}
