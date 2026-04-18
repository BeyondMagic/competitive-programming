#include "library.hpp"

using namespace std;

int main ()
{
	// test cases
	auto t = read<size_t>();

	while (t--)
	{
		auto [n, k] = read<size_t, size_t>();

		size_t m = 0;

		// moves: decrease n by 1; or divide n by k if n is divisible by k

		while (n)
		{
			auto m1 = n mod k;
			m += m1;

			n -= m1;
			if (not n)
				break;

			n /= k;
			m++;
		}

		cout << m << endl;
	}
}
