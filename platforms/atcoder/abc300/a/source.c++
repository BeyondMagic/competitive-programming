#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, a, b] = read<int, int, int>();
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		if (k == a + b)
			return print << i << endl, 0;
	}
}
