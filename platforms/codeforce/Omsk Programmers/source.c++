#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto [a, b, x] = read<int, int, int>();
		if (b < a)
			swap(a, b);
		auto k = b - a;
		int i = 1;
		while (a or b)
		{
			if (b < a)
				swap(a, b);
			b /= x;
			k = min(k, abs(b - a) + i);
			++i;
		}
		cout << k << endl;
	}
}
