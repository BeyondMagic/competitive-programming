#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<size_t>();

	auto a = size_t(0);
	while (n)
	{
		if (even(n))
		{
			a += n / 2;
			break;
		}

		size_t k = 2;
		for (; k * k <= n; ++k)
			if (n mod k == 0)
				break;

		if (n mod k)
			k = n;

		// a += n / k;
		// n = n mod k;
		n -= k;
		++a;
	}

	cout << a << endl;
}
