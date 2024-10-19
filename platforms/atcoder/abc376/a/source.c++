#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, c] = read<int, int>();

	int total = 0;

	for (int i = 1, last = 1; i <= n; ++i)
	{
		auto k = read<int>();
		if (i == 1 or k - last >= c)
		{
			++total,
			debug(last, k, total);
			last = k;
		}
	}

	print << total << endl;
}
